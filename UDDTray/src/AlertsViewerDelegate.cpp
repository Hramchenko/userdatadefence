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

#include "AlertsViewerDelegate.h"

#include <QPainter>

AlertsViewerDelegate::AlertsViewerDelegate(QWidget *parent): QStyledItemDelegate(parent) {
  // TODO Auto-generated constructor stub

}

AlertsViewerDelegate::~AlertsViewerDelegate() {
  // TODO Auto-generated destructor stub
}

void AlertsViewerDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
           const QModelIndex &index) const{

  if (option.state & QStyle::State_Selected)
    painter->fillRect(option.rect, option.palette.highlight());
  else
    QStyledItemDelegate::paint(painter, option, index);
}

QSize AlertsViewerDelegate::sizeHint(const QStyleOptionViewItem &option,
               const QModelIndex &index) const{
/*  if (qVariantCanConvert<StarRating>(index.data())) {
      StarRating starRating = qVariantValue<StarRating>(index.data());
      return starRating.sizeHint();
  } else {
      return QStyledItemDelegate::sizeHint(option, index);
  }*/
  return QSize(100, 20);
}
