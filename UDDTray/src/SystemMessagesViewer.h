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

#ifndef SYSTEMMESSAGESVIEWER_H_
#define SYSTEMMESSAGESVIEWER_H_

#include "PolicyEditor.h"

class QTimer;

class SystemMessagesViewer: public PolicyEditor {
  Q_OBJECT
public:
  SystemMessagesViewer(QWidget* parent);
  virtual ~SystemMessagesViewer();
  void activated();
  void deactivated();
public slots:
  void updateST();
private:
  void setTimerInterval();
private:
  QTimer* updationTimer;
  QString lastLogLine;
  QString oldMessage;
};

#endif /* SYSTEMMESSAGESVIEWER_H_ */
