//
// Created by chris on 6/8/2022.
//

#include "abstractXMLparser.h"
#include "stdio.h"
#include <getopt.h>

void DHBW::abstractXMLparser::getOpts(int argc, char **argv) {
    //yannic
    //getoptsmagic
    //Falls c-code erstellt werden soll, schreibe pfad des xml_src-files in xmlpfad
    //sonst -help oder -v aufrufen oder so
    int i;
    int optindex;

    const struct option longopts[] =
            {
                    {"help",    no_argument, nullptr, 'h'},
                    {"version", no_argument, nullptr, 'v'}
            };

    while ((i = getopt_long(argc, argv, "hv", longopts, &optindex)) >=
           0) //nur options ändern sich : nach Buchstaben falls Parameter
        switch (i) {
            case 'h': //help
                printhelp();
            case 'v': //help
                printversion();
            default:
                break;
        }
};


void DHBW::abstractXMLparser::printhelp() {
    std::string helptext;
    helptext = "";
    printf(helptext.data());
}

void DHBW::abstractXMLparser::printversion() {
    printf(getValueOfVersion().data());
}

std::string DHBW::abstractXMLparser::getValueOfVersion() {
    return Version;
}

bool DHBW::abstractXMLparser::isSetVersion() {
    return !Version.empty();
}
