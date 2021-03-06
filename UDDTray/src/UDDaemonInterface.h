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

#ifndef UDDAEMONINTERFACE_H_
#define UDDAEMONINTERFACE_H_

#include <QDBusInterface>

class UDDaemonInterface: public QObject{
  Q_OBJECT
public:
  virtual ~UDDaemonInterface();
  static UDDaemonInterface* instance();
  QString loadLastAuditMessages(QString last_message);
  QString loadLastMessages(QString last_message);
  QString loadLastMessagesLines(int lines_count);
protected:
  UDDaemonInterface();
private:
  QString loadLastLines(QString function, QString last_message);
private slots:
  void alertReceivedST(QString message);
signals:
  void alertReceived(QString message);
private:
  static UDDaemonInterface* _instance;
  QDBusInterface* avcbusInterface;
};

#endif /* UDDAEMONINTERFACE_H_ */
