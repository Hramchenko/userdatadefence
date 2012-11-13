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

#ifndef AUDITMESSAGEVIEWER_H_
#define AUDITMESSAGEVIEWER_H_

#include <QMap>
#include <QString>

class AuditMessage;

class AuditMessageViewer {
public:
  AuditMessageViewer();
  virtual ~AuditMessageViewer();
  QString viewMessage(AuditMessage* message);
private:
  void initMessagesFormats();
private:
  QMap<QString, QString> _messagesFormat;
};

#endif /* AUDITMESSAGEVIEWER_H_ */
