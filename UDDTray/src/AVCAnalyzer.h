/***************************************************************************
 *   Copyright (C) 2011 by Hramchenko                                      *
 *   hramchenko@bk.ru                                                      *
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

#ifndef AVCANALYZER_H_
#define AVCANALYZER_H_

#include <QString>
#include <QList>

class AVCAnalyzerState;
class AuditMessage;
class AVCVisitor;

class AVCAnalyzer {
public:
  AVCAnalyzer();
  virtual ~AVCAnalyzer();
  void processMessage(QString message);
  bool hasErrors();
  QString lastError();
  void setVisitor(AVCVisitor* visitor);
private:
  void processState();
  void clearState();
private:
  AVCAnalyzerState* _state;
  AuditMessage* _message;
  AVCVisitor* _visitor;
};

#endif /* AVCANALYZER_H_ */
