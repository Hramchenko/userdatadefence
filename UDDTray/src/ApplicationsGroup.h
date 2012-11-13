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

#ifndef APPLICATIONSGROUP_H_
#define APPLICATIONSGROUP_H_

#include "ApplicationsMenuItem.h"

#include <QList>

class QMenu;
class ApplicationsGroupMode;
class ApplicationsSettingsParameter;

class ApplicationsGroup: public ApplicationsMenuItem{
public:
  ApplicationsGroup();
  virtual ~ApplicationsGroup();
  bool processExtraAttributes();
  XMLFileElement* newElement(const QString& name, bool& error_flag);
  bool endElement();
  void appendMenuItems(QMenu* menu);
  QString elementName();
  void writeSubElements(QXmlStreamWriter* xml_writer);
  QList<ApplicationsSettingsParameter*>* subElements();
  ApplicationsSettingsParameter* appendNewItem();
public:
  QList<ApplicationsSettingsParameter*> modes;
  QMenu* traySubMenu;
};

#endif /* APPLICATIONSGROUP_H_ */
