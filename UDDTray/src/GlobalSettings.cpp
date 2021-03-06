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

#include "GlobalSettings.h"

#include <QSettings>
#include <QFont>
#include <QFileInfo>
#include <QDir>
#include <QFile>

GlobalSettings* GlobalSettings::_instance = 0;

GlobalSettings::GlobalSettings(QObject* parent): QObject(parent) {
  _settings = new QSettings();
  loadSettings();
}

GlobalSettings::~GlobalSettings() {
  delete _settings;
}

GlobalSettings* GlobalSettings::instance(){
  if (!_instance)
    _instance = new GlobalSettings();
  return _instance;
}

void GlobalSettings::makeDirIfNeed(QString path){
  QFileInfo info(path);
  if (!info.exists()){
    QDir dir;
    dir.mkpath(path);
  }
}

QString GlobalSettings::uddHome(){
  QString result = QDir::homePath() + "/.userdatadefence/";
  makeDirIfNeed(result);
  return result;
}

QString GlobalSettings::uddShare(){
  return "/usr/share/UDDTray/";
}

QString GlobalSettings::getConfigFile(QString local_path){
  QString result = uddHome() + local_path;
  QFileInfo info(result);
  makeDirIfNeed(info.path());
  if (!info.exists()){
    QFile::copy(uddShare() + local_path, result);
  }
  return result;
}

void GlobalSettings::loadSettings(){
  _systemMessagesUpdationTime = _settings->value("SystemMessagesUpdationTime", 1000).toInt();
  _maxAuditMessagesCount = _settings->value("MaxAuditMessagesCount", 5000).toInt();
  _auditMessagesReserve = _settings->value("AuditMessagesReserve", 1000).toInt();
  _oldMessagesLoadingDelay = _settings->value("OldMessagesLoadingDelay", 5000).toInt();
  _clearAlertsEditorAfterGeneration = _settings->value("ClearAlertsEditorAfterGeneration", true).toBool();
  _editorsFont.fromString(_settings->value("EditorsFont", "Monospace").toString());
}

int GlobalSettings::systemMessagesUpdationTime(){
  return _systemMessagesUpdationTime;
}

void GlobalSettings::setSystemMessagesUpdationTime(int interval){
  _systemMessagesUpdationTime = interval;
  _settings->setValue("SystemMessagesUpdationTime", interval);
}

int GlobalSettings::maxAuditMessagesCount(){
  return _maxAuditMessagesCount;
}

int GlobalSettings::auditMessagesReserve(){
  return _auditMessagesReserve;
}

void GlobalSettings::setMaxAuditMessagesCount(int count){
  _maxAuditMessagesCount = count;
  _settings->setValue("MaxAuditMessagesCount", _maxAuditMessagesCount);
}

int GlobalSettings::oldMessagesLoadingDelay(){
  return _oldMessagesLoadingDelay;
}

bool GlobalSettings::clearAlertsEditorAfterGeneration(){
  return _clearAlertsEditorAfterGeneration;
}

void GlobalSettings::setClearAlertsEditorAfterGeneration(bool value){
  _clearAlertsEditorAfterGeneration = value;
  _settings->setValue("ClearAlertsEditorAfterGeneration", value);
}

void GlobalSettings::setOldMessagesLoadingDelay(int count){
  _oldMessagesLoadingDelay = count;
  _settings->setValue("OldMessagesLoadingDelay", _oldMessagesLoadingDelay);
}

void GlobalSettings::setAuditMessagesReserve(int count){
  _auditMessagesReserve = count;
  _settings->setValue("AuditMessagesReserve", _auditMessagesReserve);
}

int GlobalSettings::deletionAuditMessagesCount(){
  return _maxAuditMessagesCount + _auditMessagesReserve;
}

QFont GlobalSettings::editorsFont(){
  return _editorsFont;
}

void GlobalSettings::setEditorsFont(QFont font){
  _editorsFont = font;
  _settings->setValue("EditorsFont", _editorsFont.toString());
  emit(editorsFontChanged());
}

QString GlobalSettings::lastOpenedFile(){
  return _lastOpenedFile;
}

void GlobalSettings::setLastOpenedFile(QString path){
  _lastOpenedFile = path;
}

QString GlobalSettings::lastOpenedFileDir(){
  QFileInfo info(_lastOpenedFile);
  return info.path();
}

