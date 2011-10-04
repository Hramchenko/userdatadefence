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

#ifndef APPLICATIONSPARSER_H_
#define APPLICATIONSPARSER_H_

#include "XMLFileReader.h"
#include "XMLFileWriter.h"
#include "ApplicationsControlRoot.h"

class ApplicationsParser: public XMLFileReader, public XMLFileWriter{
public:
  ApplicationsParser(ApplicationsControlRoot* settings);
  virtual ~ApplicationsParser();
  XMLFileElement* newElement(const QString& name, bool& error_flag);
  QString fileComment();
  void writeSubElements(QXmlStreamWriter* xml_writer);
public:
  ApplicationsControlRoot* controlRoot;
};

#endif /* APPLICATIONSPARSER_H_ */
