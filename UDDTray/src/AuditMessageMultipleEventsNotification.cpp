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

#include "AuditMessageMultipleEventsNotification.h"

#include "AlertsWatcher.h"
#include "KNotification.h"
#include "AlertsStatistics.h"

AuditMessageMultipleEventsNotification::AuditMessageMultipleEventsNotification(AuditMessageNotificationSettings* notification_settings):AuditMessageNotification(notification_settings){
  notificationManager = KNotification::instance();
}

AuditMessageMultipleEventsNotification::~AuditMessageMultipleEventsNotification(){
}

bool AuditMessageMultipleEventsNotification::processExtraAttributes(){
  return true;
}

bool AuditMessageMultipleEventsNotification::checkNotification(AuditMessage*){
  return false;
}

void AuditMessageMultipleEventsNotification::showAlertNotification(){
  KNotificationMessageMultipleAlerts* alert_notify = KNotificationMessageMultipleAlerts::instance();
  int alerts_count = AlertsStatistics::instance()->alertsCount;
  if (!alerts_count)
    return;
  setAlertParameters();
  if (!isActive()){
    notificationManager->showMessage(alert_notify);
  }
  else{
    notificationManager->updateMessage(alert_notify);
  }
}

void AuditMessageMultipleEventsNotification::setAlertParameters(){
  QString text;
  text = messageFormat();
  text = text.replace("%alerts_count%", QString::number(AlertsStatistics::instance()->alertsCount));
  text = text.replace("%max_level%", QString::number(AlertsStatistics::instance()->maxLevel));
  KNotificationMessageMultipleAlerts* alert_notify = KNotificationMessageMultipleAlerts::instance();
  alert_notify->setFromMessageNotification(this, text);
}

bool AuditMessageMultipleEventsNotification::isActive(){
  KNotificationMessageMultipleAlerts* alert_notify = KNotificationMessageMultipleAlerts::instance();
  return alert_notify->isActive;
}

QString AuditMessageMultipleEventsNotification::elementName(){
  return "multiple_events";
}

void AuditMessageMultipleEventsNotification::writeExtraAttributes(QXmlStreamWriter*){
}
