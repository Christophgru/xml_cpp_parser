//
// Created by chris on 6/2/2022.
//
#include "XMLparser.h"

namespace DHBW {

    class XMLparser {
        int buildprojectfromxml(int argc, char *argv[]) {
            //start konvertierung
            getOpts(argc, argv);
            loadXML(xmlpath);
            makeCFile();
            makeHFile();
            return false;
        }

        XMLparser() : thisdata() {
            //Hier Speicher allokieren
        }

        ~

        XMLparser() {
            //Hier Speicher wieder freigeben
        }
    };
}