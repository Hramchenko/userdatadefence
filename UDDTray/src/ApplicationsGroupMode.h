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

#ifndef APPLICATIONSGROUPMODE_H_
#define APPLICATIONSGROUPMODE_H_

#include <QList>

#include "ApplicationsMenuItem.h"

class ApplicationsGroup;
class QAction;
class ControllableApplication;
class QMenu;
class ApplicationsSettingsParameter;

class ApplicationsGroupMode: public QObject, public ApplicationsMenuItem{
  Q_OBJECT
public:
  ApplicationsGroupMode(ApplicationsGroup* group);
  virtual ~ApplicationsGroupMode();
  bool processExtraAttributes();
  XMLFileElement* newElement(const QString& name, bool& error_flag);
  QString elementName();
  void writeSubElements(QXmlStreamWriter* xml_writer);
  void setActive(bool value);
  void appendMenuItems(QMenu* menu);
  QList<ApplicationsSettingsParameter*>* subElements();
  ApplicationsSettingsParameter* appendNewItem();

public:
  QList<ApplicationsSettingsParameter*> applications;
  QAction* trayAction;
public slots:
  void modeSelectedST();
private:
  void loadCommands();
private:
  ApplicationsGroup* _group;
};

#endif /* APPLICATIONSGROUPMODE_H_ */
