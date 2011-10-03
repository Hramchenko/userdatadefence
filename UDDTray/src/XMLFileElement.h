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

#ifndef XMLFILEELEMENT_H_
#define XMLFILEELEMENT_H_

#include <QXmlAttributes>
#include <QString>
#include <QXmlStreamWriter>

class XMLFileReader;


class XMLFileElement {
public:
  XMLFileElement();
  virtual ~XMLFileElement();
  virtual bool processAttributes() = 0;
  virtual XMLFileElement* newElement(const QString& name, bool& error_flag) = 0;
  virtual bool endElement();
  QString readXMLAttribute(QString name, QString default_value = "");
  virtual QString elementName() = 0;
  virtual void writeAttributes(QXmlStreamWriter* xml_writer);
  virtual void writeSubElements(QXmlStreamWriter* xml_writer);
  virtual bool hasSubElements();
  virtual void writeElement(QXmlStreamWriter* xml_writer);
private:
  const QXmlAttributes* _xmlAttributes;
private:
  friend class XMLFileReader;
};

#endif /* XMLFILEELEMENT_H_ */
