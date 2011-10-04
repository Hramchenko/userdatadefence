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

#include "XMLFileReader.h"

#include <QtDebug>

XMLFileReader::XMLFileReader() {
  elements.push_back(this);
}

XMLFileReader::~XMLFileReader() {
}

void XMLFileReader::read(QString file_name){
  QFile file(file_name);
  QXmlInputSource source(&file);
  QXmlSimpleReader reader;
  reader.setContentHandler(this);
  reader.setErrorHandler(this);
  reader.parse(&source);
}

bool XMLFileReader::startElement(const QString&, const QString&,
    const QString &qName, const QXmlAttributes &attribs){
  if (elements.isEmpty())
    return false;
  XMLFileElement* new_element;
  bool error_flag = false;
  new_element = elements.back()->newElement(qName, error_flag);
  if (error_flag)
    return false;
  if (!new_element)
      return true;
  new_element->_xmlAttributes = &attribs;
  error_flag = !new_element->processAttributes();
  new_element->_xmlAttributes = 0;
  if(error_flag)
    return false;
  elements.push_back(new_element);
  return true;
}

bool XMLFileReader::endElement(const QString&, const QString&,
    const QString&){
  if (elements.isEmpty())
    return false;
  XMLFileElement* element = elements.takeLast();
  return element->endElement();
}

bool XMLFileReader::fatalError(const QXmlParseException &exception){
  qDebug()<<"Line "<<exception.lineNumber()<<" , column "<<exception.columnNumber()<<": "<<exception.message();
  return false;
}

bool XMLFileReader::processAttributes(){
  return true;
}

QString XMLFileReader::elementName(){
  return "";
}
