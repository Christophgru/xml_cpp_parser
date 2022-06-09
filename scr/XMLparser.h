//
// Created by chris on 6/2/2022.
//
#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <string>
#include "abstractXMLparser.h"

namespace DHBW {
    enum hasArgs {no_argument, optional_argument, required_argument
    };
    struct opt {
        int Ref = 0;//standardmäßig 0 wird genutzt für excludes
        char32_t shortOpt;
        std::string longOpt;
        std::string interface;
        std::initializer_list<uint8_t> exclusions;//Ref der Opts die nicht mit dieser aufgerufen werden dürfen
        std::string convertTo; //Datentyp des folgeparameters
        std::string deafaultValue;
        std::string connectedtoInternalMethodName="-";
        std::string connectedtoExternalMethodName="-";
        hasArgs hasargs=no_argument;
        std::string description;
    };
    struct filedata {
        std::string SignPerLine;
        std::string hfilename;
        std::string cfilename;
        std::string nameSpaceName;
        std::string classname;
        std::string author;
        std::string telephonenumber;
        std::string email;
        std::initializer_list<std::string> overallDescription;
        std::initializer_list<std::string> sampleUsage;
        std::initializer_list<opt> optarr;
    };

    class XMLparser :public abstractXMLparser{

    public:
        filedata xmldata;

        XMLparser();
        ~XMLparser();


    private:
        void makeCFile();

        void makeHFile();

        void loadXML(std::string path);

    };

}

#endif
