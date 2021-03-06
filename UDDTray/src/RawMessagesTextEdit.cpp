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

#include "RawMessagesTextEdit.h"

#include "AuditMessage.h"
#include "GlobalSettings.h"

RawMessagesTextEdit::RawMessagesTextEdit(QWidget* parent): PolicyEditor(parent) {
}

RawMessagesTextEdit::~RawMessagesTextEdit() {
}

void RawMessagesTextEdit::appendMessageST(AuditMessage* message){
  currentMessage = message->rawMessage();
  lines.push_back(currentMessage);
  int messages_count = lines.count();
  if (messages_count > GlobalSettings::instance()->deletionAuditMessagesCount()){
    int max_count =  GlobalSettings::instance()->maxAuditMessagesCount();
    lines = lines.mid(max_count);
    setPlainText(lines.join("\n"));
  }
  else
    append(message->rawMessage());
}

void RawMessagesTextEdit::clearLogST(){
  clear();
}
