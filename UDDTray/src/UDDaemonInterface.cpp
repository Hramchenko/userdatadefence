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

#include "UDDaemonInterface.h"

#include <QDBusReply>

#include <QtDebug>

UDDaemonInterface* UDDaemonInterface::_instance = 0;

UDDaemonInterface::UDDaemonInterface() {
  avcbusInterface = new QDBusInterface("net.sourceforge.userdatadefence.avcbus", "/AVCBus", "net.sourceforge.userdatadefence.avcbus", QDBusConnection::systemBus());
  connect(avcbusInterface, SIGNAL(messageReceived(QString)), this, SLOT(alertReceivedST(QString)));
}

UDDaemonInterface::~UDDaemonInterface() {
}

UDDaemonInterface* UDDaemonInterface::instance(){
  if (!_instance)
    _instance = new UDDaemonInterface();
  return _instance;
}

QString UDDaemonInterface::loadLastLines(QString function, QString last_message){
  QList<QVariant> message_args;
  message_args.append(last_message);
  QDBusReply<QString> reply;
  reply = avcbusInterface->callWithArgumentList(QDBus::AutoDetect, function, message_args);
  return reply.value();
}

QString UDDaemonInterface::loadLastAuditMessages(QString last_message){
  QString result;
  result = loadLastLines("getAuditMessages", last_message);
  return result;
}

QString UDDaemonInterface::loadLastMessages(QString last_message){
  QString result;
  result = loadLastLines("getMessages", last_message);
  return result;
}

QString UDDaemonInterface::loadLastMessagesLines(int lines_count){
  QList<QVariant> message_args;
  message_args.append(QVariant(lines_count));
  QDBusReply<QString> reply;
  reply = avcbusInterface->callWithArgumentList(QDBus::AutoDetect, "getLastMessagesLines", message_args);
  return reply.value();
}

void UDDaemonInterface::alertReceivedST(QString message){
  emit(alertReceived(message));
}

