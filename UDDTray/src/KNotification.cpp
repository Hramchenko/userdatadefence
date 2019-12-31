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
#include "KNotification.h"
#include "FreedesktopImageHint.h"

#include <QDBusInterface>
#include <QBuffer>
#include <QDBusReply>
#include <QObject>
#include <QtDebug>
#include <QImage>
#include <QVariant>
#include <QStringLiteral>
#include <QMap>
#include <iostream>
using namespace  std;

KNotification* KNotification::_instance = 0;

KNotification::KNotification(): QObject(){
  connectToInterface();
  notifyEvent = "alert";
  notifyApplication = "UDDTray";
  _queueLength = 0;
  notificationTimer = new QTimer();
  connect(notificationTimer, SIGNAL(timeout()), this, SLOT(sendMessagesFromQueueST()));
}

KNotification::~KNotification() {
  clearMessagesDict();
  delete knotifyInterface;
  delete notificationTimer;
}

KNotification* KNotification::instance(){
  if (!_instance)
    _instance = new KNotification();
  return _instance;
}

void KNotification::clearMessagesDict(){
  QMapIterator<int, KNotificationMessage*> iter(messagesDict);
  while (iter.hasNext()){
    iter.next();
    delete iter.value();
  }
  messagesDict.clear();
}

void KNotification::connectToInterface(){
  knotifyInterface = new QDBusInterface("org.freedesktop.Notifications", "/org/freedesktop/Notifications", "org.freedesktop.Notifications");
  connect(knotifyInterface, SIGNAL(ActionInvoked(const uint, const QString&)), this, SLOT(notificationActivated(const uint, const QString&)));
  connect(knotifyInterface, SIGNAL(NotificationClosed(const uint, const uint)), this, SLOT(notificationClosed(const uint, const uint)));
}

void KNotification::notificationActivated(const uint id, const QString& action){
  KNotificationMessage* message;
  message = findNotificationMessage(id);
  if (message){
    message->actionActivated(action);
    removeNotificationMessage(id);
  }
}

void KNotification::notificationClosed(const uint id, const uint){
  removeNotificationMessage(id);
}

void KNotification::removeNotificationMessage(int id){
  KNotificationMessage* message;
  message = findNotificationMessage(id);
  if (message){
    message->notificationClosed();
    if (message->needAutoDeletion()){
      delete message;
    }
    messagesDict.remove(id);
  }
}

void KNotification::updateMessage(KNotificationMessage* message){
  if (messagesDict.contains(message->messageId))
  {
    sendUpdateMessageToDBus(message);
  }
  else
  {
    showMessage(message);
  }
}

void KNotification::sendUpdateMessageToDBus(KNotificationMessage* message){
  QList<QVariant> message_args;
  createEventArgs(message, message_args);
  knotifyInterface->callWithArgumentList(QDBus::AutoDetect, "Notify", message_args);
  message->notificationShown();
}

int KNotification::newMessageId()
{
  currentMessageId += 1;
  if (currentMessageId > 100000)
  {
    currentMessageId = 0;
  }
  return currentMessageId;
}

KNotificationMessage* KNotification::findNotificationMessage(int id){
  KNotificationMessage* result = 0;
  if (messagesDict.contains(id)){
    result = messagesDict[id];
  }
  return result;
}

int KNotification::sendMessageToDBus(KNotificationMessage* message){
  message->notificationShown();
  message->messageId = newMessageId();
  QList<QVariant> message_args;
  createEventArgs(message, message_args);
  knotifyInterface->callWithArgumentList(QDBus::AutoDetect, "Notify", message_args);
  return message->messageId;
}

void KNotification::createEventArgs(KNotificationMessage* message, QVariantList &args){
  args.clear();
  args.clear();
  args << QString("UDD");
  args << static_cast<uint>(message->messageId);
  args << QVariant("");
  args << QString(message->title());
  args << QString(message->text());
  args << message->actions();
  QVariantMap hints;
  QImage img = message->image();
  if (img.width() != 0)
  {
    FreedesktopImageHint image(img);
    hints.insert(QStringLiteral("image_data"), QVariant::fromValue(image));
  }
  args << hints;
  args << message->timeout();
}

void KNotification::showMessage(KNotificationMessage* message){
  messagesQueue.push_back(message);
  if (message->needQueue()){
    notificationTimer->start(700);
    _queueLength++;
  }
  else{
    int message_id;
    message_id = sendMessageToDBus(message);
    messagesDict[message_id] = message;
  }
}

void KNotification::sendMessagesFromQueueST(){
  KNotificationMessage* message = messagesQueue.takeFirst();
  int message_id;
  message_id = sendMessageToDBus(message);
  messagesDict[message_id] = message;
  if (messagesQueue.isEmpty())
    notificationTimer->stop();
  _queueLength--;
}

int KNotification::queueLength(){
  return messagesDict.count() + _queueLength;
}

void KNotification::flushQueue(){
  notificationTimer->stop();
  _queueLength = 0;
  KNotificationMessage* message;
  while (!messagesQueue.isEmpty()){
    message = messagesQueue.takeFirst();
    if (message->needAutoDeletion())
      delete message;
  }
}

