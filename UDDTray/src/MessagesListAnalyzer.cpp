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

#include "MessagesListAnalyzer.h"

MessagesListAnalyzer::MessagesListAnalyzer() {
  messagesIterator = 0;
  messagesList = 0;
  currentMessage = 0;
}

MessagesListAnalyzer::~MessagesListAnalyzer() {
}

void MessagesListAnalyzer::deleteIterator(){
  delete messagesIterator;
  messagesIterator = 0;
  currentMessage = 0;
}

void MessagesListAnalyzer::apply(QList<AuditMessage*>* messages){
  messagesList = messages;
  messagesIterator = new QMutableListIterator<AuditMessage*>(*messagesList);
  while (messagesIterator->hasNext()){
    currentMessage = messagesIterator->next();
    if (!processMessage())
      break;
  }
  deleteIterator();
}
