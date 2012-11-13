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

#ifndef POLICYEDITOR_H_
#define POLICYEDITOR_H_

#include <QTextEdit>

class PolicyEditor: public QTextEdit {
  Q_OBJECT
public:
  PolicyEditor(QWidget* parent);
  virtual ~PolicyEditor();
  void loadText(QString file_name);
  virtual void setFile(QString file_path);
  QString caption();
  QString fileName();
  QString filePath();
  virtual void activated();
  virtual void deactivated();
  bool isModified();
  void save();
  void saveAs();
  void loadFile(QString file_name);
  bool hasSelection();
  virtual bool copyEnabled();
  virtual bool undoEnabled();
  virtual bool redoEnabled();
  virtual bool saveActionsEnabled();
  virtual bool modifyActionsEnabled();
  virtual bool modifySelectionActionsEnabled();
  virtual bool selectionReadActionsEnabled();
  virtual bool isEditable();
  virtual bool closeEnabled();
public slots:
  void textModifiedST();
  void copyAvailableST(bool flag);
  void undoAvailableST(bool flag);
  void redoAvailableST(bool flag);
  void fontChangedST();
signals:
  void editorStateChanged(PolicyEditor* editor);
  void editorCaptionChanged(PolicyEditor* editor);
private:
  QString getSavingFileName(QString file_name);
  void saveToFile(QString file_name);
  void setFlagValue(bool& flag, bool value);
private:
  QString _filePath;
  bool _isModified;
  bool _loadingFile;
  bool _copyAvailable;
  bool _undoAvailable;
  bool _redoAvailable;
};

#endif /* POLICYEDITOR_H_ */
