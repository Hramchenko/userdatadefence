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

#ifndef NOTIFICATIONCONFIGROOT_H_
#define NOTIFICATIONCONFIGROOT_H_

#include <QString>
#include <QMap>
#include <QList>

#include "XMLFileElement.h"
#include "AuditMessageTypeFilterNotification.h"
#include "AuditMessageRegExpFilterNotification.h"
#include "AuditMessageMultipleEventsNotification.h"
#include "AuditMessageDefaultNotification.h"
#include "AuditMessage.h"
#include "KNotificationMessageAlert.h"

#include "NotificationConfigParser.h"

class QStandardItem;

class AuditMessageNotificationSettings: public XMLFileElement{
public:
  AuditMessageNotificationSettings();
  virtual ~AuditMessageNotificationSettings();
  static AuditMessageNotificationSettings* currentSettings();
  static AuditMessageNotificationSettings* configurationSettings();
  static void clearConfigurationSettings();
  static void applyConfigurationSettings();
  bool processAttributes();
  QString elementName();
  void writeSubElements(QXmlStreamWriter* xml_writer);
  void writeMessageNotificationsList(QXmlStreamWriter* xml_writer, QList<AuditMessageNotification*>& list);
  XMLFileElement* newElement(const QString& name, bool& error_flag);
  AuditMessageNotification* searchNotificationMessage(AuditMessage* message);
  void showMultipleEventsNotification();
  AuditMessageDefaultNotification* defaultNotification();
  AuditMessageMultipleEventsNotification* multipleEventsNotification();
  QList<AuditMessageNotification*>& typeFilterNotificationsList();
  QList<AuditMessageNotification*>& regExpFilterNotificationsList();
  QString configFile();
private:
  void loadSettings();
  AuditMessageNotification* searchNotificationWithEventsList(QList<AuditMessageNotification*>& list, AuditMessage* message);
  AuditMessageRegExpFilterNotification* searchPattern(QString message);
private:
  AuditMessageDefaultNotification* _defaultNotification;
  AuditMessageMultipleEventsNotification* _multipleEventsNotification;
  QList<AuditMessageNotification*> _typeFilterNotificationsList;
  QList<AuditMessageNotification*> _regExpFilterNotificationsList;
  static AuditMessageNotificationSettings* _currentSettings;
  static AuditMessageNotificationSettings* _configurationSettings;
private:
  friend class PreferencesDialog;
};

#endif /* NOTIFICATIONCONFIGROOT_H_ */
