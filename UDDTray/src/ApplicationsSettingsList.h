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

#ifndef APPLICATIONSSETTINGSLIST_H_
#define APPLICATIONSSETTINGSLIST_H_

#include "SettingsList.h"

class ApplicationsSettingsParameter;

class ApplicationsSettingsList: public SettingsList {
  Q_OBJECT
public:
  ApplicationsSettingsList(QWidget* parent);
  virtual ~ApplicationsSettingsList();
  ApplicationsSettingsParameter* currentParameter();
public slots:
  void appendNewItemST();
  void deleteCurrentItemST();
  void parameterDeletedST(ApplicationsSettingsParameter* parameter);
  void parameterAppendedST(ApplicationsSettingsParameter* parameter);
  void setParentST(ApplicationsSettingsParameter* parent);
  void itemActivatedST(QListWidgetItem * item);
  void parameterNameChangedST(ApplicationsSettingsParameter* parameter);
signals:
  void parameterDeleted(ApplicationsSettingsParameter* parameter);
  void parameterAppended(ApplicationsSettingsParameter* parameter);
  void parameterSelected(ApplicationsSettingsParameter* parameter);
private:
  void appendNewElement(ApplicationsSettingsParameter* parameter);
  QListWidgetItem* searchParameterWidget(ApplicationsSettingsParameter* parameter);
private:
  ApplicationsSettingsParameter* _parentItem;
};

#endif /* APPLICATIONSSETTINGSLIST_H_ */
