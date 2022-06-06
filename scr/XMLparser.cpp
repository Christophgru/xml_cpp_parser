//
// Created by chris on 6/2/2022.
//


#include "XMLparser.h"
#include "include/filewrite/filewrite.h"

using namespace std;

bool DHBW::XMLparser::getOpts(int argc, char *argv[]) {
    //yannic
    //getoptsmagic
    //Falls c-code erstellt werden soll, schreibe pfad des xml_src-files in xmlpfad
    //sonst -help oder -v aufrufen oder so
};


int DHBW::XMLparser::buildprojectfromxml(int argc, char *argv[]) {
    //start konvertierung
    getOpts(argc, argv);
    //je nach opts entweder:
    loadXML(xmlpath);
    makeCFile();
    makeHFile();
    //oder


    return false;
}

DHBW::filedata DHBW::XMLparser::loadXML(string path) {
    //Elias
}



DHBW::XMLparser::~XMLparser() {
    //Hier Speicher wieder freigeben
};

bool DHBW::XMLparser::makeHFile() {
    buildH(xmldata);

}

bool DHBW::XMLparser::makeCFile() {
    buildC(xmldata);

}

DHBW::XMLparser::XMLparser() {
    //Hier Speicher allokieren
}


void DHBW::XMLparser::printhelp() {

}

void DHBW::XMLparser::printversion() {

}
