/***************************************************************************
 *   Copyright (C) 2011 by Hramchenko                                      *
 *   v.hramchenko@gmail.com                                                *
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

#ifndef NOTIFICATIONMESSAGESLIST_H_
#define NOTIFICATIONMESSAGESLIST_H_

#include "ui_notificationmessageslist.h"

#include <QList>
#include "AuditMessageNotification.h"

class NotificationMessagesList: public QWidget, Ui::NotificationMessagesList {
  Q_OBJECT
public:
  NotificationMessagesList(QWidget* parent = 0);
  virtual ~NotificationMessagesList();
  void loadMessagesList(QList<AuditMessageNotification*>& list);
public slots:
  void itemActivatedST(QListWidgetItem* item);
  void messageFilterChangedST(QString filter);
  void appendItemST();
  void deleteItemST();
  void notificationAppendedST(AuditMessageNotification* message);
private:
  void addItem(AuditMessageNotification* message);
signals:
  void messageSelected(AuditMessageNotification* message);
  void messageFilterSelected(QString filter);
  void needNewMessageNotification();
  void messageNotificationDeleted(AuditMessageNotification* message);
private:
  AuditMessageNotification* currentMessage;
};

#endif /* NOTIFICATIONMESSAGESLIST_H_ */
