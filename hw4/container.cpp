//
// Created by TOPAPEC on 23.09.2021.
//

#include "container.h"
#include "shape.h"
#include "rectangle.h"
#include "triangle.h"
#include "circle.h"
extern "C" void shaker_sort(shape** c, int length);

void init(container &c) {
    c.length = 0;
}

void clear(container &c) {
    for (int i = 0; i < c.length; i++) {
        delete c.cont[i];
    }
    c.length = 0;
}

void in(container &c, std::ifstream &ifst) {
    while (!ifst.eof()) {
        c.cont[c.length] = in(ifst);
        if (c.cont[c.length] != NULL) {
            c.cont[c.length]->per = perimeter(*(c.cont[c.length]));
            c.length++;
        }
    }
}

void in_rnd(container &c, int size) {
    while(c.length < size) {
        c.cont[c.length] = in_rnd();
        if (c.cont[c.length] != NULL) {
            c.cont[c.length]->per = perimeter(*(c.cont[c.length]));
            c.length++;
        }
    }
}

void output(container &c, std::ofstream &ofst) {
    ofst << "Container contains " << c.length << " elements." << "\n";
    for (int i = 0; i < c.length; ++i) {
        ofst << i << ": ";
        output(*(c.cont[i]), ofst);
    }
}

double perimeter_sum(container &c) {
    double sum = 0.0;
    for (int i = 0; i < c.length; ++i) {
        sum += perimeter(*(c.cont[i]));
    }
    return sum;
}

void call_shaker_sort(container &cont) {
    shaker_sort(cont.cont, cont.length);
}