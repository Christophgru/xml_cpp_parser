//
// Created by chris on 6/2/2022.
//
#include <ctime>
#include "../../XMLparser.h"
#include<fstream>

using namespace std;

int write_data(const string &text, const string &name) {

    ofstream file;
    file.open(name, ios::out);
    file << text;
    file.close();


}

string get_date() {
    time_t t = time(nullptr);
    tm *now = localtime(&t);

    char buffer[128];
    strftime(buffer, sizeof(buffer), "%m/%d/%Y", now);
    return buffer;
}

string getnameofenum(DHBW::hasArgs args) {

    if (args == DHBW::required_argument) { return "required_argument"; }
    else if (args == DHBW::optional_argument) { return "optional_argument"; }
    else { return "no_argument"; }
};


std::string generateHelpstr(const DHBW::filedata &xmldata) {
    string hilfetext;
    hilfetext += "Overall Description:\n";
    for (int i = 0; i < xmldata.overallDescription.size(); ++i) {
        hilfetext += data(xmldata.overallDescription)[1];
        hilfetext += "\n";
    }
    hilfetext += "\nSample Usage:\n";

    for (int i = 0; i < xmldata.sampleUsage.size(); ++i) {
        hilfetext += data(xmldata.sampleUsage)[i];
        hilfetext += "\n";
    }
    hilfetext += "\nOptions:\n";

    for (int i = 0; i < xmldata.optarr.size(); ++i) {
        DHBW::opt optx = data(xmldata.optarr)[i];
        hilfetext += "ShortOpt: ";
        hilfetext += to_string(optx.shortOpt).empty() ? "Keine ShortOpt " : to_string(optx.shortOpt);
        hilfetext += "LongOpt: ";
        hilfetext += optx.longOpt.empty() ? "Keine LongOpt " : optx.longOpt;
        hilfetext += "Description: " + optx.description;
    }
    hilfetext += "\nKontaktdaten:\nAutoren: " + xmldata.author + " Email: " + xmldata.email;
}


void buildC(const DHBW::filedata &xmldata) {
    string c_code;
    string path_c = "./output/src/" + xmldata.cfilename;

    //SOF Comment
    string startcomment = "//\n//This empty method body for the class" + xmldata.cfilename
                          + " was created by " + xmldata.author + " on " + get_date() + "\n//\n";
    c_code += startcomment;

    //includes from hfile
    c_code += "#include \"../headers/" + xmldata.hfilename + "\" \n";
    c_code += "#include <getopt.h>\n\n";
    c_code += "void " + xmldata.nameSpaceName + "::" + xmldata.classname + "::getOpts(int argc, char **argv) {\n";
    c_code += "int i;\n"
              "    int optindex;\n";


    //Generiere für alle longopts ein shortopt
    for (int i = 0; i < xmldata.optarr.size(); ++i) {
        DHBW::opt optx = xmldata.optarr[i];
        if (optx.longOpt != "-") {
            if (optx.shortOpt == '-') {
                optx.shortOpt = tolower(optx.longOpt[0]);
            }
        }
        //und erstelle eine flag für diese shortopt
        if (optx.shortOpt != '-') {
            c_code += "bool ";
            c_code += optx.shortOpt;
            c_code += "_flag;";
        }
    }
    c_code += "\n"
              "    const struct option longopts[] ={\n"
              "            {";
    for (int i = 0; i < xmldata.optarr.size(); ++i) {
        DHBW::opt optx = xmldata.optarr[i];
        if (optx.longOpt != "-") {
            c_code += "{\"" + optx.longOpt +
                      "\", " + getnameofenum(optx.hasargs) +
                      "+ nullptr, \'";
            c_code += optx.shortOpt;
            c_code += "\'},";
        }
    }
    c_code.pop_back();//delete last comma
    c_code += "\n};\n\n";





    //switch case for options
    //create string with first letters
    string firstletter;
    for (int i = 0; i < xmldata.optarr.size(); ++i) {
        firstletter += xmldata.optarr[i].shortOpt;
    }
    c_code += "while ((i = getopt_long(argc, argv, \"" + firstletter + "\", longopts, &optindex)) >=0)\n" +
              "switch(i){\n";
    for (int i = 0; i < xmldata.optarr.size(); ++i) {
        DHBW::opt optx = xmldata.optarr[i];
        c_code += "\ncase \'";
        c_code += optx.shortOpt;
        c_code += "\':\n";
        //falls es einen übergabeparameter gab, hier casten und übergeben
        c_code += optx.convertTo + " " + optx.interface + "=argv[argc-1];\n";
        c_code += optx.shortOpt;
        c_code += "_flag =true;";
    }
    c_code += "default:\nbreak;\n}\n};\n\n\n";



//exceptioncheck&methoden aufruf
    for (int i = 0; i < xmldata.optarr.size(); ++i) {
        DHBW::opt optx = xmldata.optarr[i];
        c_code += "if(";
        c_code += optx.shortOpt;
        c_code += "){\n";
        if (optx.exclusions.size() > 0) {
            c_code += "if(";
            for (int j = 0; j < optx.exclusions.size(); ++j) {
                for (int k = 0; k < xmldata.optarr.size(); ++k) {
                    DHBW::opt opty = xmldata.optarr[i];
                    if (optx.exclusions[j] == opty.Ref) {
                        c_code += to_string(opty.shortOpt) + "_flag ||";
                    }
                }
                c_code.substr(0, c_code.size() - 2);//delete last two ||
                c_code += "){\n cout << \"Eclusion Error: " + to_string(optx.shortOpt) + "\" << endl;\nexit(1);\n";
                c_code += "}else{"
                          //Methode aufrufen
                          + (optx.connectedtoInternalMethodName == "-" ? optx.connectedtoExternalMethodName
                                                                       : optx.connectedtoInternalMethodName) +
                          "(" + optx.interface + "); }\n";
            }
        }
        if (optx.connectedtoInternalMethodName != "-") {
            c_code += optx.connectedtoInternalMethodName;
        } else { c_code += optx.connectedtoExternalMethodName; }
        c_code += "();\n";
    }
    c_code += "default:\nbreak;\n}\n};\n\n\n";


//Methoden
    for (int i = 0; i < xmldata.optarr.size(); ++i) {
        DHBW::opt optx = xmldata.optarr[i];

        //generate internal method
        if (optx.connectedtoInternalMethodName != "-") {

            //internal printhelp methodbody
            if (optx.connectedtoInternalMethodName == "printHelp") {
                c_code += "void DHBW::abstractXMLparser::print" + optx.interface + "() {\n";
                c_code += "printf(helptext.data());\n}";
            }

                //Internal print [...] Method
            else if (optx.connectedtoInternalMethodName.substr(0, size("print")) == "print") {
                c_code += "void DHBW::abstractXMLparser::print" + optx.interface + "() {\n";
                c_code += "printf(" + optx.interface + ".data());\n}";
            }
        }

        //generate interface getter und bool isSet()
        if (optx.interface != "-") {
            if (optx.hasargs != DHBW::no_argument) {
                //getter
                c_code += optx.convertTo + " " + xmldata.nameSpaceName + "::" + xmldata.classname + "::getValueOf" +
                          (optx.longOpt == "-" ? to_string(optx.shortOpt) : optx.longOpt) + "(){\n";
                if (optx.hasargs != DHBW::optional_argument) {
                    c_code +=
                            "if(" + optx.interface + "==" + optx.deafaultValue + "or ){return " + optx.interface +
                            ";}";
                }
                c_code += " return " + optx.interface + ";\n}\n\n";
            }
            //is set
            c_code += "bool " + xmldata.nameSpaceName + "::" + xmldata.classname + "::isSet" + optx.interface +
                      "() {\n"
                      "    return !" +
                      optx.interface + ".empty();\n}";
        }

    }

    write_data(c_code, path_c);
}


