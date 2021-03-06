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

#include "PreferencesDialog.h"

#include <QFile>
#include <QDir>
#include <QFontDialog>

#include "AuditMessageDefaultNotification.h"
#include "AuditMessageMultipleEventsNotification.h"
#include "AuditMessageNotificationSettings.h"
#include "AuditMessageTypeFilterNotification.h"
#include "AuditMessageRegExpFilterNotification.h"
#include "functions.h"
#include "NotificationConfigParser.h"
#include "ApplicationsControlRoot.h"
#include "ControllableApplication.h"
#include "ApplicationsParser.h"
#include "GlobalSettings.h"

#include <QtDebug>


PreferencesDialog::PreferencesDialog(QWidget* parent): QDialog(parent) {
  setupUi(this);
  _settings = GlobalSettings::instance();
  _notificationSettings = AuditMessageNotificationSettings::configurationSettings();
  _applicationsSettings = ApplicationsControlRoot::configurationApplications();
  groupsListWgt->setCurrentRow(0);
  loadDefaultMessagesTab();
  loadMultipleMessagesTab();
  alertTypeSelectionList->loadMessagesList(_notificationSettings->typeFilterNotificationsList());
  alertRegExpSelectionList->loadMessagesList(_notificationSettings->regExpFilterNotificationsList());
  applicationGroupsList->setParentST(_applicationsSettings);
  groupsSelectonList->setParentST(_applicationsSettings);
  applicatonsGroupsSelectonList->setParentST(_applicationsSettings);
  groupsSettingsBox->setNameEditorLabel("Group name:");
  modesSettingsBox->setNameEditorLabel("Mode name:");
  maxAuditMessagesCountSB->setValue(_settings->maxAuditMessagesCount());
  auditMessagesReserveSB->setValue(_settings->auditMessagesReserve());
  logUpdationTimeSB->setValue(_settings->systemMessagesUpdationTime());
  clearAlertsEditorAfterGenerationCB->setChecked(_settings->clearAlertsEditorAfterGeneration());
  _editorsFont = GlobalSettings::instance()->editorsFont();
  updateEditorsFontLabel();
}

void PreferencesDialog::updateEditorsFontLabel(){
  editorsFontLB->setFont(_editorsFont);
  QString name;
  name = _editorsFont.family();
  name += " ";
  name += QString::number(_editorsFont.pointSize());
  editorsFontLB->setText(name);
}


void PreferencesDialog::loadDefaultMessagesTab(){
  unclassifiedAlertSettingsBox->loadMessageST(_notificationSettings->defaultNotification());
  showUnknownMessagesCB->setChecked(_notificationSettings->defaultNotification()->showUnknown);
}

void PreferencesDialog::loadMultipleMessagesTab(){
  multipleAlertsSettingsBox->loadMessageST(_notificationSettings->multipleEventsNotification());
}

PreferencesDialog::~PreferencesDialog() {
}

void PreferencesDialog::showUnknownMessagesChangedST(bool state){
  _notificationSettings->defaultNotification()->showUnknown = state;
}

void PreferencesDialog::groupActivatedST(QModelIndex index){
  mainGroupBox->setTitle(index.data(Qt::DisplayRole).toString());
}

void PreferencesDialog::applyST(){
  cloneConfigurationFiles();
  AuditMessageNotificationSettings::applyConfigurationSettings();
  ApplicationsControlRoot::applyConfiguration();
  _settings->setEditorsFont(_editorsFont);
  close();
}

void PreferencesDialog::cloneConfigurationFiles(){
  saveApplicationsSettings();
  saveNotificationSettings();
}

void PreferencesDialog::saveApplicationsSettings(){
  QString applications_config = _applicationsSettings->configFile();
  ApplicationsParser parser(_applicationsSettings);
  createReserve(applications_config);
  parser.write(applications_config);
}

void PreferencesDialog::saveNotificationSettings(){
  QString notifications_config = _notificationSettings->configFile();
  NotificationConfigParser parser(_notificationSettings);
  createReserve(notifications_config);
  parser.write(notifications_config);
}

void PreferencesDialog::clearAlertsEditorAfterGenerationChangedST(bool state){
}

void PreferencesDialog::createReserve(QString file_name){
  QFile::copy(file_name, file_name + ".old");
}

void PreferencesDialog::cancelST(){
  close();
}

void PreferencesDialog::closeEvent(QCloseEvent* event) {
  AuditMessageNotificationSettings::clearConfigurationSettings();
  ApplicationsControlRoot::clearConfiguration();
  QDialog::closeEvent(event);
}

void PreferencesDialog::needNewTypeNotificationST(){
  AuditMessageNotification* message_notification = new AuditMessageTypeFilterNotification(_notificationSettings);
  _notificationSettings->typeFilterNotificationsList().append(message_notification);
  emit(typeNotificationAppended(message_notification));
}

void PreferencesDialog::needNewRegExpNotificationST(){
  AuditMessageNotification* message_notification = new AuditMessageRegExpFilterNotification(_notificationSettings);
  _notificationSettings->regExpFilterNotificationsList().append(message_notification);
  emit(regExpNotificationAppended(message_notification));
}

void PreferencesDialog::typeNotificationDeletedST(AuditMessageNotification* notification){
  QList<AuditMessageNotification*>& list = _notificationSettings->typeFilterNotificationsList();
  int index = list.indexOf(notification);
  list.removeAt(index);
  delete notification;
}

void PreferencesDialog::regExpNotificationDeletedST(AuditMessageNotification* notification){
  QList<AuditMessageNotification*>& list = _notificationSettings->regExpFilterNotificationsList();
  int index = list.indexOf(notification);
  list.removeAt(index);
  delete notification;
}

void PreferencesDialog::applicationNameChangedST(QString name){
  ControllableApplication* application = (ControllableApplication*)applicatonsList->currentParameter();
  if (!application)
    return;
  application->setName(name);
  emit(applicationNameChanged(application));
}

void PreferencesDialog::applicationCommandChangedST(QString command){
  ControllableApplication* application = (ControllableApplication*)applicatonsList->currentParameter();
  if (!application)
    return;
  application->command = command;
}

void PreferencesDialog::applicationSelectedST(ApplicationsSettingsParameter* parameter){
  QString name;
  QString command;
  ControllableApplication* application = (ControllableApplication*)parameter;
  if (application){
    name = application->name();
    command = application->command;
  }
  applicationNameLE->setText(name);
  applicatonCommandLE->setText(command);
}

void PreferencesDialog::selectEditorsFontST(){
  bool ok;
  QFont font;
  font = QFontDialog::getFont(&ok, _settings->editorsFont(), this);
  if (ok){
    _editorsFont = font;
    updateEditorsFontLabel();
  }
}

void PreferencesDialog::maxAuditMessagesCountChangedST(int count){
  _settings->setMaxAuditMessagesCount(count);
}

void PreferencesDialog::auditMessagesReserveChangedST(int count){
  _settings->setAuditMessagesReserve(count);
}

void PreferencesDialog::logUpdationIntervalChangedST(int count){
  _settings->setSystemMessagesUpdationTime(count);
}

void PreferencesDialog::oldMessagesLoadingDelayChangedST(int count){
  _settings->setOldMessagesLoadingDelay(count);
}
