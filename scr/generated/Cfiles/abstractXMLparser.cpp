//
//This empty method body for the classabstractXMLparser.cpp was created by Jonas Heiss on 07/22/2022 contact me under015207619839
//
#include "../Hfiles/abstractXMLparser.h" 
#include <getopt.h>

#include <iostream>

using namespace std;


void DHBW::abstractXMLparser::parseOptions(int argc, char **argv) {
workingdir=argv[0];int i;
    int optindex;
bool h_flag = false;bool v_flag = false;bool g_flag = false;bool s_flag = false;
    const struct option longopts[] =
            {{"help", no_argument, nullptr, 'h'},{"generate", required_argument, nullptr, 'g'},{"signperline", no_argument, nullptr, 's'}
};

while ((i = getopt_long(argc, argv, "hvg:s", longopts, &optindex)) >=0)
switch(i){

case 'h':
h_flag =true;
 break;
case 'v':
v_flag =true;
 break;
case 'g':
 path=argv[argc-1];
g_flag =true;
 break;
case 's':
 signperline=atoi(argv[argc-1]);
s_flag =true;
 break;default:
break;
}

if(h_flag){
if(  v_flag ||g_flag ){
 cout << "Exclusion Error: h" << endl;
 cerr << "Exclusion Error "<<endl;
}else{printhelp(); }
}if(v_flag){
if(  h_flag ||g_flag ){
 cout << "Exclusion Error: v" << endl;
 cerr << "Exclusion Error "<<endl;
}else{printversion(); }
}if(g_flag){
if(  h_flag ||v_flag ){
 cout << "Exclusion Error: g" << endl;
 cerr << "Exclusion Error "<<endl;
}else{generate(path); }
}if(s_flag){
if(  g_flag ){
 cout << "Exclusion Error: s" << endl;
 cerr << "Exclusion Error "<<endl;
}else{; }
}}string helptextformatierung(string text, int signsperline) {
    int space_count = 0;
    bool check = false;
    int count = -1;
    for (int i = 0; i < text.length(); ++i) {
        count++;
        if (text[i] != ' ' && check) {
            space_count++;
        } else {
            space_count = 0;
            check = true;
        }
        if (count % signsperline == 0 && i != 0) {
            text[i - space_count] = '\n';
            count = space_count;
        }
    }return text;
}void DHBW::abstractXMLparser::printhelp() {
printf("%s", helptextformatierung(helptext,signperline).data());
}bool DHBW::abstractXMLparser::isSethelptext() {
    return !(helptext.empty());
}void DHBW::abstractXMLparser::printversion() {
printf("Your current Version is: %s",version.data());
}bool DHBW::abstractXMLparser::isSetversion() {
    return !(version.empty());
}string DHBW::abstractXMLparser::getValueOfpath(){
if(path!="-"||path!= ""){return path;} return path;
}

bool DHBW::abstractXMLparser::isSetpath() {
    return !(path.empty());
}bool DHBW::abstractXMLparser::isSetsignperline() {
    return !(signperline!=79);
}