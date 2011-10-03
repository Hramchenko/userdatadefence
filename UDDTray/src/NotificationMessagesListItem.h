/***************************************************************************
 *   Copyright (C) 2011 by Hramchenko                                      *
 *   hramchenko@bk.ru                                                      *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 ***************************************************************************/

#ifndef NOTIFICATIONMESSAGESLISTITEM_H_
#define NOTIFICATIONMESSAGESLISTITEM_H_

#include <QListWidgetItem>

class AuditMessageNotification;

class NotificationMessagesListItem: public QListWidgetItem {
public:
  NotificationMessagesListItem(QListWidget* parent = 0);
  virtual ~NotificationMessagesListItem();
  AuditMessageNotification* messageNotification();
  void setMessageNotification(AuditMessageNotification* message_notification);
private:
  AuditMessageNotification* _messageNotification;
};

#endif /* NOTIFICATIONMESSAGESLISTITEM_H_ */
