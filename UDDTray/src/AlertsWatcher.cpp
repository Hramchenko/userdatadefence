/***************************************************************************
 *   Copyright (C) 2011 by Hramchenko                                      *
 *   v.hramchenko@gmail.com                                                *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 ***************************************************************************/


#include "AlertsWatcher.h"

#include <QDBusInterface>
#include <QDBusReply>
#include <QtDebug>
#include <QRegExp>
#include <QTimer>

#include "KNotification.h"
#include "KNotificationMessageAlert.h"
#include "AVCAnalyzer.h"
#include "AuditMessageViewer.h"
#include "AuditMessageNotificationSettings.h"
#include "MainWindow.h"
#include "AuditMessageMultipleEventsNotification.h"
#include "AlertsDepositary.h"
#include "AlertsStatistics.h"
#include "AuditMessageNotificationSettings.h"
#include "AuditMessage.h"
#include "KNotificationMessage.h"
#include "UDDaemonInterface.h"
#include "GlobalSettings.h"

AlertsWatcher* AlertsWatcher::_instance = 0;

AlertsWatcher::AlertsWatcher(): QObject(){
  notificationSettings = AuditMessageNotificationSettings::currentSettings();
  notificationManager = KNotification::instance();
  avcbusInterface = UDDaemonInterface::instance();
  analyzer = new AVCAnalyzer();
  analyzer->setVisitor(this);
  messagesViewer = new AuditMessageViewer();
  loadingOldAlerts = false;
  connectSignals();
}

AlertsWatcher::~AlertsWatcher(){
  delete notificationManager;
  delete analyzer;
  delete messagesViewer;
}

void AlertsWatcher::connectSignals(){
  connect(this, SIGNAL(messageReceived(AuditMessage*)), AlertsDepositary::instance(), SLOT(messageReceivedST(AuditMessage*)));
  connect(this, SIGNAL(messageReceived(AuditMessage*)), AlertsStatistics::instance(), SLOT(messageReceivedST(AuditMessage*)));
  connect(MainWindow::instance(), SIGNAL(logCleared()), this, SLOT(clearLogST()));
}

AlertsWatcher* AlertsWatcher::instance(){
  if (!_instance)
    _instance = new AlertsWatcher();
  return _instance;
}

void AlertsWatcher::clearLogST(){
}

#include <iostream>
using namespace std;
void AlertsWatcher::loadOldAlertsST(){
  if (AlertsDepositary::instance()->needLoadingOldAlerts()){
    loadingOldAlerts = true;
    QString messages;
    messages = avcbusInterface->loadLastAuditMessages(AlertsDepositary::instance()->lastAuditMessage);
    AVCAlert(messages);
    loadingOldAlerts = false;
  }
}

void AlertsWatcher::connectToInterface(){
  int loading_delay = GlobalSettings::instance()->oldMessagesLoadingDelay();
  QTimer::singleShot(loading_delay, this, SLOT(loadOldAlertsST()));
  connect(avcbusInterface, SIGNAL(alertReceived(QString)), this, SLOT(AVCAlert(QString)));
}

void AlertsWatcher::processNewMessage(AuditMessage* message){
  emit(messageReceived(message));
}

void AlertsWatcher::checkIndividualAlerts(){
  if (!showIndividualAlerts)
    return;
  if (notificationManager->queueLength() > 5 || AuditMessageNotificationSettings::currentSettings()->multipleEventsNotification()->isActive()){
    notificationManager->flushQueue();
    showIndividualAlerts = false;
  }
}

void AlertsWatcher::process(AuditMessage*& message){
  processNewMessage(message);
  if (!message->needNotification())
    return;
  checkIndividualAlerts();
  if (showIndividualAlerts){
    showIndividualNotification(message);
  }
}

void AlertsWatcher::showIndividualNotification(AuditMessage* message){
  if (needNotifications()){
    KNotificationMessageAlert* notify = new KNotificationMessageAlert();
    notify->setFromMessage(message);
    notificationManager->showMessage(notify);
  }
}

void AlertsWatcher::AVCAlert(QString text){
  showIndividualAlerts = true;
  analyzer->processMessage(text);
  if (AlertsStatistics::instance()->alertsCount)
    emit(modeChanged("alert", AlertsStatistics::instance()->maxLevel));
  showMultipleNotification();
}

void AlertsWatcher::showMultipleNotification(){
  if (showIndividualAlerts)
    return;
  if (needNotifications())
    AuditMessageNotificationSettings::currentSettings()->multipleEventsNotification()->showAlertNotification();
}

bool AlertsWatcher::needNotifications(){
  return !MainWindow::instance()->isVisible();
}

void AlertsWatcher::closeAllAlerts(){
  AlertsStatistics::instance()->clearST();
}


