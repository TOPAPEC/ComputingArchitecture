//
// Created by TOPAPEC on 22.09.2021.
//
#include <cstdlib>
#include "rectangle.h"

void in(rectangle &r, std::ifstream &ifst) {
    ifst >> r.x_upper_left >> r.y_upper_left >> r.x_lower_right >> r.y_lower_right;
}

void in_rnd(rectangle &r) {
    r.x_upper_left = rand() % 20 + 1;
    r.y_upper_left = rand() % 20 + 1;
    // Гарантируется корректность заданной фигуры
    do {
        r.x_lower_right = rand() % 40 + 1;
        r.y_lower_right = rand() % 40 + 1;
    } while (r.x_lower_right >= r.x_upper_left || r.y_lower_right >= r.y_upper_left);
}

double perimeter(rectangle &r) {
    return 2 * ((r.x_upper_left - r.x_lower_right) + (r.y_upper_left - r.y_upper_left));
}

void output(rectangle &r, std::ofstream &ofst) {
    ofst << "It is Rectangle: x_upper_left = " << r.x_upper_left << ", y_upper_left = "
         << r.y_upper_left << ", x_lower_right = " << r.x_lower_right << ", y_lower_right = "
         << r.y_lower_right << ". Perimeter = " << perimeter(r);
}

