//
// Created by TOPAPEC on 22.09.2021.
//

#ifndef HW1__TRIANGLE_H_
#define HW1__TRIANGLE_H_

#include <fstream>

struct triangle {
  int x1, x2, x3, y1, y2, y3;
};

void in(triangle &t, std::ifstream &ifst);

void in_rnd(triangle &t);

void output(triangle &t, std::ofstream &ofst);

double perimeter(triangle &t);

#endif //HW1__TRIANGLE_H_
