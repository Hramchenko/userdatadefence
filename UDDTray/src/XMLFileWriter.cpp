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

#include "XMLFileWriter.h"

#include <QtDebug>

XMLFileWriter::XMLFileWriter() {
  _xmlFileWriter = 0;
}

XMLFileWriter::~XMLFileWriter() {
}

void XMLFileWriter::write(QString file_name){
  QFile stream(file_name);
  stream.open(QIODevice::WriteOnly);
  _xmlFileWriter = new QXmlStreamWriter(&stream);
  _xmlFileWriter->setAutoFormatting(true);
  _xmlFileWriter->writeStartDocument();
  _xmlFileWriter->writeComment(fileComment());
  writeSubElements(_xmlFileWriter);
  _xmlFileWriter->writeEndDocument();
  stream.close();
}

QString XMLFileWriter::elementName(){
  return "";
}

bool XMLFileWriter::processAttributes(){
  return true;
}
