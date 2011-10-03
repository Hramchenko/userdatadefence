/***************************************************************************
 *   Copyright (C) 2011 by Hramchenko                                      *
 *   hramchenko@bk.ru                                                      *
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

#include "PolicyEditor.h"

#include <QFileInfo>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>

#include "GlobalSettings.h"



#include <QtDebug>


PolicyEditor::PolicyEditor(QWidget* parent): QTextEdit(parent) {
  _isModified = false;
  _filePath = "unknown";
  _copyAvailable = false;
  _undoAvailable = false;
  _redoAvailable = false;
  _loadingFile = false;

  fontChangedST();

  connect(document(), SIGNAL(contentsChanged()), this, SLOT(textModifiedST()));
  connect(this, SIGNAL(copyAvailable(bool)), this, SLOT(copyAvailableST(bool)));
  connect(this, SIGNAL(undoAvailable(bool)), this, SLOT(undoAvailableST(bool)));
  connect(this, SIGNAL(redoAvailable(bool)), this, SLOT(redoAvailableST(bool)));
  connect(GlobalSettings::instance(), SIGNAL(editorsFontChanged()), this, SLOT(fontChangedST()));
}

PolicyEditor::~PolicyEditor() {
}

void PolicyEditor::fontChangedST(){
  setFont(GlobalSettings::instance()->editorsFont());
}


void PolicyEditor::textModifiedST(){
  if (_loadingFile)
    return;
  _isModified = _undoAvailable || _redoAvailable;
  if (!_isModified)
    return;
  emit(editorCaptionChanged(this));
  emit(editorStateChanged(this));
}

void PolicyEditor::setFile(QString file_path){
  _filePath = file_path;
  _isModified = false;
  document()->clearUndoRedoStacks();
  emit(editorCaptionChanged(this));
  emit(editorStateChanged(this));
  GlobalSettings::instance()->setLastOpenedFile(file_path);
}

bool PolicyEditor::isModified(){
  return _isModified;
}

QString PolicyEditor::caption(){
  QString result;
  if (_isModified)
    result += "*";
  result += fileName();
  return result;
}

QString PolicyEditor::filePath(){
  return _filePath;
}

QString PolicyEditor::fileName(){
  QString result;
  if (_filePath.isEmpty())
    result = "unknown";
  else{
    QFileInfo info(_filePath);
    result = info.fileName();
  }
  return result;
}

void PolicyEditor::activated(){
  emit(editorStateChanged(this));
}

void PolicyEditor::deactivated(){
}

void PolicyEditor::loadFile(QString file_name){
  QFile file(file_name);
  if (!file.open(QIODevice::ReadOnly))
    return;
  QTextStream input_stream(&file);
  QString text = input_stream.readAll();
  file.close();
  _loadingFile = true;
  setPlainText(text);
  setFile(file_name);
  _loadingFile = false;
}

QString PolicyEditor::getSavingFileName(QString file_name){
  QFile file(file_name);
  while (!file.open(QIODevice::WriteOnly)){
    file_name = QFileDialog::getSaveFileName(this, tr("Save ") + fileName(), _filePath);
    if (file_name.isEmpty())
      return "";
    file.setFileName(file_name);
  }
  file.close();
  return file_name;
}

void PolicyEditor::save(){
  if (!_isModified)
    return;
  QString file_name;
  file_name = getSavingFileName(_filePath);
  saveToFile(file_name);
}

void PolicyEditor::saveAs(){
  QString file_name;
  _filePath = GlobalSettings::instance()->lastOpenedFileDir();
  file_name = getSavingFileName("");
  saveToFile(file_name);
}


void PolicyEditor::saveToFile(QString file_name){
  QFile file(file_name);
  if(!file.open(QIODevice::WriteOnly))
    return;
  QTextStream output_stream(&file);
  output_stream<<toPlainText();
  file.close();
  setFile(file_name);
}

void PolicyEditor::copyAvailableST(bool flag){
  setFlagValue(_copyAvailable, flag);
}

void PolicyEditor::undoAvailableST(bool flag){
  setFlagValue(_undoAvailable, flag);
}

void PolicyEditor::redoAvailableST(bool flag){
  setFlagValue(_redoAvailable, flag);
}

void PolicyEditor::setFlagValue(bool& flag, bool value){
  flag = value;
  emit(editorStateChanged(this));
}

bool PolicyEditor::isEditable(){
  return false;
}


bool PolicyEditor::copyEnabled(){
  return hasSelection();
}

bool PolicyEditor::undoEnabled(){
  return _undoAvailable && isEditable();
}

bool PolicyEditor::redoEnabled(){
  return _redoAvailable && isEditable();
}

bool PolicyEditor::saveActionsEnabled(){
  return _isModified;
}

bool PolicyEditor::modifyActionsEnabled(){
  return isEditable();
}

bool PolicyEditor::modifySelectionActionsEnabled(){
  return isEditable() && hasSelection();
}

bool PolicyEditor::hasSelection(){
  bool result;
  result = textCursor().hasSelection();
  return result;
}

bool PolicyEditor::selectionReadActionsEnabled(){
  return hasSelection();
}

bool PolicyEditor::closeEnabled(){
  return false;
}
