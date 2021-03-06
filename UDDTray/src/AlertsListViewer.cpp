/***************************************************************************
 *   Copyright (C) 2011 by Hramchenko                                      *
 *   v.hramchenko@gmail.com                                                *
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

#include "AlertsListViewer.h"

#include <QSortFilterProxyModel>
#include <QStandardItemModel>

#include "AuditMessage.h"
#include "AuditMessageNotificationSettings.h"
#include "UDDaemonInterface.h"
#include "AlertsDepositary.h"
#include "AVCAnalyzer.h"
#include "GlobalSettings.h"

#include <QtDebug>

AlertsListViewer::AlertsListViewer(QWidget* parent): QListView(parent) {
  setUniformItemSizes(true);
  model = new QStandardItemModel();
  proxyModel = new QSortFilterProxyModel();
  proxyModel->setSourceModel(model);
  proxyModel->setFilterRole(Qt::WhatsThisRole);
  proxyModel->setFilterRegExp(QRegExp("", Qt::CaseInsensitive,
      QRegExp::FixedString));
  setModel(proxyModel);
  proxyModel->setDynamicSortFilter(true);
  setSelectionMode(QAbstractItemView::ContiguousSelection);
  connect(selectionModel(), SIGNAL(selectionChanged(const QItemSelection&, const QItemSelection&)), this, SLOT(selectionChangedST(const QItemSelection&, const QItemSelection&)));
}

void AlertsListViewer::selectionChangedST(const QItemSelection&, const QItemSelection&){
  QModelIndexList indexes;
  indexes = selectionModel()->selectedIndexes();
  emit(messagesSelected(indexes));
}

AlertsListViewer::~AlertsListViewer() {
}

void AlertsListViewer::logClearedST(){
  while (!itemsList.isEmpty())
    delete itemsList.takeLast();
  model->clear();
}

void AlertsListViewer::alertReceivedST(AuditMessage* message){
  if (!message->needNotification())
    return;
  QStandardItem *parentItem = model->invisibleRootItem();
  QStandardItem *item = new QStandardItem();
  item->setText(message->formattedMessage());
  item->setIcon(message->icon());
  item->setWhatsThis(message->rawMessage());
  parentItem->insertRow(0, item);
  itemsList.insert(0, item);
  deleteExtraMessages();
}

void AlertsListViewer::deleteExtraMessages(){
  int messages_count = model->rowCount();
  if (messages_count > GlobalSettings::instance()->deletionAuditMessagesCount()){
    int max_count =  GlobalSettings::instance()->maxAuditMessagesCount();
    model->removeRows(max_count, messages_count - max_count);
    update();
  }
}

void AlertsListViewer::filterChangedST(QString text){
  proxyModel->setFilterRegExp(QRegExp(text, Qt::CaseInsensitive));
}

void AlertsListViewer::reloadList(){
  model->clear();
  if (!AlertsDepositary::instance()->needLoadingOldAlerts())
    return;
  QString messages;
  messages = UDDaemonInterface::instance()->loadLastAuditMessages(AlertsDepositary::instance()->lastAuditMessage);
  AVCAnalyzer analyzer;
  analyzer.setVisitor(this);
  analyzer.processMessage(messages);
}

void AlertsListViewer::process(AuditMessage*& message){
  alertReceivedST(message);
}

