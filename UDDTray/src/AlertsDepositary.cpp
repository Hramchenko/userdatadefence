/***************************************************************************
 *   Copyright (C) 2011 by Hramchenko                                      *
 *   v.hramchenko@gmail.com                                                *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 ***************************************************************************/

#include "AlertsDepositary.h"

#include <QApplication>
#include <QSettings>
#include <QtDebug>

#include "AuditMessage.h"
#include "UDDaemonInterface.h"
#include "functions.h"

AlertsDepositary* AlertsDepositary::_instance = 0;

AlertsDepositary::AlertsDepositary() {
  loadSettings();
  connect(qApp, SIGNAL(aboutToQuit()), this, SLOT(saveSettingsST()));
}

AlertsDepositary::~AlertsDepositary() {
}

AlertsDepositary* AlertsDepositary::instance(){
  if (!_instance)
    _instance = new AlertsDepositary();
  return _instance;
}

void  AlertsDepositary::loadSettings(){
  QSettings settings;
  lastSystemMessage = settings.value("LastMessage", "").toString();
  lastAlert = settings.value("LastAlert", "").toString();
  currentAlert = lastAlert;
  lastAuditMessage = settings.value("LastLogMessage", "").toString();
}

void AlertsDepositary::saveSettingsST(){
  QSettings settings;
  settings.setValue("LastAlert", currentAlert);
  settings.setValue("LastLogMessage", lastAuditMessage);
  settings.setValue("LastMessage", lastSystemMessage);
}

void AlertsDepositary::visibleChangedST(bool is_visible){
  if (is_visible)
    saveSettingsST();
}

void AlertsDepositary::messageReceivedST(AuditMessage* message){
  if (message->type != "EOE"){
    currentAlert = message->rawMessage();
    if (lastAuditMessage.isEmpty()){
      lastAuditMessage = currentAlert;
      saveSettingsST();
    }
  }
  log += message->rawMessage() + "\n";
}

void AlertsDepositary::clearLogST(){
  lastAuditMessage = currentAlert;
  lastSystemMessage = UDDaemonInterface::instance()->loadLastMessagesLines(1);
  log = "";
  saveSettingsST();
}

bool AlertsDepositary::needLoadingOldAlerts(){
  return !lastAuditMessage.isEmpty();
}

