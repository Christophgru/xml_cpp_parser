//
// Created by chris on 6/2/2022.
//
#ifndef XMLparser_h_
#define XMLparser_h_

#include <string>

using namespace std;

namespace DHBW {


    class XMLparser {
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
            initializer_list<string> overallDescription;
            initializer_list<string> sampleUsage;
            initializer_list<opt> optarr;
        };
    public:
        XMLparser();
        int buildprojectfromxml(int argc, char *argv[]);
         ~XMLparser();

    private:
        filedata thisdata;
        string xmlpath;
        bool makeCFile();
        bool makeHFile();
        bool getOpts(int argc, char *argv[]);
        filedata loadXML(string path);

    };

}

#endif
