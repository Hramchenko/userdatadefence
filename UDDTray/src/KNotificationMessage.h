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

#ifndef KNOTIFICATIONMESSAGE_H_
#define KNOTIFICATIONMESSAGE_H_

#include <QString>

class QByteArray;
class QStringList;
class QPixmap;

class KNotificationMessage {
public:
  KNotificationMessage();
  virtual ~KNotificationMessage();
  virtual QByteArray pixmapBytes();
  virtual QString title();
  virtual QString text();
  virtual QStringList actions();
  virtual int timeout();
  virtual void actionActivated(int action_id);
  virtual void notificationShown();
  virtual void notificationClosed();
  virtual bool needAutoDeletion();
  virtual bool needQueue();
  static QByteArray pixmapToByteArray(QPixmap pixmap);
public:
  int messageId;
};

#endif /* KNOTIFICATIONMESSAGE_H_ */
