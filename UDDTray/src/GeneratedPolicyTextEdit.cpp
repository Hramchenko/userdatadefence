/***************************************************************************
 *   Copyright (C) 2011 by Hramchenko                                      *
 *   hramchenko@bk.ru                                                      *
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

#include "GeneratedPolicyTextEdit.h"

#include <QProcess>
#include <QtDebug>

#include "AlertsDepositary.h"
#include "MainWindow.h"
#include "UDDaemonInterface.h"

GeneratedPolicyTextEdit::GeneratedPolicyTextEdit(QWidget* parent): TEEditor(parent){
  audit2Allow = new QProcess();
  connect(audit2Allow, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(audit2AllowFinishedST(int, QProcess::ExitStatus)));
  enableHighlighting(true);
}

GeneratedPolicyTextEdit::~GeneratedPolicyTextEdit() {
  delete audit2Allow;
}

void GeneratedPolicyTextEdit::clearLogST(){
  MainWindow::instance()->offPolicyGenerationActions();
  audit2Allow->kill();
  clear();
}

void GeneratedPolicyTextEdit::audit2AllowFinishedST(int exitCode, QProcess::ExitStatus){
  QByteArray result_bytes = audit2Allow->readAll();
  QString result = QString(result_bytes);
  if (exitCode)
    qDebug()<<"Error: audit2allow finished with errors.";
  setPlainText(result);
  MainWindow::instance()->offPolicyGenerationActions();
}


void GeneratedPolicyTextEdit::runAudit2Allow(QString messages){
  audit2Allow->kill();
  audit2Allow->start("audit2allow", QStringList() << "-R");
  if (!audit2Allow->waitForStarted()){
    qDebug()<<"Error: Can't start audit2allow.";
    return;
  }
  QByteArray input;
  input.append(messages);
  audit2Allow->write(input);
  audit2Allow->closeWriteChannel();
}

QString GeneratedPolicyTextEdit::auditMessages(){
  return AlertsDepositary::instance()->log;
}

QString GeneratedPolicyTextEdit::editorMessages(){
  return MainWindow::instance()->alertsEditorText();
}

QString GeneratedPolicyTextEdit::systemMessages(){
  QString last_messages;
  last_messages = UDDaemonInterface::instance()->loadLastMessages(AlertsDepositary::instance()->lastSystemMessage);
  return last_messages;
}

void GeneratedPolicyTextEdit::generatePolicyAllST(){
  QString messages;
  messages = systemMessages() + auditMessages();
  runAudit2Allow(messages);
}

void GeneratedPolicyTextEdit::generatePolicyEditorST(){
  QString messages;
  messages = editorMessages();
  runAudit2Allow(messages);
}

void GeneratedPolicyTextEdit::generatePolicySystemST(){
  QString messages;
  messages = systemMessages();
  runAudit2Allow(messages);
}

bool GeneratedPolicyTextEdit::closeEnabled(){
  return false;
}
