//
// Created by chris on 6/8/2022.
//

#ifndef XMLPARSER_ABGABE_ABSTRACTXMLPARSER_H
#define XMLPARSER_ABGABE_ABSTRACTXMLPARSER_H

#include <string>

namespace DHBW {

    class abstractXMLparser {
    public:
        std::string xmlpath;
        const std::string version = "1.1.2.4a/c";
        const std::string helptext="Dies ist ein Helptext";

        void getOpts(int argc, char **argv);

        void printhelp();

        void printversion();

        virtual void generate(std::string path) = 0;
    };
}


#endif //XMLPARSER_ABGABE_ABSTRACTXMLPARSER_H
