//
// Created by chris on 6/2/2022.
//


#include "XMLparser.h"
#include "include/filewrite/filewrite.h"

using namespace std;



void DHBW::XMLparser::loadXML(string path) {
    //Elias
}



DHBW::XMLparser::~XMLparser()=default;

void DHBW::XMLparser::makeHFile() {
    buildH(xmldata);

}

void DHBW::XMLparser::makeCFile() {
    buildC(xmldata);

}

DHBW::XMLparser::XMLparser() {
    //Hier Speicher allokieren
}

