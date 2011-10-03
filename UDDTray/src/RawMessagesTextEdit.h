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

#ifndef RAWMESSAGESTEXTEDIT_H_
#define RAWMESSAGESTEXTEDIT_H_

#include "PolicyEditor.h"

#include <QStringList>

class AuditMessage;

class RawMessagesTextEdit: public PolicyEditor{
  Q_OBJECT
public:
  RawMessagesTextEdit(QWidget* parent);
  virtual ~RawMessagesTextEdit();
public slots:
  void appendMessageST(AuditMessage* message);
  void clearLogST();
private:
  QString currentMessage;
  QStringList lines;
};

#endif /* RAWMESSAGESTEXTEDIT_H_ */
