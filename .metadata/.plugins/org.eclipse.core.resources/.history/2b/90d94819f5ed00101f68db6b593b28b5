/***************************************************************************
 *   Copyright (C) 2011 by Hramchenko                                      *
 *   hramchenko@bk.ru                                                      *
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

#include "AuditMessageNotification.h"

#include <QtDebug>

#include "AuditMessageNotificationSettings.h"
#include "KNotificationMessage.h"
#include "AuditMessage.h"
#include "KNotificationMessageAlert.h"

AuditMessageNotification::AuditMessageNotification(AuditMessageNotificationSettings* notification_settings) {
  _notificationSettings = notification_settings;
}

AuditMessageNotification::~AuditMessageNotification() {
}

AuditMessageNotificationSettings* AuditMessageNotification::notificationSettings(){
  return _notificationSettings;
}

QString AuditMessageNotification::defaultPixmapFile(){
  return _notificationSettings->defaultNotification()->imagePath();
}

QString AuditMessageNotification::defaultCaption(){
  return _notificationSettings->defaultNotification()->caption();
}

QString AuditMessageNotification::defaultMessageFormat(){
  return _notificationSettings->defaultNotification()->messageFormat();
}

int AuditMessageNotification::defaultLevel(){
  return _notificationSettings->defaultNotification()->level();
}


QString AuditMessageNotification::formatMessage(AuditMessage* message){
  QString result = messageFormat();
  QMapIterator<QString, AuditMessageField*> i(message->fields);
  while (i.hasNext()) {
    i.next();
    result = result.replace("%" + i.key() + "%", i.value()->interpretedValue);
  }
  result = result.replace("%RAW_MESSAGE%", message->rawMessage());
  return result;
}

bool AuditMessageNotification::processAttributes(){
  setLevel(readXMLAttribute("level", QString::number(defaultLevel())).toInt());
  setCaption(readXMLAttribute("caption", defaultCaption()));
  setMessageFormat(readXMLAttribute("message", defaultMessageFormat()));
  QString image_path = readXMLAttribute("image");
  loadPixmap(image_path);
  return processExtraAttributes();
}

XMLFileElement* AuditMessageNotification::newElement(const QString&, bool& error_flag){
  error_flag = true;
  return 0;
}

QString AuditMessageNotification::filterString(){
  return _filterString;
}

void AuditMessageNotification::setFilterString(QString filter){
  _filterString = filter;
}

QPixmap AuditMessageNotification::pixmap(){
  return _pixmap;
}

void AuditMessageNotification::setPixmap(QPixmap pixmap){
  _pixmap = pixmap;
  _icon = QIcon(pixmap);
  _pixmapBytes = KNotificationMessage::pixmapToByteArray(pixmap);
  _imagePath = "";
}

void AuditMessageNotification::loadPixmap(QString file_name){
  QPixmap pixmap;
  if (file_name.isEmpty())
    file_name = defaultPixmapFile();
  pixmap = QPixmap(file_name);
  setPixmap(pixmap);
  _imagePath = file_name;
}

QIcon AuditMessageNotification::icon(){
  return _icon;
}

QByteArray AuditMessageNotification::pixmapBytes(){
  return _pixmapBytes;
}

QString AuditMessageNotification::caption(){
  return _caption;
}

void AuditMessageNotification::setCaption(QString caption){
  _caption = caption;
}


QString AuditMessageNotification::messageFormat(){
  return _messageFormat;
}

void AuditMessageNotification::setMessageFormat(QString format){
  _messageFormat = format;
}


QString AuditMessageNotification::imagePath(){
  return _imagePath;
}

int AuditMessageNotification::level(){
  return _level;
}

void AuditMessageNotification::setLevel(int level){
  _level = level;
}

void AuditMessageNotification::writeAttributes(QXmlStreamWriter* xml_writer){
  writeExtraAttributes(xml_writer);
  xml_writer->writeAttribute("message", messageFormat());
  xml_writer->writeAttribute("image", imagePath());
  xml_writer->writeAttribute("caption", caption());
  xml_writer->writeAttribute("level", QString::number(level()));
}

bool AuditMessageNotification::hasSubElements(){
  return false;
}

bool AuditMessageNotification::needNotification(){
  return true;
}
