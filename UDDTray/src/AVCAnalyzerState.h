/***************************************************************************
 *   Copyright (C) 2011 by Hramchenko                                      *
 *   v.hramchenko@gmail.com                                                *
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

#ifndef AVCANALYZERSTATE_H_
#define AVCANALYZERSTATE_H_

#include <QString>

#include "AuditMessage.h"

typedef struct opaque auparse_state_t;

class AVCAnalyzerState {
public:
  AVCAnalyzerState();
  virtual ~AVCAnalyzerState();
  void init();
  void setError(QString message);
  QString processedLog();
  void setProcessedLog(QString log);
  char* processedLogData();
  void flushError();
  void clear();
public:
  QString _processedLog;
  QByteArray _processedLogData;
  auparse_state_t* auparseState;
  bool errorFlag;
  QString errorMessage;
};

#endif /* AVCANALYZERSTATE_H_ */
