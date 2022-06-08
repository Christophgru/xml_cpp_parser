#include <iostream>
#include "XMLparser.h"
using namespace DHBW;
int main(int argc, char** argv) {
    XMLparser myparser= XMLparser();
    myparser.getOpts(argc, argv);
}
