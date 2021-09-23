//
// Created by TOPAPEC on 22.09.2021.
//

#ifndef HW1__CONTAINER_H_
#define HW1__CONTAINER_H_

#include "shape.h"

struct container {
  static const int MAX_LENGTH = 10000;
  int length;
  shape *cont[MAX_LENGTH];
};

void init(container &c);

void clear(container &c);

void in(container &c, std::ifstream &ifst);

void in_rnd(container &c, int size);

void output(container &c, std::ofstream &ofst);

double perimeter_sum(container &c);

#endif //HW1__CONTAINER_H_
