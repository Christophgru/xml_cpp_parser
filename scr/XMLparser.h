//
// Created by chris on 6/2/2022.
//
#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <string>
#include "vector"
#include "abstractXMLparser.h"

using namespace std;

namespace DHBW {
    enum hasArgs {
        no_argument, optional_argument, required_argument
    };
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

    class XMLparser : public abstractXMLparser {

    public:
        filedata xmldata;

        XMLparser();

        ~XMLparser();


    private:
        void generate(string path);
    };

}

#endif
