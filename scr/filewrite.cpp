//
// Created by chris on 6/2/2022.
//
#include "XMLparser.h"

using namespace std;

int write_data(const string& text, string name){
    string filename(name);

    FILE *o_file = fopen(filename.c_str(), "w+");
    if (o_file){
        fwrite(text.c_str(), 1, text.size(), o_file);
    }

}

bool DHBW::XMLparser::makeCFile() {
    string  c_code;
    string path_c="/../output/code/"+thisdata.classname+".cpp";


    write_data(c_code,path_c);
    return false;
};
bool DHBW::XMLparser::makeHFile() {
    string  h_code;
    string path_c="/../output/header/"+thisdata.classname+".h";
    return false;
}



