/***************************************************************************
 *   Copyright (C) 2010 by Hramchenko                                      *
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

#include <QCoreApplication>
#include <QtDebug>

#include "UDDBusServer.h"

int main(int argc, char** argv) {
  QCoreApplication app(argc, argv);
  QObject obj;
  UDDBusServer* udd_bus = new UDDBusServer(&obj);
  QDBusConnection::systemBus().registerObject("/AVCBus", &obj);
  if (!QDBusConnection::systemBus().registerService(SERVICE_NAME)){
    fprintf(stderr, "%s\n",
        qPrintable(QDBusConnection::systemBus().lastError().message()));
    exit(1);
  }
  app.exec();
  delete udd_bus;
  return 0;
}
