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

#include "ApplicationsSettingsParameter.h"

ApplicationsSettingsParameter::ApplicationsSettingsParameter() {
  // TODO Auto-generated constructor stub

}

ApplicationsSettingsParameter::~ApplicationsSettingsParameter() {
  // TODO Auto-generated destructor stub
}

QList<ApplicationsSettingsParameter*>* ApplicationsSettingsParameter::subElements(){
  return 0;
}

ApplicationsSettingsParameter* ApplicationsSettingsParameter::appendNewItem(){
  return 0;
}

QString ApplicationsSettingsParameter::name(){
  return _name;
}

void ApplicationsSettingsParameter::setName(QString name){
  _name = name;
}

