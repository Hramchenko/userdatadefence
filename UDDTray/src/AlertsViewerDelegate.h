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

#ifndef ALERTSVIEWERDELEGATE_H_
#define ALERTSVIEWERDELEGATE_H_

#include <QStyledItemDelegate>

class AlertsViewerDelegate: public QStyledItemDelegate {
  Q_OBJECT
public:
  AlertsViewerDelegate(QWidget *parent = 0);
  virtual ~AlertsViewerDelegate();
  void paint(QPainter *painter, const QStyleOptionViewItem &option,
             const QModelIndex &index) const;
  QSize sizeHint(const QStyleOptionViewItem &option,
                 const QModelIndex &index) const;
/*  QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                        const QModelIndex &index) const;
  void setEditorData(QWidget *editor, const QModelIndex &index) const;
  void setModelData(QWidget *editor, QAbstractItemModel *model,
                    const QModelIndex &index) const;
private slots:
  void commitAndCloseEditor();*/
};

#endif /* ALERTSVIEWERDELEGATE_H_ */
