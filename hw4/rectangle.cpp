//
// Created by TOPAPEC on 22.09.2021.
//
#include <cstdlib>
#include "rectangle.h"
extern "C" double perimeter_rectangle(int x_upperl, int x_lowerr, int y_upperl, int y_lowerr);

void in(rectangle &r, std::ifstream &ifst) {
    ifst >> r.x_upper_left >> r.y_upper_left >> r.x_lower_right >> r.y_lower_right;
}

void in_rnd(rectangle &r) {
    r.x_upper_left = rand() % 20 + 21;
    r.y_upper_left = rand() % 20 + 21;
    // Гарантируется корректность заданной фигуры
    do {
        r.x_lower_right = rand() % 20 + 1;
        r.y_lower_right = rand() % 20 + 1;
    } while (r.x_lower_right >= r.x_upper_left || r.y_lower_right >= r.y_upper_left);
}

double perimeter(rectangle &r) {
    return perimeter_rectangle(r.x_upper_left, r.x_lower_right, r.y_upper_left, r.y_lower_right);
//    return 2*(r.y_upper_left - r.x_lower_right)*(r.y_upper_left-r.y_lower_right);
}

void output(rectangle &r, std::ofstream &ofst) {
    ofst << "It is Rectangle: x_upper_left = " << r.x_upper_left << ", y_upper_left = "
         << r.y_upper_left << ", x_lower_right = " << r.x_lower_right << ", y_lower_right = "
         << r.y_lower_right << ". Perimeter = " << perimeter(r);
}

