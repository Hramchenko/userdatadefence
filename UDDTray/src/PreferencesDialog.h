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

#ifndef PREFERENCESDIALOG_H_
#define PREFERENCESDIALOG_H_

#include <QDialog>

#include "ui_preferencesdialog.h"

#include <QFont>

class AuditMessageNotificationSettings;
class ApplicationsControlRoot;
class ApplicationsSettingsParameter;
class GlobalSettings;

class PreferencesDialog: public QDialog, public Ui::PreferencesDialog {
  Q_OBJECT
public:
  PreferencesDialog(QWidget* parent = 0);
  virtual ~PreferencesDialog();
  void closeEvent(QCloseEvent*);
public slots:
  void groupActivatedST(QModelIndex index);
  void applyST();
  void cancelST();
  void needNewTypeNotificationST();
  void needNewRegExpNotificationST();
  void typeNotificationDeletedST(AuditMessageNotification*);
  void regExpNotificationDeletedST(AuditMessageNotification*);
  void applicationNameChangedST(QString name);
  void applicationCommandChangedST(QString command);
  void applicationSelectedST(ApplicationsSettingsParameter* parameter);
  void selectEditorsFontST();
  void maxAuditMessagesCountChangedST(int count);
  void auditMessagesReserveChangedST(int count);
  void logUpdationIntervalChangedST(int count);
  void oldMessagesLoadingDelayChangedST(int count);
  void showUnknownMessagesChangedST(bool state);
  void saveApplicationsSettings();
  void saveNotificationSettings();
  void clearAlertsEditorAfterGenerationChangedST(bool state);
signals:
  void applicationNameChanged(ApplicationsSettingsParameter* parameter);
  void typeNotificationAppended(AuditMessageNotification*);
  void regExpNotificationAppended(AuditMessageNotification*);
private:
  void updateEditorsFontLabel();
  void loadDefaultMessagesTab();
  void loadMultipleMessagesTab();
  void cloneConfigurationFiles();
  void createReserve(QString file_name);
private:
  AuditMessageNotificationSettings* _notificationSettings;
  ApplicationsControlRoot* _applicationsSettings;
  GlobalSettings* _settings;
  QFont _editorsFont;
};

#endif /* PREFERENCESDIALOG_H_ */
