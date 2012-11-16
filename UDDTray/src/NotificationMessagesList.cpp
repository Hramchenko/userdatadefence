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

#include "NotificationMessagesList.h"

#include "NotificationMessagesListItem.h"

#include <QtDebug>


NotificationMessagesList::NotificationMessagesList(QWidget* parent): QWidget(parent){
  setupUi(this);
  currentMessage = 0;
}

NotificationMessagesList::~NotificationMessagesList() {
}

void NotificationMessagesList::loadMessagesList(QList<AuditMessageNotification*>& list){
  AuditMessageNotification* message;
  QListIterator<AuditMessageNotification*> iter(list);
  while (iter.hasNext()){
    message = iter.next();
    addItem(message);
  }
  typeAlertsListLW->selectFirst();
}

void NotificationMessagesList::addItem(AuditMessageNotification* message){
  NotificationMessagesListItem* item = new NotificationMessagesListItem();
  item->setText(message->filterString());
  item->setMessageNotification(message);
  typeAlertsListLW->addItem(item);
}


void NotificationMessagesList::itemActivatedST(QListWidgetItem* item){
  NotificationMessagesListItem* list_item = (NotificationMessagesListItem*)item;
  currentMessage = list_item->messageNotification();
  emit(messageSelected(currentMessage));
  emit(messageFilterSelected(currentMessage->filterString()));
}

void NotificationMessagesList::messageFilterChangedST(QString filter){
  if (!currentMessage)
    return;
  currentMessage->setFilterString(filter);
  typeAlertsListLW->changeCurrentText(filter);
}


void NotificationMessagesList::appendItemST(){
  emit(needNewMessageNotification());
}

void NotificationMessagesList::notificationAppendedST(AuditMessageNotification* message){
  message->setFilterString("<new>");
  addItem(message);
}

void NotificationMessagesList::deleteItemST(){
  NotificationMessagesListItem* list_item = (NotificationMessagesListItem*)typeAlertsListLW->currentItem();
  emit(messageNotificationDeleted(list_item->messageNotification()));
  qDeleteAll(typeAlertsListLW->selectedItems());
  typeAlertsListLW->selectFirst();
}
