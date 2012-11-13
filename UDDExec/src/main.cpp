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
#include <QDBusInterface>
#include <QBuffer>
#include <QDBusReply>
#include <QObject>
#include <QList>
#include <QVariant>
#include <QProcess>

int main(int argc, char** argv) {
  if (argc < 2){
    qWarning()<<"Usage: "<<argv[1]<<" <command> [arg1] [arg2] ..."<<endl;
  }
  QCoreApplication app(argc, argv);
  QDBusInterface* exec_bus = new QDBusInterface("net.sourceforge.userdatadefence.execbus", "/ExecBus", "net.sourceforge.userdatadefence.execbus");
  QList<QVariant> message_args;
  message_args.append(QString(argv[1]));
  QDBusReply<QString> reply;
  reply = exec_bus->callWithArgumentList(QDBus::AutoDetect, "getCommand", message_args);
  QObject parent;
  QString program = reply.value();
  if (program.isEmpty()){
    qDebug()<<"Can't find program in database";
    exit(0);
  }

  QStringList arguments;
  int i;
  for (i = 2; i < argc; i++)
    arguments<<QString::fromLocal8Bit(argv[i]);
  QProcess myProcess(&parent);
  myProcess.start(program, arguments);
  myProcess.waitForFinished();
  return 0;
}
