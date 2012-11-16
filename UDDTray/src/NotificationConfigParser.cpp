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

#include "NotificationConfigParser.h"

#include "AuditMessageNotificationSettings.h"

NotificationConfigParser::NotificationConfigParser(AuditMessageNotificationSettings* notification_settings) {
  notificationSettings = notification_settings;
}

NotificationConfigParser::~NotificationConfigParser() {
}

XMLFileElement* NotificationConfigParser::newElement(const QString& name, bool& error_flag){
  if (name != "notification_config"){
    error_flag = true;
    return 0;
  }
  return notificationSettings;
}

QString NotificationConfigParser::elementName(){
  return "notification_config";
}

QString NotificationConfigParser::fileComment(){
  return " User Data Defence Notification Config ";
}

void NotificationConfigParser::writeSubElements(QXmlStreamWriter* xml_writer){
  notificationSettings->writeElement(xml_writer);
}