void buildH(const DHBW::filedata &xmldata) {

    string h_code;
    string path_h = "./output/headers/" + xmldata.hfilename;

    //SOF Comment
    string startcomment = "//\n//This empty method body for the class" + xmldata.hfilename
                          + " was created by " + xmldata.author + " on " + get_date() + "\n//\n\n";
    h_code += startcomment;

    //include Guards
    h_code += "#ifndef " + xmldata.hfilename.substr(0, xmldata.hfilename.length() - 2) + "_H" + "\n";
    h_code += "#define " + xmldata.hfilename.substr(0, xmldata.hfilename.length() - 2) + "_H" + "\n\n";

    //using namespace std
    h_code += "#include <string>\n\n";

    //start namespace
    h_code += "namespace " + xmldata.nameSpaceName + " {" + "\n\n";

    //Klassenbeschreibung
    for (int i = 0; i < xmldata.optarr.size(); ++i) {
        h_code += "//" + xmldata.overallDescription[i] + "\n";
    }

    //start class
    h_code += "\nclass " + xmldata.classname + "{" + "\n\n public:";

    //build interfaces
    for (int i = 0; i < xmldata.optarr.size(); ++i) {
        DHBW::opt optx = xmldata.optarr[i];
        if (!optx.interface.empty()) {
            if (optx.interface == "helptext") {
                h_code += "const std::string helptext=\"" + generateHelpstr(xmldata) + "\";";
            } else {
                if (optx.convertTo == "string") { optx.convertTo = "std::string"; }
                h_code += (optx.convertTo.empty() ? "void" : optx.convertTo) + " " + optx.interface + ";\n";
            }
        }
    }

    //build external method declarations
    for (int i = 0; i < xmldata.optarr.size(); ++i) {
        DHBW::opt optx = xmldata.optarr[i];

        //generate internal methods
        //Kommentar für jede Methode
        h_code += "//" + optx.description + "\n";

        //Methodendeklaration
        if (optx.connectedtoInternalMethodName != "-") {
            h_code += "void " + optx.connectedtoInternalMethodName + "();" + "\n\n";
        }
        //generate external methods
        if (optx.connectedtoExternalMethodName != "-") { //generate externam method
            h_code += "virtual void "
                      //+ xmldata.nameSpaceName + "::" + xmldata.classname + "::"
                      + optx.connectedtoExternalMethodName + "()=0;\n\n";
        }


    }

    //klammer zu Klasse
    h_code += "}\n;";

    //klammer zu namespace
    h_code += "}\n";

    //klammer zu kompiler includeguard
    h_code += "\n#endif";
    write_data(h_code.data(), path_h.data());

}



