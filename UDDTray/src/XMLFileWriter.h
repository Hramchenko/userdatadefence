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

#ifndef XMLFILEWRITER_H_
#define XMLFILEWRITER_H_

#include <QXmlStreamWriter>

#include "XMLFileElement.h"

class XMLFileWriter: public XMLFileElement{
public:
  XMLFileWriter();
  virtual ~XMLFileWriter();
  void write(QString file_name);
  virtual QString fileComment() = 0;
  QString elementName();
  bool processAttributes();
private:
  QXmlStreamWriter* _xmlFileWriter;
};

#endif /* XMLFILEWRITER_H_ */
