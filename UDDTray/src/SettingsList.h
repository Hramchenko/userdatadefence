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

#ifndef SETTINGLIST_H_
#define SETTINGLIST_H_

#include <QListWidget>

class SettingsList: public QListWidget {
  Q_OBJECT
public:
  SettingsList(QWidget* parent);
  virtual ~SettingsList();
public slots:
  void selectFirst();
  void changeCurrentText(QString text);
};

#endif /* SETTINGLIST_H_ */
