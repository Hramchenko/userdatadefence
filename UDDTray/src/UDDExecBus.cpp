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

#include "UDDExecBus.h"

#include <QtDebug>

UDDExecBus* UDDExecBus::_instance = 0;

UDDExecBus::UDDExecBus(QObject* parent): QDBusAbstractAdaptor(parent){
  _parent = parent;
}

UDDExecBus::~UDDExecBus() {
}

UDDExecBus* UDDExecBus::instance(){
  if (!_instance){
    QObject* object = new QObject;
    _instance = new UDDExecBus(object);
  }
  return _instance;
}

void UDDExecBus::registerService(){
  QDBusConnection::sessionBus().registerObject("/ExecBus", _parent);
  if (!QDBusConnection::sessionBus().registerService("net.sourceforge.userdatadefence.execbus")) {
    fprintf(stderr, "%s\n",
        qPrintable(QDBusConnection::sessionBus().lastError().message()));
    exit(1);
  }
}

QString UDDExecBus::getCommand(QString program_name){
  QString result = "";
  if (commandsDict.contains(program_name))
    result = commandsDict[program_name];
  return result;
}

