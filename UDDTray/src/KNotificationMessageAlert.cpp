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

#include "KNotificationMessageAlert.h"

#include <QPixmap>
#include <QDebug>

#include "MainWindow.h"
#include "KNotification.h"

KNotificationMessageAlert::KNotificationMessageAlert(): KNotificationMessage(){
}

KNotificationMessageAlert::~KNotificationMessageAlert() {
}

void KNotificationMessageAlert::setCaption(QString caption){
  _caption = caption;
}

void KNotificationMessageAlert::setText(QString message){
  _message = message;
}

QString KNotificationMessageAlert::text(){
  return _message;
}

QString KNotificationMessageAlert::title(){
  return _caption;
}

QImage KNotificationMessageAlert::image(){
  return _image;
}

QStringList KNotificationMessageAlert::actions(){
  QStringList action_list;
  action_list.append("View");
  action_list.append("View");
  return action_list;
}

void KNotificationMessageAlert::actionActivated(const QString &action_id){
  if (action_id == "View"){
    MainWindow::instance()->setVisible(true);
  }
}

void KNotificationMessageAlert::setFromMessage(AuditMessage* message){
  setFromMessageNotification(message->messageNotification(), message->formattedMessage());
}

void KNotificationMessageAlert::setFromMessageNotification(AuditMessageNotification* message_notification, QString text){
  setText(text);
  setCaption(message_notification->caption());
  _image = message_notification->image();
}





