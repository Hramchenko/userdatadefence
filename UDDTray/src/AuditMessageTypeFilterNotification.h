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

#ifndef NOTIFICATIONEVENTS_H_
#define NOTIFICATIONEVENTS_H_

#include "AuditMessageNotification.h"

class AuditMessageTypeFilterNotification: public AuditMessageNotification{
public:
  AuditMessageTypeFilterNotification(AuditMessageNotificationSettings* notification_settings);
  virtual ~AuditMessageTypeFilterNotification();
  bool processExtraAttributes();
  QString elementName();
  void writeExtraAttributes(QXmlStreamWriter* xml_writer);
  bool checkNotification(AuditMessage* message);
public:
  QString type;
};

#endif /* NOTIFICATIONEVENTS_H_ */
