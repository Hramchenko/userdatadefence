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

#ifndef CONTROLLABLEAPPLICATION_H_
#define CONTROLLABLEAPPLICATION_H_

#include <QString>

#include "XMLFileElement.h"
#include "ApplicationsSettingsParameter.h"

class ControllableApplication: public ApplicationsSettingsParameter{
public:
  ControllableApplication();
  virtual ~ControllableApplication();
  bool processAttributes();
  XMLFileElement* newElement(const QString& name, bool& error_flag);
  QString elementName();
  void writeAttributes(QXmlStreamWriter* xml_writer);
  bool hasSubElements();
public:
  QString command;
};

#endif /* CONTROLLABLEAPPLICATION_H_ */
