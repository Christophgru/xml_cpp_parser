//
// Created by chris on 6/8/2022.
//

#include "abstractXMLparser.h"
#include "stdio.h"

void DHBW::abstractXMLparser::getOpts(int argc, char** argv) {
    //yannic
    //getoptsmagic
    //Falls c-code erstellt werden soll, schreibe pfad des xml_src-files in xmlpfad
    //sonst -help oder -v aufrufen oder so
};



void DHBW::abstractXMLparser::printhelp() {
    printf(helptext.data());
}

void DHBW::abstractXMLparser::printversion() {
    printf(version.data());
}
