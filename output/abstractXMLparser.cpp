//
//This empty method body for the classabstractXMLparser.cpp was created by Jonas Heiss on 07/18/2022 contact me under110
//
#include "./abstractXMLparser.h" 
#include <getopt.h>

#include <iostream>

using namespace std;


void DHBW::abstractXMLparser::getOpts(int argc, char **argv) {
workingdir=argv[0];int i;
    int optindex;
bool h_flag = false;bool v_flag = false;bool l_flag = false;bool c_flag = false;bool h_flag = false;
    const struct option longopts[] =
            {{"help", no_argument, nullptr, 'h'},{"load", required_argument, nullptr, 'l'},{"cmake", no_argument, nullptr, 'c'},{"hmake", no_argument, nullptr, 'h'}
};

while ((i = getopt_long(argc, argv, "hvl:ch", longopts, &optindex)) >=0)
switch(i){

case 'h':
h_flag =true;
 break;
case 'v':
v_flag =true;
 break;
case 'l':
l_flag =true;
 break;
case 'c':
c_flag =true;
 break;
case 'h':
h_flag =true;
 break;default:
break;
}

if(h_flag){
if(  v_flag ){
 cout << "Exclusion Error: h" << endl;
exit(1);
}else{printhelp(); }
}if(v_flag){
if(  h_flag ){
 cout << "Exclusion Error: v" << endl;
exit(1);
}else{printversion(); }
}if(l_flag){
if(  c_flag ||h_flag ){
 cout << "Exclusion Error: l" << endl;
exit(1);
}else{loadXML(); }
}if(c_flag){
if(  l_flag ||h_flag ){
 cout << "Exclusion Error: c" << endl;
exit(1);
}else{makeCFile(); }
}if(h_flag){
if(  l_flag ||c_flag ){
 cout << "Exclusion Error: h" << endl;
exit(1);
}else{makeHFile(); }
}}void DHBW::abstractXMLparser::printhelp() {
printf("%s",.data());
}void DHBW::abstractXMLparser::print-() {
printf("Your current Version is: %s",-.data());
}