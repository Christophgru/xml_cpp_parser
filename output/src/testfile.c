//
//This empty method body for the classtestfile.c was created by Chrissi on 06/22/2022
//
#include "../headers/testfile.h"
#include <getopt.h>

void mynamespace::myclassname::getOpts(int argc, char **argv) {
    int i;
    int optindex;

    const struct option longopts[] = {

    };

    while ((i = getopt_long(argc, argv, "", longopts, &optindex)) >= 0)
        switch (i) {
            default:
                break;
        }
};


default:
break;
}
};


