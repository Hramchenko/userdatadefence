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

#ifndef TRAYICON_H_
#define TRAYICON_H_

#include <QSystemTrayIcon>
#include <QMenu>

class MainWindow;

class TrayIcon: public QSystemTrayIcon {
  Q_OBJECT
public:
  virtual ~TrayIcon();
  void init();
  void loadControllableApplications();
  static TrayIcon* instance();
  void reloadMenu();
protected:
  TrayIcon();
public slots:
  void setMode(QString mode, int alert_level);
  void mainWindowVisibleST(bool is_visible);
  void iconActivatedST(QSystemTrayIcon::ActivationReason reason);
private:
  void createMenu();
public:
  QMenu* menu;
  QAction* showHideAction;
  MainWindow* mainWindow;
private:
  static TrayIcon* _instance;
};

#endif /* TRAYICON_H_ */
