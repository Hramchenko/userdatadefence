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

#ifndef APPLICATIONSETTINGSBOX_H_
#define APPLICATIONSETTINGSBOX_H_

#include "ui_applicationsettingsbox.h"

class ApplicationsSettingsParameter;
class ApplicationsMenuItem;

class ApplicationSettingsBox: public QWidget, public Ui::ApplicationSettingsBox {
  Q_OBJECT
public:
  ApplicationSettingsBox(QWidget* parent);
  virtual ~ApplicationSettingsBox();
  void setNameEditorLabel(QString text);
public slots:
  void parameterSelectedST(ApplicationsSettingsParameter* parameter);
  void nameChangedST(QString text);
  void textChangedST(QString text);
  void iconChangedST(QString text);
signals:
  void parameterNameChanged(ApplicationsSettingsParameter* parameter);
private:
  ApplicationsMenuItem* _menuItem;
};

#endif /* APPLICATIONSETTINGSBOX_H_ */
