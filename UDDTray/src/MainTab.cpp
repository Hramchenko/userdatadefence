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

#include "MainTab.h"

#include <QToolButton>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QApplication>
#include <QClipboard>
#include <QSettings>
#include <QMessageBox>

#include "PolicyEditor.h"
#include "TEEditor.h"
#include "MainWindow.h"
#include "findreplacedialog.h"
#include "NewPolicyDialog.h"
#include "AboutDialog.h"
#include "GlobalSettings.h"

#include <QtDebug>


MainTab::MainTab(QWidget* parent): QTabWidget(parent) {
  oldEditor = 0;
  findReplaceDialog = new FindReplaceDialog(this);
}

MainTab::~MainTab() {
}

void MainTab::init(){
  initSaveActions();
  initModifyActions();
  initModifySelectionActions();
  initSelectionReadActions();
  MainWindow* win = MainWindow::instance();
  connectEditor(win->rawMessageTE);
  connectEditor(win->auditMessagesTE);
  connectEditor(win->alertsEditorTE);
  connectEditor(win->systemMessagesTE);
  connectEditor(win->generatedPolicyTE);
  connect(qApp, SIGNAL(aboutToQuit()), this, SLOT(saveModifiedFilesST()));
  connect(this, SIGNAL(currentChanged(int)), this, SLOT(tabChangedST(int)));
  loadEditors();
  setCurrentIndex(0);
  tabChangedST(0);
}

PolicyEditor* MainTab::appendNewEditor(){
  PolicyEditor* result = new TEEditor(this);
  addEditor(result);
  return result;
}

void MainTab::addEditor(PolicyEditor* editor){
  connectEditor(editor);
  connect(editor, SIGNAL(editorCaptionChanged(PolicyEditor*)), this, SLOT(editorCaptionChangedST(PolicyEditor*)));
//  connect(GlobalSettings::instance(), SIGNAL(editorsFontChanged()), editor, SLOT(fontChangedST()));
  int index = addTab(editor, editor->caption());
  setCurrentIndex(index);
}

void MainTab::connectEditor(PolicyEditor* editor){
  connect(editor, SIGNAL(editorStateChanged(PolicyEditor*)), this, SLOT(editorStateChangedST(PolicyEditor*)));
}

void MainTab::loadEditors(){
  QSettings settings;
  QStringList files;
  files = settings.value("OpenedFiles", QStringList()).toStringList();
  QString file_name;
  QStringListIterator iter(files);
  while (iter.hasNext()){
    file_name = iter.next();
    openEditor(file_name);
  }
}

void MainTab::saveEditors(){
  int index;
  QStringList files;
  PolicyEditor* editor;
  for (index = firstEditorIndex(); index < count(); index++){
    editor = (PolicyEditor*)widget(index);
    files.append(editor->filePath());
  }
  QSettings settings;
  settings.setValue("OpenedFiles", files);
}

void MainTab::editorStateChangedST(PolicyEditor* editor){
  setActionListEnabled(modifyActions, editor->modifyActionsEnabled());
  setActionListEnabled(modifySelectionActions, editor->modifySelectionActionsEnabled());
  setActionListEnabled(selectionReadActions, editor->selectionReadActionsEnabled());
  setActionListEnabled(saveActions, editor->saveActionsEnabled());
  MainWindow* win = MainWindow::instance();
  win->actionEditCopy->setEnabled(editor->copyEnabled());
  win->actionEditUndo->setEnabled(editor->undoEnabled());
  win->actionEditRedo->setEnabled(editor->redoEnabled());
  win->actionCloseFile->setEnabled(editor->closeEnabled());
}

void MainTab::editorCaptionChangedST(PolicyEditor* editor){
  int index;
  index = indexOf(editor);
  setTabText(index, editor->caption());
  saveEditors();
}

void MainTab::initSaveActions(){
  MainWindow* win = MainWindow::instance();
  saveActions.append(win->actionSaveFile);
}

void MainTab::initModifyActions(){
  MainWindow* win = MainWindow::instance();
  modifyActions.append(win->actionEditPaste);
}

void MainTab::initModifySelectionActions(){
  MainWindow* win = MainWindow::instance();
  modifySelectionActions.append(win->actionEditCut);
  modifySelectionActions.append(win->actionEditDelete);
}

void MainTab::initSelectionReadActions(){
  MainWindow* win = MainWindow::instance();
  selectionReadActions.append(win->actionClearSelection);
}


void MainTab::setActionListEnabled(QList<QAction*>& actions_list, bool is_enabled){
  QListIterator<QAction*> iter(actions_list);
  while (iter.hasNext()){
    QAction* action = iter.next();
    action->setEnabled(is_enabled);
  }
}



