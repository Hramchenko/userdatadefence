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

#include "XMLFileElement.h"

XMLFileElement::XMLFileElement() {
  _xmlAttributes = 0;
}

XMLFileElement::~XMLFileElement() {
}

bool XMLFileElement::endElement(){
  return true;
}

QString XMLFileElement::readXMLAttribute(QString name, QString default_value){
  QString result;
  result = _xmlAttributes->value(name);
  if (result.isEmpty())
    return default_value;
  return result;
}

void XMLFileElement::writeAttributes(QXmlStreamWriter*){
}

void XMLFileElement::writeSubElements(QXmlStreamWriter*){
}

bool XMLFileElement::hasSubElements(){
  return true;
}

void XMLFileElement::writeElement(QXmlStreamWriter* xml_writer){
  if (hasSubElements())
    xml_writer->writeStartElement(elementName());
  else
    xml_writer->writeEmptyElement(elementName());
  writeAttributes(xml_writer);
  writeSubElements(xml_writer);
  if (hasSubElements())
    xml_writer->writeEndElement();
}
