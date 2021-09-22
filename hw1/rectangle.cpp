//
// Created by TOPAPEC on 22.09.2021.
//
#include <cstdlib>
#include "rectangle.h"

void in(rectangle &r, std::ifstream &ifst) {
    ifst >> r.x_upper_left >> r.y_upper_left >> r.x_lower_right >> r.y_lower_right;
}

void in_rnd(rectangle &r) {
    r.x_upper_left = rand() % 100 + 1;
    r.y_upper_left = rand() % 100 + 1;
    r.x_lower_right = rand() % 100 + 1;
    r.y_lower_right = rand() % 100 + 1;
}

void output(rectangle & )