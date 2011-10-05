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

#include "MainWindow.h"

#include <QDBusInterface>
#include <QtGui>
#include <QStringList>

#include "AlertsWatcher.h"
#include "ApplicationsParser.h"
#include "NotificationConfigParser.h"
#include "UDDaemonInterface.h"
#include "KNotification.h"
#include "AlertsStatistics.h"
#include "AlertsDepositary.h"
#include "PreferencesDialog.h"
#include "AlertsDepositary.h"
#include "TrayIcon.h"

#include <QtDebug>

MainWindow* MainWindow::_instance = 0;

MainWindow::MainWindow(QWidget* parent) :
  QMainWindow(parent) {
  _instance = this;
  setupUi(this);

  createTrayIcon();
  initAlertsWatcher();
  mainTab->init();
  _visible = false;
}

void MainWindow::initAlertsWatcher(){
  alertsWatcher = AlertsWatcher::instance();
  connect(alertsWatcher, SIGNAL(messageReceived(AuditMessage*)), auditMessagesTE, SLOT(appendMessageST(AuditMessage*)));
  connect(alertsWatcher, SIGNAL(modeChanged(QString, int)), trayIcon, SLOT(setMode(QString, int)));
  connect(alertsWatcher, SIGNAL(messageReceived(AuditMessage*)), alertsListLV, SLOT(alertReceivedST(AuditMessage*)));
  connect(this, SIGNAL(logCleared()), AlertsDepositary::instance(), SLOT(clearLogST()));
  connect(this, SIGNAL(logCleared()), alertsListLV, SLOT(logClearedST()));
  connect(this, SIGNAL(visibleChanged(bool)), AlertsDepositary::instance(), SLOT(visibleChangedST(bool)));
  alertsWatcher->connectToInterface();
}

void MainWindow::createTrayIcon(){
  trayIcon = TrayIcon::instance();
  trayIcon->init();
  trayIcon->show();
}

MainWindow::~MainWindow() {
}

MainWindow* MainWindow::instance(){
  return _instance;
}

void MainWindow::setVisible(bool is_visible){
  QMainWindow::setVisible(is_visible);
  if (is_visible){
    alertsWatcher->closeAllAlerts();
  }
  emit(visibleChanged(is_visible));
}

void MainWindow::closeEvent(QCloseEvent*) {
  if (trayIcon->isVisible())
    hide();
}

void MainWindow::quitST(){
  qApp->quit();
}

void MainWindow::changeVisibleST(){
  _visible = !_visible;
  setVisible(_visible);
}

void MainWindow::clearLogST(){
  emit(logCleared());
}

QString MainWindow::alertsEditorText(){
  return alertsEditorTE->toPlainText();
}

void MainWindow::offPolicyGenerationActions(){
  actionGeneratePolicyEditor->setChecked(false);
  actionGeneratePolicyAll->setChecked(false);
  actionGeneratePolicySys->setChecked(false);
}

void MainWindow::editPreferencesST(){
  PreferencesDialog dialog;
  dialog.exec();
}

void MainWindow::reloadAlertsList(){
  alertsListLV->reloadList();
}

