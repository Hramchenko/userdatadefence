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

#ifndef ALERTSLISTVIEWER_H_
#define ALERTSLISTVIEWER_H_

#include <QListView>
#include <QList>
#include <QStandardItem>

#include "AVCVisitor.h"

class AuditMessage;
class QSortFilterProxyModel;
class QStandardItemModel;

class AlertsListViewer: public QListView, public AVCVisitor{
  Q_OBJECT
public:
  AlertsListViewer(QWidget* parent = 0);
  virtual ~AlertsListViewer();
  void process(AuditMessage*& message);
public slots:
  void logClearedST();
  void alertReceivedST(AuditMessage* message);
  void filterChangedST(QString text);
  void reloadList();
  void deleteExtraMessages();
  void selectionChangedST(const QItemSelection& selected, const QItemSelection& deselected);
signals:
  void messagesSelected(QModelIndexList index_list);
private:
  QSortFilterProxyModel* proxyModel;
  QStandardItemModel* model;
  QList<QStandardItem*> itemsList;
};

#endif /* ALERTSLISTVIEWER_H_ */
