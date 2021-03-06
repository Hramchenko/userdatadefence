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

#include "AlertSettingsBox.h"

#include <QFileInfo>
#include <QFileDialog>
#include <QtDebug>

#include "AuditMessageNotification.h"

AlertSettingsBox::AlertSettingsBox(QWidget* parent): QGroupBox(parent) {
  setupUi(this);
  notification = 0;
}

AlertSettingsBox::~AlertSettingsBox() {
}

void AlertSettingsBox::loadMessageST(AuditMessageNotification* notification_message){
  notification = notification_message;
  levelSB->setValue(notification->level());
  alertTextTB->setText(notification->messageFormat());
  captionLE->setText(notification->caption());
  imageSelectionBox->loadImageST(notification->imagePath());
}

void AlertSettingsBox::levelChangedST(int level){
  if (!notification)
    return;
  notification->setLevel(level);
}

void AlertSettingsBox::captionChangedST(QString caption){
  if (!notification)
    return;
  notification->setCaption(caption);
}

void AlertSettingsBox::imageFileChangedST(QString file_name){
  QPixmap pixmap(file_name);
  notification->loadPixmap(file_name);
}

void AlertSettingsBox::alertTextChangedST(){
  if (!notification)
    return;
  notification->setMessageFormat(alertTextTB->toPlainText());
}
