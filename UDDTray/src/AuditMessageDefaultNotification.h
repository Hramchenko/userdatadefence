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

#ifndef NOTIFICATIONDEFAULTPARAMETERS_H_
#define NOTIFICATIONDEFAULTPARAMETERS_H_

#include <QString>
#include <QImage>

#include "AuditMessageNotification.h"

class AuditMessageDefaultNotification: public AuditMessageNotification{
public:
  AuditMessageDefaultNotification(AuditMessageNotificationSettings* notification_settings);
  virtual ~AuditMessageDefaultNotification();
  bool processExtraAttributes();
  QString elementName();
  void writeExtraAttributes(QXmlStreamWriter* xml_writer);
  bool checkNotification(AuditMessage* message);
  QString formatMessage(AuditMessage* message);
  bool needNotification();
public:
  bool showUnknown;
};

#endif /* NOTIFICATIONDEFAULTPARAMETERS_H_ */
