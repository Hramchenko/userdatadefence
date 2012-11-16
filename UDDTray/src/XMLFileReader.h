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

#ifndef XMLFILEREADER_H_
#define XMLFILEREADER_H_

#include <QXmlDefaultHandler>
#include <QList>

#include "XMLFileElement.h"

class XMLFileReader: public QXmlDefaultHandler, public XMLFileElement {
public:
  XMLFileReader();
  virtual ~XMLFileReader();
  void read(QString file_name);
  bool startElement(const QString &namespaceURI, const QString &localName,
      const QString &qName, const QXmlAttributes &attribs);
  bool endElement(const QString &namespaceURI, const QString &localName,
      const QString &qName);
  bool fatalError(const QXmlParseException &exception);
  bool processAttributes();
  QString elementName();
protected:
  QList<XMLFileElement*> elements;
};

#endif /* XMLFILEREADER_H_ */
