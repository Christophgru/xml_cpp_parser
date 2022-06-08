//
// Created by chris on 6/2/2022.
//
#include "../../XMLparser.h"

using namespace std;

int write_data(const string &text, string name) {
    string filename(name);

    FILE *o_file = fopen(filename.c_str(), "w+");
    if (o_file) {
        fwrite(text.c_str(), 1, text.size(), o_file);
    }
    return 0;
}

string get_date() {
    time_t t = time(nullptr);
    tm *now = localtime(&t);

    char buffer[128];
    strftime(buffer, sizeof(buffer), "%m/%d/%Y", now);
    return buffer;
}

string getnameofenum(DHBW::hasArgs args) {

    if (args == DHBW::required) { return "required_argument"; }
    else if (args == DHBW::optional) { return "optional_argument"; }
    else { return "no_argument"; }
};


template<typename _Traits, typename _CharT, typename _Alloc>


void buildC(const DHBW::filedata &xmldata) {
    string c_code;
    string path_c = "/../output/code/" + xmldata.cfilename;

    //SOF Comment
    string startcomment = "//\n//This empty method body for the class" + xmldata.cfilename
                          + " was created by " + xmldata.author + " on " + get_date() + "\n//\n";
    c_code += startcomment;

    //includes from hfile
    c_code += "#include \" ../header/" + xmldata.cfilename + "\" \n";
    c_code += "#include <getopt.h>\n\n";
    c_code += "void " + xmldata.nameSpaceName + "::" + xmldata.classname + "::getOpts(int argc, char **argv) {\n";
    c_code += "int i;\n"
              "    int optindex;\n"
              "\n"
              "    const struct option longopts[] =\n"
              "            {";
    for (int i = 0; i < xmldata.optarr.size(); ++i) {
        DHBW::opt optx = data(xmldata.optarr)[i];
        if (optx.longOpt != "-") {
            optx.shortOpt = tolower(optx.longOpt[0]);
            c_code += "{\"" + optx.longOpt +
                      "\", " + getnameofenum(optx.hasargs) +
                      "+ nullptr, \'" + to_string(optx.shortOpt) + "\'},";
        }
    }
    c_code.pop_back();//delete last comma
    c_code += "\n};\n\n";
    //switch case for options
    //create string with first letters
    string firstletter;
    for (int i = 0; i < xmldata.optarr.size(); ++i) {
        firstletter += data(xmldata.optarr)[i].shortOpt;
    }
    c_code += "while ((i = getopt_long(argc, argv, \"" + firstletter + "\", longopts, &optindex)) >=0)\n" +
              "switch(i){\n";
    for (int i = 0; i < xmldata.optarr.size(); ++i) {
        DHBW::opt optx = data(xmldata.optarr)[i];
        c_code += "\ncase \'" + to_string(optx.shortOpt) + "\':\n";
        if (optx.connectedtoInternalMethodName != "-") {
            c_code += optx.connectedtoInternalMethodName;
        } else { c_code += optx.connectedtoExternalMethodName; }
        c_code += "();\n";
    }
    c_code += "default:\nbreak;\n}\n};\n\n\n";

    //internal methods
    for (int i = 0; i < xmldata.optarr.size(); ++i) {
        DHBW::opt optx = data(xmldata.optarr)[i];
        if(optx.connectedtoExternalMethodName!="-"){
            c_code+="void "+xmldata.nameSpaceName+"::"+xmldata.classname+"::"
                    +optx.connectedtoExternalMethodName+"()=0;\n\n";
        }
        if(optx.interface!="-"){
            c_code+=optx.convertTo+" "+xmldata.nameSpaceName+"::"+xmldata.classname+"::get"+optx.longOpt+
                    "(){\n return "+optx.interface+";\n}\n\n";
        }
        if(optx.connectedtoInternalMethodName!="-"){
            //generate method
            //if -v or -h printf, sonst idk
        }

    }

    write_data(c_code, path_c);
}


void buildH(const DHBW::filedata &xmldata) {

    string h_code;
    string path_h = "/../output/header/" + xmldata.hfilename + "\n";

    //SOF Comment
    string startcomment = "//This empty method body for the class" + xmldata.hfilename
                          + " was created by " + xmldata.author + " on " + get_date() + "\n\n\n\n";
    h_code += startcomment;

    //include Guards
    h_code += "#ifndef " + xmldata.hfilename + "_H" + "\n";
    h_code += "#define" + xmldata.hfilename + "_H" + "\n\n\n\n";

    //start namespace
    h_code += "namespace " + xmldata.nameSpaceName + " {" + "\n\n";

    //Klassenbeschreibung
    for (int i = 0; i < xmldata.optarr.size(); ++i) {
        h_code += "//" + data(xmldata.overallDescription)[i] + "\n";
    }

    //start class
    h_code += "class" + xmldata.classname + "{" + "\n\n";
    //build external method declarations
    for (int i = 0; i < xmldata.optarr.size(); ++i) {
        if (data(xmldata.optarr)[i].connectedtoExternalMethodName.compare("-") != 0) {
            //Interne methode wird hier erstellt

            //Kommentar für jede Methode
            h_code += "//" + data(xmldata.optarr)[i].description + "\n";
            //Methodendeklaration
            h_code += "void " + data(xmldata.optarr)[i].connectedtoInternalMethodName + "();" + "\n\n";
        }
    }
    //klammer zu Klasse
    h_code += "};";

    //klammer zu namespace
    h_code += "}";

    //klammer zu kompiler includeguard
    h_code += "#endif";
    write_data(h_code, path_h);

}



