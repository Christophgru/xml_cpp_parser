/**
 * @file
 * @author  Christoph Gründer
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
 * main. initiates the XMLparser
 */
#include <iostream>
#include "XMLparser.h"
using namespace DHBW;
int main(int argc, char** argv) {
    XMLparser myparser= XMLparser();
    myparser.parseOptions(argc, argv);
}
