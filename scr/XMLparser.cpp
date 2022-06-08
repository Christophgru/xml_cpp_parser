//
// Created by chris on 6/2/2022.
//


#include "XMLparser.h"
#include "include/filewrite/filewrite.h"
#include "include/XMLread/readXML.h"
using namespace std;



void DHBW::XMLparser::loadXML(string path) {
    //Elias
    readXML(path,xmldata);
}



DHBW::XMLparser::~XMLparser()=default;
DHBW::XMLparser::XMLparser() =default;

void DHBW::XMLparser::makeHFile() {
    buildH(xmldata);

}

void DHBW::XMLparser::makeCFile() {
    buildC(xmldata);

}



