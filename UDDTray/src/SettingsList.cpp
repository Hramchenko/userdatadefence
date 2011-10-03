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

#include "SettingsList.h"

SettingsList::SettingsList(QWidget* parent): QListWidget(parent) {
}

SettingsList::~SettingsList() {
}

void SettingsList::selectFirst(){
  QListWidgetItem* list_item;
  list_item = item(0);
  if (list_item){
    setCurrentRow(0);
  }
  emit(itemActivated(list_item));
}

void SettingsList::changeCurrentText(QString text){
  QListWidgetItem* list_item;
  list_item = currentItem();
  if (list_item){
    list_item->setText(text);
  }
}

