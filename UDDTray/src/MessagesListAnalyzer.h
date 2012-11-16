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

#ifndef MESSAGESLISTANALYZER_H_
#define MESSAGESLISTANALYZER_H_

#include "AuditMessage.h"

class MessagesListAnalyzer {
public:
  MessagesListAnalyzer();
  virtual ~MessagesListAnalyzer();
  void apply(QList<AuditMessage*>* messages);
  virtual bool processMessage() = 0;
private:
  void deleteIterator();
public:
  AuditMessage* currentMessage;
  QList<AuditMessage*>* messagesList;
  QMutableListIterator<AuditMessage*>* messagesIterator;
};

#endif /* MESSAGESLISTANALYZER_H_ */
