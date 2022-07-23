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
 * For test purposes only
 */
#include "../include/filewrite/filewrite.h"

/**
 * mockup main, for test purposes
 *
 * @return
 */
int main() {
    DHBW::filedata mockdata;
    mockdata.SignPerLine = "80";
    mockdata.hfilename = "abstractXMLparser.h";
    mockdata.cfilename = "abstractXMLparser.c";
    mockdata.nameSpaceName = "DHBW";
    mockdata.classname = "abstractXMLparser";
    mockdata.author = "Chrissi";
    mockdata.email = "Christoph@familie-gruender.de";
    mockdata.overallDescription = {"Hier steht eine grundsätzliche Beschreibung"};
    mockdata.sampleUsage = {"Dies ist ein Beispiel"};
    DHBW::opt opt1;
    opt1.description="Dies ist die Beshreibung der option G";
    opt1.shortOpt = 'g';
    opt1.interface = "path";
    opt1.convertTo = "string";
    opt1.longOpt = "generate";
    opt1.connectedtoExternalMethodName = "generate";
    opt1.hasargs = DHBW::required_argument;
    mockdata.optarr = {opt1};


    buildH(mockdata);
    buildC(mockdata);
}
