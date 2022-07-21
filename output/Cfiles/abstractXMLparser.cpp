//
//This empty method body for the classabstractXMLparser.cpp was created by Jonas Heiss on 07/21/2022 contact me under110
//
#include "../Hfiles/abstractXMLparser.h" 
#include <getopt.h>

#include <iostream>

using namespace std;


void DHBW::abstractXMLparser::parseOptions(int argc, char **argv) {
workingdir=argv[0];int i;
    int optindex;
bool h_flag = false;bool v_flag = false;bool g_flag = false;
    const struct option longopts[] =
            {{"help", no_argument, nullptr, 'h'},{"generate", required_argument, nullptr, 'g'}
};

while ((i = getopt_long(argc, argv, "hvg:", longopts, &optindex)) >=0)
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
 break;default:
break;
}

if(h_flag){
if(  v_flag ||g_flag ){
 cout << "Exclusion Error: h" << endl;

exit(1);
}else{printhelp(); }
}if(v_flag){
if(  h_flag ||g_flag ){
 cout << "Exclusion Error: v" << endl;

exit(1);
}else{printversion(); }
}if(g_flag){
if(  h_flag ||v_flag ){
 cout << "Exclusion Error: g" << endl;

exit(1);
}else{generate(path); }
}}void DHBW::abstractXMLparser::printhelp() {
printf("%s",helptext.data());
}bool DHBW::abstractXMLparser::isSethelptext() {
    return !helptext.empty();
}void DHBW::abstractXMLparser::printversion() {
printf("Your current Version is: %s",version.data());
}bool DHBW::abstractXMLparser::isSetversion() {
    return !version.empty();
}string DHBW::abstractXMLparser::getValueOfpath(){
if(path!="-"||path!= ""){return path;} return path;
}

bool DHBW::abstractXMLparser::isSetpath() {
    return !path.empty();
}