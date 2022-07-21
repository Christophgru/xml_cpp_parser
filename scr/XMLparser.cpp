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

    //relative pfadangabe von ordner der ausführung zum xml_src ordner
    string relativepath="..\\xml_src\\";

    path=string(workingdir).substr(0,workingdir.find_last_of("\\")+1)+relativepath+path;
    readXML(path, xmldata);
    buildH(xmldata);
    buildC(xmldata);
    printf("Generating done");
}




