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

#ifndef APPLICATIONSMENUITEM_H_
#define APPLICATIONSMENUITEM_H_

#include <QString>
#include <QIcon>

#include "XMLFileElement.h"
#include "ApplicationsSettingsParameter.h"

class QMenu;

class ApplicationsMenuItem: public ApplicationsSettingsParameter{
public:
  ApplicationsMenuItem();
  virtual ~ApplicationsMenuItem();
  bool processAttributes();
  virtual bool processExtraAttributes() = 0;
  bool endElement();
  void appendMenuItems(QMenu* menu);
  void writeAttributes(QXmlStreamWriter* xml_writer);
  void setIcon(QString file_name);
private:
  void loadIcon();
public:
  QString text;
  QIcon* icon;
  QString iconFile;
};

#endif /* APPLICATIONSMENUITEM_H_ */
