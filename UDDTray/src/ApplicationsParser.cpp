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

#include "ApplicationsParser.h"

#include <QtDebug>

ApplicationsParser::ApplicationsParser(ApplicationsControlRoot* settings) {
  controlRoot = settings;
}

ApplicationsParser::~ApplicationsParser() {

}

XMLFileElement* ApplicationsParser::newElement(const QString& name, bool& error_flag){
  if (name != "controllable_applications"){
    error_flag = true;
    return 0;
  }
  return controlRoot;
}

QString ApplicationsParser::fileComment(){
  return " User Data Defence Applications ";
}

void ApplicationsParser::writeSubElements(QXmlStreamWriter* xml_writer){
  controlRoot->writeElement(xml_writer);
}
