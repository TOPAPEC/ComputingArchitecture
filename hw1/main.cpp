#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include "container.h"

void err_msg_command() {
    std::cout << "Incorrect command line.\n"
                 "Expected:\n"
                 "command -f inputFile outputFile1 outputFile2\n"
                 "or:\n"
                 "command -n number outputFile1 outputFile2\n";
}

void err_msg_qual() {
    std::cout << "Incorrect qualifier value.\n"
                 "Expected:\n"
                 "command -f inputFile outputFile1 outputFile2\n"
                 "or:\n"
                 "command -n number outputFile1 outputFile2\n";
}

void err_fig_parse(int size) {
    std::cout << "Incorrect number of figures = " << size
              << ". Set 0 < number <= 10000\n";
}
int main(int argc, char *argv[]) {
    if (argc != 5) {
        err_msg_command();
        return -1;
    }
    container c;
    init(c);

    if (!strcmp(argv[1], "-f")) {
        std::ifstream ifst(argv[2]);
        in(c, ifst);
    } else if (!strcmp(argv[1], "-n")) {
        auto size = atoi(argv[2]);
        if ((size < 1) || (size > 10000)) {
            err_fig_parse(size);
            return -3;
        }
        srand(static_cast<unsigned int>(time(0)));
        in_rnd(c, size);
    } else {
        err_msg_qual();
        return -2;
    }
    std::ofstream ofst1(argv[3]);
    ofst1 << "Filled containers:\n";
    output(c, ofst1);

    std::ofstream ofst2(argv[4]);
    ofst2 << "Perimeter sum = " << perimeter_sum(c) << "\n";
    clear(c);
    return 0;

}
