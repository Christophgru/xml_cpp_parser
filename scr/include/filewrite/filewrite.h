/**
 * @file
 * @author  Christoph Gründer, Yannic Grafwallner
 * @email Christoph\@familie-gruender.de
 * @version 1.0
 *
 * @section
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * @section DESCRIPTION
 *
 * This file is the header of the file generating c- and h-code
 */

#ifndef XMLPARSER_ABGABE_FILEWRITE_H
#define XMLPARSER_ABGABE_FILEWRITE_H
#include "../../XMLparser.h"
void buildC(const DHBW::filedata&);
void buildH(const DHBW::filedata&);

#endif //XMLPARSER_ABGABE_FILEWRITE_H
