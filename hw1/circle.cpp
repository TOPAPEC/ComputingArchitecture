//
// Created by Danil Bugrienko on 24.09.2021.
//
#define _USE_MATH_DEFINES
#include <math.h>
#include <cstdlib>
#include "circle.h"

void in(circle &c, std::ifstream &ifst) {
    ifst >> c.x_center >> c.y_center >> c.radius;
}

void in_rnd(circle &c) {
    c.x_center = rand() % 20 + 1;
    c.y_center = rand() % 20 + 1;
    c.radius = rand() % 20 + 1;
}

double perimeter(circle &c) {
    return 2.0 * M_PI * c.radius;
}

void output(circle &c, std::ofstream &ofst) {
    ofst << "It is a Circle: x_center = " << c.x_center << ", y_center = " <<
            c.y_center << ", radius = " << c.radius << ". Perimeter = " << perimeter(c);
}


