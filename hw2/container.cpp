//
// Created by TOPAPEC on 08.10.2021.
//
//
// Created by TOPAPEC on 23.09.2021.
//

#include "container.h"
#include "shape.h"
#include <algorithm>

container::container() {
    length = 0;
    cont = new shape*[MAX_LENGTH];
}

container::~container() {
    clear();
}

void container::clear() {
    for (int i = 0; i < length; i++) {
        delete cont[i];
    }
    length = 0;
}

void container::in(FILE *fptr) {
    while (!feof(fptr)) {
        cont[length] = shape::generic_init_input(fptr);
        if (cont[length] != nullptr) {
            ++length;
        }
    }
}

void container::in_rnd(int size) {
    while (length < size) {
        cont[length] = shape::generic_init_rand();
        if (cont[length] != nullptr) {
            length++;
        }
    }
}

void container::output(FILE *fptr) {
    fprintf(fptr, "Container contains %d elements.\n", length);
    for (int i = 0; i < length; ++i) {
        fprintf(fptr, "%d : ", i);
        cont[i]->output(fptr);
    }
}

double container::perimeter_sum() {
    double sum = 0.0;
    for (int i = 0; i < length; ++i) {
        sum += cont[i]->perimeter();
    }
    return sum;
}

void container::shaker_sort() {
    int control = length - 1;
    int left = 0;
    int right = length - 1;
    do {
        for (int i = left; i < right; i++) {
            if (cont[i]->perimeter() > cont[i + 1]->perimeter()) {
                std::swap(cont[i], cont[i + 1]);
                control = i;
            }
        }
        right = control;
        for (int i = right; i > left; i--) {
            if (cont[i]->perimeter() < cont[i - 1]->perimeter()) {
                std::swap(cont[i], cont[i - 1]);
                control = i;
            }
        }
        left = control;
    } while (left < right);
}
