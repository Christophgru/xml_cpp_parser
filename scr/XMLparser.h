//
// Created by chris on 6/2/2022.
//
#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <string>
#include <list>
using namespace std;

namespace DHBW {

    struct opt {
        int optIndex;
        char32_t shortOpt;
        string longOpt;
        initializer_list<uint8_t> exclusions;
        string connectedMethodName;
        bool hasargs;
        string descriptions;
    };
    struct filedata {
        string nameSpaceName;
        string classname;
        string author;
        string telephonenumber;
        string email;
        string headerFileName;
        string sourceFileName;
        list<string> overallDescription;
        list<string> sampleUsage;
        list<opt> optarr;
    };
    class XMLparser {

    public:
         filedata xmldata;
         string xmlpath;

        XMLparser();
        ~XMLparser();
        int buildprojectfromxml(int argc, char *argv[]);
        void printhelp();
        void printversion();
    private:
        bool makeCFile();
        bool makeHFile();
        bool getOpts(int argc, char *argv[]);
        filedata loadXML(string path);

    };

}

#endif
