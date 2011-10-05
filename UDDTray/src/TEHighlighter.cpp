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

#include "TEHighlighter.h"

#include <QtGui>

TEHighlighter::TEHighlighter(QTextDocument* parent):QSyntaxHighlighter(parent) {
  TEHighlightingRule rule;

  keywordFormat.setForeground(Qt::darkBlue);
  keywordFormat.setFontWeight(QFont::Bold);
  initKeyWords();

  foreach (const QString &pattern, keywordPatterns) {
    rule.pattern = QRegExp("\\b" + pattern + "\\b");
    rule.format = keywordFormat;
    highlightingRules.append(rule);
  }

  classFormat.setFontWeight(QFont::Bold);
  classFormat.setForeground(Qt::darkMagenta);
  rule.pattern = QRegExp("\\$[A-Za-z0-9_]+\\b");
  rule.format = classFormat;
  highlightingRules.append(rule);

  functionFormat.setFontItalic(true);
  functionFormat.setForeground(Qt::blue);
  rule.pattern = QRegExp("\\b[A-Za-z0-9_]+(?=\\()");
  rule.format = functionFormat;
  highlightingRules.append(rule);

  singleLineCommentFormat.setForeground(Qt::gray);
  rule.pattern = QRegExp("#[^\n]*");
  rule.format = singleLineCommentFormat;
  highlightingRules.append(rule);
}



void TEHighlighter::initKeyWords(){
  keywordPatterns <<"CLONE"<<"clone"<<
      "COMMON"<<"common"<<
      "CLASS"<<"class"<<
      "CONSTRAIN"<<"constrain"<<
      "VALIDATETRANS"<<"validatetrans"<<
      "INHERITS"<<"inherits"<<
      "SID"<<"sid"<<
      "ROLE"<<"role"<<
      "ROLES"<<"roles"<<
      "TYPES"<<"types"<<
      "TYPEALIAS"<<"typealias"<<
      "TYPEATTRIBUTE"<<"typeattribute"<<
      "TYPE"<< "type"<<
      "BOOL"<<"bool"<<
      "IF"<<"if"<<
      "ELSE"<<"else"<<
      "ALIAS"<<"alias"<<
      "ATTRIBUTE"<<"attribute"<<
      "TYPE_TRANSITION"<< "type_transition"<<
      "TYPE_MEMBER"<<"type_member"<<
      "TYPE_CHANGE"<<"type_change"<<
      "ROLE_TRANSITION"<<"role_transition"<<
      "RANGE_TRANSITION"<<"range_transition"<<
      "SENSITIVITY"<<"sensitivity"<<
      "DOMINANCE"<<"dominance"<<
      "CATEGORY"<<"category"<<
      "LEVEL"<<"level"<<
      "RANGE"<<"range"<<
      "MLSCONSTRAIN"<<"mlsconstrain"<<
      "MLSVALIDATETRANS"<<"mlsvalidatetrans"<<
      "USER"<<"user"<<
      "NEVERALLOW"<<"neverallow"<<
      "ALLOW"<<"allow"<<
      "AUDITALLOW"<<"auditallow"<<
      "AUDITDENY"<<"auditdeny"<<
      "DONTAUDIT"<<"dontaudit"<<
      "SOURCE"<<"source"<<
      "TARGET"<<"target"<<
      "SAMEUSER"<<"sameuser"<<
      "module"<<"MODULE"<<"require"<<"REQUIRE"<<
      "optional"<<"OPTIONAL"<<
      "OR"<<"or"<<
      "AND"<<"and"<<
      "NOT"<<"not"<<
      "xor"<<"XOR"<<
      "eq"<<"EQ"<<
      "true"<<"TRUE"<<
      "false"<<"FALSE"<<
      "dom"<<"DOM"<<
      "domby"<<"DOMBY"<<
      "INCOMP"<<"incomp"<<
      "fscon"<<"FSCON"<<
      "portcon"<<"PORTCON"<<
      "netifcon"<<"NETIFCON"<<
      "nodecon"<<"NODECON"<<
      "fs_use_xattr"<<"FS_USE_XATTR"<<
      "fs_use_task"<<"FS_USE_TASK"<<
      "fs_use_trans"<<"FS_USE_TRANS"<<
      "genfscon"<<"GENFSCON"<<
      "r1"<<"R1"<<
      "r2"<<"R2"<<
      "r3"<<"R3"<<
      "u1"<<"U1"<<
      "u2"<<"U2"<<
      "u3"<<"U3"<<
      "t1"<<"T1"<<
      "t2"<<"T2"<<
      "t3"<<"T3"<<
      "l1"<<"L1"<<
      "l2"<<"L2"<<
      "h1"<<"H1"<<
      "h2"<<"H2"<<
      "define"<<
      "ifelse"<<
      "incr"<<
      "decr"<<
      "ifdef"<<
      "optional_policy"<<
      "tunable_policy"<<
      "gen_require"<<
      "interface"<<
      "template"<<
      "define"<< "DEFINE";
}


TEHighlighter::~TEHighlighter() {
}

void TEHighlighter::highlightBlock(const QString &text) {
  foreach (const TEHighlightingRule &rule, highlightingRules){
      QRegExp expression(rule.pattern);
      int index = expression.indexIn(text);
      while (index >= 0){
        int length = expression.matchedLength();
        setFormat(index, length, rule.format);
        index = expression.indexIn(text, index + length);
      }
  }
  setCurrentBlockState(0);
}
