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

#ifndef NOTIFICATIONEVENTSPATTERN_H_
#define NOTIFICATIONEVENTSPATTERN_H_

#include <QRegExp>

#include "AuditMessageNotification.h"

class AuditMessageRegExpFilterNotification: public AuditMessageNotification{
public:
  AuditMessageRegExpFilterNotification(AuditMessageNotificationSettings* notification_settings);
  virtual ~AuditMessageRegExpFilterNotification();
  bool processExtraAttributes();
  QString elementName();
  void writeExtraAttributes(QXmlStreamWriter* xml_writer);
  bool checkNotification(AuditMessage* message);
  void setFilterString(QString filter);
public:
  QRegExp _regExpr;
  int level;
};

#endif /* NOTIFICATIONEVENTSPATTERN_H_ */
