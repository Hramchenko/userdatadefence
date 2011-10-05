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

#ifndef NOTIFICATIONMULTIPLEEVENTS_H_
#define NOTIFICATIONMULTIPLEEVENTS_H_

#include "AuditMessageNotification.h"
#include "KNotificationMessageMultipleAlerts.h"

class KNotification;

class AuditMessageMultipleEventsNotification: public AuditMessageNotification{
public:
  AuditMessageMultipleEventsNotification(AuditMessageNotificationSettings* notification_settings);
  virtual ~AuditMessageMultipleEventsNotification();
  bool processExtraAttributes();
  bool checkNotification(AuditMessage* message);
  void showAlertNotification();
  bool isActive();
  QString elementName();
  void writeExtraAttributes(QXmlStreamWriter* xml_writer);

private:
  void setAlertParameters();
public:
  int alertsCount;
  int maxLevel;
private:
  KNotification* notificationManager;
};

#endif /* NOTIFICATIONMULTIPLEEVENTS_H_ */
