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

#include "AlertsStatistics.h"

#include <QtDebug>

#include "AuditMessageNotificationSettings.h"
#include "AlertsWatcher.h"
#include "AlertsDepositary.h"
#include "MainWindow.h"

AlertsStatistics* AlertsStatistics::_instance = 0;


AlertsStatistics::AlertsStatistics() {
  clearST();
}

AlertsStatistics::~AlertsStatistics() {
}

AlertsStatistics* AlertsStatistics::instance(){
  if (!_instance)
    _instance = new AlertsStatistics();
  return _instance;
}

void AlertsStatistics::clearST(){
  alertsCount = 0;
  maxLevel = 0;
}

void AlertsStatistics::messageReceivedST(AuditMessage* message){
  if (MainWindow::instance()->isVisible())
    return;
  AuditMessageNotification* notification_message;
  notification_message = AuditMessageNotificationSettings::currentSettings()->searchNotificationMessage(message);
  if (notification_message){
    int level = notification_message->level();
    alertsCount++;
    if (level > maxLevel)
      maxLevel = level;
    if (AlertsWatcher::instance()->loadingOldAlerts){
      if (message->rawMessage() == AlertsDepositary::instance()->lastAlert){
        clearST();
      }
    }
  }
}
