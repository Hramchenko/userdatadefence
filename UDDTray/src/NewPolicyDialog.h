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

#ifndef NEWPOLICYDIALOG_H_
#define NEWPOLICYDIALOG_H_

#include "ui_newpolicydialog.h"

class QValidator;

class NewPolicyDialog: public QDialog, public Ui::NewPolicyDialog {
  Q_OBJECT
public:
  NewPolicyDialog(QWidget* parent);
  virtual ~NewPolicyDialog();
public slots:
  void createPolicyST();
  void cancelST();
  void selectFolderST();
  void nameChangedST(QString name);
  void folderChangedST(QString folder);
private:
  void checkCreation();
  bool checkFile(bool old_flag, QString suffix);
  void createFileFromTemplate(QString suffix);
  QString templateFile(QString suffix);
  QString policyFilePath();
public:
  QString policyFile;
private:
  QString _folder;
  QString _name;
  QValidator* _nameValidator;
};

#endif /* NEWPOLICYDIALOG_H_ */
