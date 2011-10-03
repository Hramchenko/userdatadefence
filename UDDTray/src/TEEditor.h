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

#ifndef TEEDITOR_H_
#define TEEDITOR_H_

#include "PolicyEditor.h"

class TEHighlighter;

class TEEditor: public PolicyEditor {
public:
  TEEditor(QWidget* parent =0);
  virtual ~TEEditor();
  void setFile(QString file_path);
  void enableHighlighting(bool flag);
  bool closeEnabled();
  void deleteHighlighter();
  bool isEditable();
private:
  TEHighlighter* _highlighter;
};

#endif /* TEEDITOR_H_ */
