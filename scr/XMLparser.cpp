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
 * This XML-Parser implements the abstract class XMLParser
 */

#include "XMLparser.h"
#include "include/filewrite/filewrite.h"
#include "include/XMLread/readXML.h"

using namespace std;

DHBW::XMLparser::~XMLparser() = default;

DHBW::XMLparser::XMLparser() = default;
/**
 *
 * @param path path in format "example.xml"
 */
void DHBW::XMLparser::generate(string path) {

    ///relative pfadangabe von ordner der ausführung zum xml_src ordner todo: when .exe in main foler set path to ".\\xml_src\\", else relative path like "..\\xml_src\\"
    string relativepath="..\\xml_src\\";

    path=string(workingdir).substr(0,workingdir.find_last_of("\\")+1)+relativepath+path;
    readXML(path, xmldata);
    buildH(xmldata);
    buildC(xmldata);
    printf("Generating done");
}




