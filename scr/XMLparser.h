//
// Created by chris on 6/2/2022.
//
#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <string>

namespace DHBW {

    struct opt {
        int optIndex;
        char32_t shortOpt;
        std::string longOpt;
        std::initializer_list<uint8_t> exclusions;
        std::string connectedMethodName;
        bool hasargs;
        std::string descriptions;
    };
    struct filedata {
        std::string nameSpaceName;
        std::string classname;
        std::string author;
        std::string telephonenumber;
        std::string email;
        std::string headerFileName;
        std::string sourceFileName;
        std::initializer_list<std::string> overallDescription;
        std::initializer_list<std::string> sampleUsage;
        std::initializer_list<opt> optarr;
    };
    class XMLparser {

    public:
         filedata xmldata;
         std::string xmlpath;

        XMLparser();
        ~XMLparser();
        int buildprojectfromxml(int argc, char *argv[]);
        void printhelp();
        void printversion();
    private:
        bool makeCFile();
        bool makeHFile();
        bool getOpts(int argc, char *argv[]);
        filedata loadXML(std::string path);

    };

}

#endif
