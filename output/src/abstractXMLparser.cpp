//
//This empty method body for the classabstractXMLparser.cpp was created by Jonas Heiss on 06/22/2022
//
#include "../headers/abstractXMLparser.h"
#include <getopt.h>

void DHBW::abstractXMLparser::getOpts(int argc, char **argv) {
    int i;
    int optindex;
    bool h_flag;
    bool v_flag;
    bool g_flag;
    const struct option longopts[] =
            {{"help",     no_argument,       nullptr, 'h'},
             {"help",     no_argument,       nullptr, 'v'},
             {"generate", required_argument, nullptr, 'g'}
            };

    while ((i = getopt_long(argc, argv, "hvg", longopts, &optindex)) >= 0)
        switch (i) {

            case 'h':
                h_flag = true;
            case 'v':
                v_flag = true;
            case 'g':
                g_flag = true;
            default:
                break;
        }

    if (h_flag) {
        if () {
            cout << "Exclusion Error: h" << endl;
            exit(1);
        } else { printhelp(); }
        printhelp();
        if (v_flag) {
            if () {
                cout << "Exclusion Error: v" << endl;
                exit(1);
            } else { printversion(); }
            printversion();
            if (g_flag) {
                if () {
                    cout << "Exclusion Error: g" << endl;
                    exit(1);
                } else { printversion(); }
                printversion();
                default:
                    break;
            }
        };


        bool DHBW::abstractXMLparser::isSet() {
            return !.empty();
        }
        bool DHBW::abstractXMLparser::isSet() {
            return !.empty();
        }
        DHBW::abstractXMLparser::getValueOfgenerate()
        {
            if (==or ){ return; }
            return;
        }

        bool DHBW::abstractXMLparser::isSet() {
            return !.empty();
        }