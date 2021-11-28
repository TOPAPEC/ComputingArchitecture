//
// Created by TOPAPEC on 22.09.2021.
//

#ifndef HW1__CIRCLE_H_
#define HW1__CIRCLE_H_
#include <fstream>

struct circle {
  int x_center, y_center, radius;
};

void in(circle &t, std::ifstream &ifst);

void in_rnd(circle &t);

void output(circle &t, std::ofstream &ofst);

double perimeter(circle &t);
#endif //HW1__CIRCLE_H_
