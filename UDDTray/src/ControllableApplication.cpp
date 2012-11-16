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

#include "ControllableApplication.h"

#include <QtDebug>

ControllableApplication::ControllableApplication() {
}

ControllableApplication::~ControllableApplication() {
}

bool ControllableApplication::processAttributes(){
  setName(readXMLAttribute("name"));
  command = readXMLAttribute("command");
  return true;
}

XMLFileElement* ControllableApplication::newElement(const QString&, bool& error_flag){
  error_flag = true;
  return 0;
}

QString ControllableApplication::elementName(){
  return "application";
}

void ControllableApplication::writeAttributes(QXmlStreamWriter* xml_writer){
  xml_writer->writeAttribute("name", name());
  xml_writer->writeAttribute("command", command);
}

bool ControllableApplication::hasSubElements(){
  return false;
}

