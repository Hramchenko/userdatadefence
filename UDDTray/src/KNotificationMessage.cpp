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

#include "KNotificationMessage.h"

#include <QSystemTrayIcon>
#include <QStringList>
#include <QBuffer>

KNotificationMessage::KNotificationMessage(){
  messageId = 0;
}

KNotificationMessage::~KNotificationMessage(){

}

QByteArray KNotificationMessage::pixmapToByteArray(QPixmap pixmap){
  QByteArray result;
  QBuffer buffer(&result);
  buffer.open( QIODevice::WriteOnly );
  pixmap.save(&buffer, "PNG");
  return result;
}

QByteArray KNotificationMessage::pixmapBytes(){
  return QByteArray();
}

QString KNotificationMessage::title(){
  return "";
}

QString KNotificationMessage::text(){
  return "";
}

QStringList KNotificationMessage::actions(){
  return QStringList();
}

int KNotificationMessage::timeout(){
  return 5000;
}

void KNotificationMessage::actionActivated(int){
}

void KNotificationMessage::notificationShown(){
}

void KNotificationMessage::notificationClosed(){
}

bool KNotificationMessage::needAutoDeletion(){
  return true;
}

bool KNotificationMessage::needQueue(){
  return true;
}

