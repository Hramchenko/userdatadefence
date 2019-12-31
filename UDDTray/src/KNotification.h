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

#ifndef KNOTIFICATION_H_
#define KNOTIFICATION_H_

#include <QMap>
#include <QByteArray>
#include <QPixmap>
#include <QList>
#include <QTimer>

#include "KNotificationMessage.h"

class QDBusInterface;

class KNotification: QObject{
  Q_OBJECT
public:
  virtual ~KNotification();
  static KNotification* instance();
  void showMessage(KNotificationMessage* message);
  void updateMessage(KNotificationMessage* message);
  int queueLength();
  void flushQueue();
protected:
  KNotification();
public slots:
  void notificationActivated(const uint, const QString &);
  void notificationClosed(const uint, const uint);
private:
  void connectToInterface();
  int sendMessageToDBus(KNotificationMessage* message);
  void createEventArgs(KNotificationMessage* message, QVariantList &args);
  void removeNotificationMessage(int id);
  void clearMessagesDict();
  KNotificationMessage* findNotificationMessage(int id);
  void sendUpdateMessageToDBus(KNotificationMessage* message);
  int newMessageId();
private slots:
  void sendMessagesFromQueueST();
private:
  QMap<int, KNotificationMessage*> messagesDict;
  QList<KNotificationMessage*> messagesQueue;
  QTimer* notificationTimer;
  QDBusInterface* knotifyInterface;
  QString notifyEvent;
  QString notifyApplication;
  int _queueLength;
  int currentMessageId = 0;
  static KNotification* _instance;
};

#endif /* UDDNOTIFICATION_H_ */
