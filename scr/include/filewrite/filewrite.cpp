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


void buildC( DHBW::filedata &xmldata) {
    string c_code;
    string path_c = "/../output/code/" + xmldata.cfilename + ".cpp";

    //SOF Comment
    string startcomment = "//This empty method body for the class" + xmldata.cfilename
                          + " was created by " + xmldata.author + " on " + get_date() + "\n";
    c_code += startcomment;

    //includes from hfile
    c_code += "#include \" ../header/" + xmldata.cfilename + "\" \n";


    write_data(c_code, path_c);
};

void buildH(DHBW::filedata &xmldata) {

    string h_code;
    string path_h = "/../output/header/" + xmldata.hfilename + ".h" + "\n";

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



