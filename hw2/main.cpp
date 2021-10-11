//
// Created by TOPAPEC on 08.10.2021.
//
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <stdio.h>
#include "container.h"

void err_msg_command() {
    printf("Incorrect command line.\nExpected:\ncommand -f inputFile"
           " outputFile1 outputFile2\nor:\ncommand -n number outputFile1 outputFile2\n");
}

void err_msg_qual() {
    printf("Incorrect qualifier value.\n"
           "Expected:\n"
           "command -f inputFile outputFile1 outputFile2\n"
           "or:\n"
           "command -n number outputFile1 outputFile2\n");
}

void err_fig_parse(int size) {
    printf("Incorrect number of figures = %d. Set 0 < number <= 10000\n", size);
}
int main(int argc, char *argv[]) {
    if (argc != 5) {
        err_msg_command();
        return -1;
    }

    printf("Initialising\n");
    container c;
    srand(static_cast<unsigned int>(time(0)));

    if (!strcmp(argv[1], "-f")) {
        printf("Parsing\n");
        FILE *fptr = fopen(argv[2], "r");
        c.in(fptr);
    } else if (!strcmp(argv[1], "-n")) {
        printf("Randomizing\n");
        auto size = atoi(argv[2]);
        if ((size < 1) || (size > 10000)) {
            err_fig_parse(size);
            return -3;
        }
        c.in_rnd(size);
    } else {
        err_msg_qual();
        return -2;
    }
    printf("Filled containers\n");
    printf("Sorting\n");
    c.shaker_sort();
    printf("Printing to %s\n", argv[3]);
    FILE *fptr1 = fopen(argv[3], "w");
    fprintf(fptr1, "Filled containers:\n");
    c.output(fptr1);
    printf("Printing to %s\n", argv[4]);
    FILE *fptr2 = fopen(argv[4], "w");
    fprintf(fptr2, "Perimeter sum = %f\n", c.perimeter_sum());
    c.clear();
    printf("Finished\n");

    return 0;
}


