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

#ifndef TEHIGHLIGHTER_H_
#define TEHIGHLIGHTER_H_

#include <QSyntaxHighlighter>
#include <QHash>
#include <QTextCharFormat>

struct TEHighlightingRule{
  QRegExp pattern;
  QTextCharFormat format;
};

class TEHighlighter: public QSyntaxHighlighter {
  Q_OBJECT
public:
  TEHighlighter(QTextDocument* parent = 0);
  virtual ~TEHighlighter();
protected:
  void highlightBlock(const QString &text);
private:
  void initKeyWords();
private:
  QVector<TEHighlightingRule> highlightingRules;
  QTextCharFormat keywordFormat;
  QTextCharFormat classFormat;
  QTextCharFormat singleLineCommentFormat;
  QTextCharFormat quotationFormat;
  QTextCharFormat functionFormat;
  QStringList keywordPatterns;
};

#endif /* TEHIGHLIGHTER_H_ */
