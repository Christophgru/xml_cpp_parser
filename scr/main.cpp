#include <iostream>
#include "XMLparser.h"
using namespace DHBW;
int main(int argc, char *argv[]) {
    XMLparser myparser= XMLparser();
    return myparser.buildprojectfromxml(argc, argv);
}
