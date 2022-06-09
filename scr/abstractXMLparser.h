//
// Created by chris on 6/8/2022.
//

#ifndef XMLPARSER_ABGABE_ABSTRACTXMLPARSER_H
#define XMLPARSER_ABGABE_ABSTRACTXMLPARSER_H

#include <string>

namespace DHBW {

    class abstractXMLparser {
    public:
        std::string xmlpath="example.xml";
        std::string Version="1.0";

        void getOpts(int argc, char** argv);
        void printhelp();
        void printversion();
        bool isSetVersion();
        std::string getValueOfVersion();
        virtual void loadXML(std::string path)=0;
        virtual void makeCFile()=0;
        virtual void makeHFile()=0;



    };
}


#endif //XMLPARSER_ABGABE_ABSTRACTXMLPARSER_H
