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

#ifndef ALERTSDEPOSITARY_H_
#define ALERTSDEPOSITARY_H_

#include <QObject>
#include <QList>

class AuditMessage;

class AlertsDepositary: public QObject {
  Q_OBJECT
public:
  virtual ~AlertsDepositary();
  static AlertsDepositary* instance();
  void clear();
  bool needLoadingOldAlerts();
  QMutableListIterator<AuditMessage*> currentMessages();
  void flushCurrentMessages();
  unsigned int messagesCount();
  AuditMessage* message(int index);
  void flushMessages();
protected:
  AlertsDepositary();
private:
  void loadSettings();
public slots:
  void messageReceivedST(AuditMessage* message);
  void saveSettingsST();
  void clearLogST();
  void visibleChangedST(bool is_visible);
public:
  QString currentAlert;
  QString lastAlert;
  QString lastAuditMessage;
  QString lastSystemMessage;
  QString log;
private:
  static AlertsDepositary* _instance;
};

#endif /* ALERTSDEPOSITARY_H_ */
