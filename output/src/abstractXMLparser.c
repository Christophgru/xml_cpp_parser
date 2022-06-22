//
//This empty method body for the classabstractXMLparser.c was created by Chrissi on 06/22/2022
//
#include "../headers/abstractXMLparser.h" 
#include <getopt.h>

void DHBW::abstractXMLparser::getOpts(int argc, char **argv) {
int i;
    int optindex;
bool g_flag;
    const struct option longopts[] ={
            {{"generate", required_argument+ nullptr, '103'}
};

while ((i = getopt_long(argc, argv, "g", longopts, &optindex)) >=0)
switch(i){

case '103':
string path=argv[argc-1];
103_flag =true;default:
break;
}
};


if(103){
generate();
default:
break;
}
};


string DHBW::abstractXMLparser::getValueOfgenerate(){
if(path==or ){return path;} return path;
}

bool DHBW::abstractXMLparser::isSetpath() {
    return !path.empty();
}