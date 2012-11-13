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

#ifndef UDDEXECBUS_H_
#define UDDEXECBUS_H_

#include <QtDBus>
#include <QMap>

class UDDExecBus: public QDBusAbstractAdaptor {
  Q_OBJECT
  Q_CLASSINFO("D-Bus Interface", "net.sourceforge.userdatadefence.execbus")
public:
  virtual ~UDDExecBus();
  static UDDExecBus* instance();
  void registerService();
protected:
  UDDExecBus(QObject* parent);
public slots:
  QString getCommand(QString program_name);
public:
  QMap<QString, QString> commandsDict;
private:
  static UDDExecBus* _instance;
  QObject* _parent;
};

#endif /* UDDEXECBUS_H_ */
