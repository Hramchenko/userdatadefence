/***************************************************************************
 *   Copyright (C) 2011 by Hramchenko                                      *
 *   v.hramchenko@gmail.com                                                *
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

#ifndef ALERTSSTATISTICS_H_
#define ALERTSSTATISTICS_H_

#include <QObject>

class AuditMessage;

class AlertsStatistics: public QObject {
  Q_OBJECT
public:
  virtual ~AlertsStatistics();
  static AlertsStatistics* instance();
protected:
  AlertsStatistics();
public slots:
  void messageReceivedST(AuditMessage* message);
  void clearST();
public:
  int alertsCount;
  int maxLevel;
private:
  static AlertsStatistics* _instance;
};

#endif /* ALERTSSTATISTICS_H_ */
