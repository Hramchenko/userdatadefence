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

#ifndef IMAGESELECTIONBOX_H_
#define IMAGESELECTIONBOX_H_

#include "ui_imageselectionbox.h"

class ImageSelectionBox: public QGroupBox, public Ui::ImageSelectionBox {
  Q_OBJECT
public:
  ImageSelectionBox(QWidget* parent);
  virtual ~ImageSelectionBox();
public slots:
  void loadImageST(QString file_name);
  void showImageFileDialogST();
  void imageFileNameChangedST(QString file_name);
signals:
  void imageFileChanged(QString file_name);
};

#endif /* IMAGESELECTIONBOX_H_ */
