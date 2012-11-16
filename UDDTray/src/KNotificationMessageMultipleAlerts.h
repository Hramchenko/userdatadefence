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

#ifndef KNOTIFICATIONMESSAGEMULTIPLEALERTS_H_
#define KNOTIFICATIONMESSAGEMULTIPLEALERTS_H_

#include "KNotificationMessageAlert.h"

class KNotificationMessageMultipleAlerts: public KNotificationMessageAlert {
public:
  virtual ~KNotificationMessageMultipleAlerts();
  static KNotificationMessageMultipleAlerts* instance();
  virtual void notificationShown();
  virtual void notificationClosed();
  virtual bool needAutoDeletion();
  virtual bool needQueue();
protected:
  KNotificationMessageMultipleAlerts();
public:
  bool isActive;
  static KNotificationMessageMultipleAlerts* _instance;
};

#endif /* KNOTIFICATIONMESSAGEMULTIPLEALERTS_H_ */
