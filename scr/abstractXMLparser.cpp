//
// Created by chris on 6/8/2022.
//

#include "abstractXMLparser.h"
#include <cstdio>
#include <getopt.h>
#include <iostream>

using namespace std;

void DHBW::abstractXMLparser::getOpts(int argc, char **argv) {
    //Falls c-code erstellt werden soll, schreibe pfad des xml_src-files in xmlpfad
    int i;
    int optindex;
    bool h_flag;
    bool v_flag;
    bool d_flag;
    bool g_flag;
    g_flag = h_flag = v_flag = d_flag = false;

    const struct option longopts[] =
            {
                    {"help",     no_argument, nullptr, 'h'},
                    // Stichwort für lange Option, Argument (no_argument, optional_argument, required_argument), flag(?), Reference auf Buchstaben
                    {"version",  no_argument, nullptr, 'v'},
                    {"date",     no_argument, nullptr, 'd'},
                    {"generate", required_argument, nullptr, 'g'}
            };

    while ((i = getopt_long(argc, argv, "hvdg:", longopts, &optindex)) >= 0) {
        //nur options ändern sich : nach Buchstaben falls Parameter
        switch (i) {
            case 'h': //help
                h_flag = true;
                break;
            case 'v': //version
                v_flag = true;
                break;
            case 'd': //date
                d_flag = true;
                break;
            case 'g':
                g_flag = true;
            default:
                break;
        }
    }

    if (h_flag/*flag für den abzufragenden Paramater*/) {
        if (v_flag || d_flag/*Alle Exclude Parameter verodert*/) {
            cout << "Exclusion Error" << endl;
            exit(1);
            //Exclude Error (wird geraised, wenn Excludes missachtet werden)
        } else {
            printhelp(); //eigentliches Ausführen der Option}
        }
    }

    if (v_flag) {
        if (h_flag || d_flag) {
            cout << "Exclusion Error" << endl;
            exit(1);
        } else { printversion(); }
    }

    if (d_flag) {
        if (h_flag || v_flag) {
            cout << "Exclusion Error" << endl;
            exit(1);
        } else {/*do sth*/}
    }
    if (g_flag) {
        string path(optarg);
        generate(path);
    }
}

void DHBW::abstractXMLparser::printhelp() {
    cout << helptext.data() << endl;
}

void DHBW::abstractXMLparser::printversion() {
    cout << "Current version: " << version.data() << endl;
}