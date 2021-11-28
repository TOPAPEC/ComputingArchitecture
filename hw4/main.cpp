#include <cstdlib>
#include <cstring>
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
    init(c);
    srand(static_cast<unsigned int>(time(0)));

    if (!strcmp(argv[1], "-f")) {
        printf("Parsing\n");
        std::ifstream ifst(argv[2]);
        in(c, ifst);
    } else if (!strcmp(argv[1], "-n")) {
        printf("Randomizing\n");
        auto size = atoi(argv[2]);
        if ((size < 1) || (size > 10000)) {
            err_fig_parse(size);
            return -3;
        }
        in_rnd(c, size);
    } else {
        err_msg_qual();
        return -2;
    }
    printf("Filled containers\n");
    printf("Sorting\n");
    call_shaker_sort(c);
    printf("Printing to %s\n", argv[3]);
    std::ofstream ofst1(argv[3]);
    ofst1 << "Filled containers:\n";
    output(c, ofst1);
    printf("Printing to %s\n", argv[4]);
    std::ofstream ofst2(argv[4]);
    ofst2 << "Perimeter sum = " << perimeter_sum(c) << "\n";
    clear(c);
    printf("Finished\n");

    return 0;
}
