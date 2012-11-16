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

#include "AuditMessageViewer.h"

#include <QtDebug>

#include "AuditMessage.h"

AuditMessageViewer::AuditMessageViewer() {
  initMessagesFormats();
}

AuditMessageViewer::~AuditMessageViewer() {
}

void AuditMessageViewer::initMessagesFormats(){
  _messagesFormat["AVC"] = "Program %comm% with pid = %pid% was blocked on %name%";
}

QString AuditMessageViewer::viewMessage(AuditMessage* message){
  QString result;
  if (_messagesFormat.contains(message->type)){
    result = _messagesFormat[message->type];
    QMapIterator<QString, AuditMessageField*> i(message->fields);
     while (i.hasNext()) {
         i.next();
        result = result.replace("%" + i.key() + "%", i.value()->interpretedValue);
     }
  }
  return result;
}
