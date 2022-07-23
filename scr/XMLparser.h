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
 * This XML-Parser header implements the abstract class XMLParser
 */
#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <string>
#include "vector"
#include "generated/Hfiles/abstractXMLparser.h"

using namespace std;
namespace DHBW {
    ///determines if opt has /has not or might have arguments
    enum hasArgs {
        no_argument, optional_argument, required_argument
    };
    ///struct to store option-information from xml file to generate c/hfiles
    struct opt {
        int Ref = 0;//standardmäßig 0 wird genutzt für excludes
        char32_t shortOpt = '-';
        string longOpt;
        string interface;
        vector<uint8_t> exclusions;//Ref der Opts die nicht mit dieser aufgerufen werden dürfen
        string convertTo; //Datentyp des folgeparameters
        string deafaultValue;
        string connectedtoInternalMethodName;
        string connectedtoExternalMethodName;
        hasArgs hasargs = no_argument;
        string description;
    };
///struct to store information from xml file to generate c/hfiles
    struct filedata {
        string version;
        string SignPerLine;
        string hfilename;
        string cfilename;
        string nameSpaceName;
        string classname;
        string author;
        string telephonenumber;
        string email;
        vector<string> overallDescription;
        vector<string> sampleUsage;
        vector<opt> optarr;
    };
/**
 * XMLparser implements auto generated abstract xml parser
 */
    class XMLparser : public abstractXMLparser {

    public:
        /**
         * All the data needed for code generation
         */
        filedata xmldata;
/**
 * constructor
 */
        XMLparser();
/**
 * destructor
 */
        ~XMLparser();


    private:
        /**
         * main method for generation of c/h-files
         * @param path path in format "example.xml"
         */
        void generate(string path);
    };

}

#endif
