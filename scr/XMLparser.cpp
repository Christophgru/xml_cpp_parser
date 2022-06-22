//
// Created by chris on 6/2/2022.
//


#include "XMLparser.h"
#include "include/filewrite/filewrite.h"
#include "include/XMLread/readXML.h"

using namespace std;


DHBW::XMLparser::~XMLparser() = default;

DHBW::XMLparser::XMLparser() = default;

void DHBW::XMLparser::generate(string path) {
    readXML(path, xmldata);
    buildH(xmldata);
    buildC(xmldata);
}




