//
// Created by TOPAPEC on 22.09.2021.
//

#ifndef HW1__CONTAINER_H_
#define HW1__CONTAINER_H_

#include "shape.h"

struct container {
  const MAX_LENGTH = 10000;
  int length;
  shape *cont[MAX_LENGTH];
};

void init(container &c);

void clear(container &c);

void in(container &c);

void in_rnd(container &c, int size);

void output(container &c, ofstream &ofst);

double perimeter_sum(container &c);

#endif //HW1__CONTAINER_H_