void MainTab::newFileST(){
  appendNewEditor();
}

void MainTab::openFileST(){
  QString file_name = QFileDialog::getOpenFileName(this, tr("Open file"), GlobalSettings::instance()->lastOpenedFileDir(), tr("All files (*)"));
  if (file_name.isEmpty())
    return;
  openEditor(file_name);
}


void MainTab::closeFileST(){
  if (isCurrentEditorSpecial())
    return;
  PolicyEditor* editor = currentEditor();
  editor->save();
  int index = currentIndex();
  removeTab(index);
  oldEditor = currentEditor();
  saveEditors();
}

bool MainTab::isCurrentEditorSpecial(){
  int index = currentIndex();
  if (index < firstEditorIndex())
    return true;
  return false;
}

int MainTab::firstEditorIndex(){
  return 5;
}


PolicyEditor* MainTab::currentEditor(){
  PolicyEditor* result = 0;
  int index = currentIndex();
  if (index == 0){
    result = MainWindow::instance()->rawMessageTE;
  }
  else if (index == 1){
    result = MainWindow::instance()->auditMessagesTE;
  }
  else if (index == 2){
    result = MainWindow::instance()->alertsEditorTE;
  }
  else if (index == 3){
    result = MainWindow::instance()->systemMessagesTE;
  }
  else if (index == 4){
    result = MainWindow::instance()->generatedPolicyTE;
  }
  if (index >= firstEditorIndex()){
    result = (PolicyEditor*)currentWidget();
  }
  return result;
}

void MainTab::saveFileST(){
  PolicyEditor* editor = currentEditor();
  editor->save();
}

void MainTab::saveFileAsST(){
  PolicyEditor* editor = currentEditor();
  editor->saveAs();
}

void MainTab::saveAllFilesST(){
  int i;
  for (i = firstEditorIndex(); i < count(); i++){
    PolicyEditor* editor;
    editor = (PolicyEditor*)widget(i);
    editor->save();
  }
}

void MainTab::saveModifiedFilesST(){
  int i;
  for (i = firstEditorIndex(); i < count(); i++){
    PolicyEditor* editor;
    editor = (PolicyEditor*)widget(i);
    if (editor->isModified())
      editor->saveAs();
  }
}

void MainTab::tabChangedST(int){
  if (oldEditor)
    oldEditor->deactivated();
  PolicyEditor* editor = currentEditor();
  oldEditor = editor;
  editor->activated();
}

void MainTab::editCopyST(){
  PolicyEditor* editor = currentEditor();
  if (currentIndex() != 0){
    editor->copy();
    return;
  }
  if (editor->textCursor().hasSelection()){
    editor->copy();
    return;
  }
  QString text;
  text = editor->toPlainText();
  QApplication::clipboard()->setText(text);
}

void MainTab::editPasteST(){
  PolicyEditor* editor = currentEditor();
  editor->paste();
}

void MainTab::editCutST(){
  PolicyEditor* editor = currentEditor();
  editor->cut();
}

void MainTab::editDeleteST(){
  PolicyEditor* editor = currentEditor();
  editor->textCursor().removeSelectedText();
}

void MainTab::editSelectAllST(){
  int index = currentIndex();
  if (index > 0){
    PolicyEditor* editor = currentEditor();
    editor->selectAll();
  }
  else{
    MainWindow::instance()->alertsListLV->selectAll();
  }
}

void MainTab::editUndoST(){
  PolicyEditor* editor = currentEditor();
  editor->undo();
}

void MainTab::editRedoST(){
  PolicyEditor* editor = currentEditor();
  editor->redo();
}

void MainTab::showFindDialogST(){
  PolicyEditor* editor = currentEditor();
  findReplaceDialog->setTextEdit(editor);
  findReplaceDialog->show();
}

void MainTab::editClearSelectionST(){
  int index = currentIndex();
  if (index > 0){
    PolicyEditor* editor = currentEditor();
    QTextCursor cursor = editor->textCursor();
    cursor.clearSelection();
    editor->setTextCursor(cursor);
  }
  else{
    MainWindow::instance()->alertsListLV->clearSelection();
  }
}

void MainTab::openEditor(QString file_name){
  if (!QFile::exists(file_name))
    return;
  PolicyEditor* editor = appendNewEditor();
  editor->loadFile(file_name);
}


void MainTab::createPolicyST(){
  NewPolicyDialog dialog(this);
  dialog.exec();
  QString file = dialog.policyFile;
  if (!file.isEmpty()){
    openEditor(file + ".if");
    openEditor(file + ".fc");
    openEditor(file + ".te");
  }
}


void MainTab::showAboutDialogST(){
  AboutDialog about(this);
  about.exec();
}
