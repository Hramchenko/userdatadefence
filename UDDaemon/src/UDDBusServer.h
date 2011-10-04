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

#ifndef UDDBUSSERVER_H_
#define UDDBUSSERVER_H_

#include <QtCore>
#include <QtDBus>
#include <QMap>
#include <QList>

#define SERVICE_NAME "net.sourceforge.userdatadefence.avcbus"

class UDDBusServer: public QDBusAbstractAdaptor {
  Q_OBJECT
  Q_CLASSINFO("D-Bus Interface", "net.sourceforge.userdatadefence.avcbus")
public:
  UDDBusServer(QObject *application);
  virtual ~UDDBusServer();
public slots:
  void AVCMessage(const QString &message);
  QString getAuditMessages(QString last_message);
  QString getMessages(QString last_message);
  QString getLastMessagesLines(int lines_count);
signals:
  void messageReceived(QString alert_text);
private:
  QString readFileFromLine(QString file_name, QString line);
private:
  QString lastMessage;
};

#endif /* UDDBUSSERVER_H_ */
