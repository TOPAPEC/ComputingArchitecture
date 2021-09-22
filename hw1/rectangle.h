//
// Created by TOPAPEC on 22.09.2021.
//

#ifndef HW1__RECTANGLE_H_
#define HW1__RECTANGLE_H_

#include <fstream>

struct rectangle {
  int x_upper_left, x_lower_right, y_upper_left, y_lower_right;
};

void in(rectangle &r, std::ifstream &ifst);

void in_rnd(rectangle &r);

void output(rectangle &r, std::ofstream &ofst);

double perimeter(rectangle &r);

#endif //HW1__RECTANGLE_H_
