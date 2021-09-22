//
// Created by TOPAPEC on 22.09.2021.
//

#ifndef HW1__SHAPE_H_
#define HW1__SHAPE_H_

#include <fstream>
#include "rectangle.h"
#include "triangle.h"
#include "circle.h"

struct shape {
  enum colors {
    red,
    orange,
    yellow,
    green,
    blue,
    dark_blue,
    purple
  };
  enum key {
    Rectangle,
    Triangle,
    Circle
  };
  key k;
  union {
    rectangle r;
    triangle t;
    circle c;
  };
};

shape *in(std::ifstream &ifdt);

shape *in_rnd();

void output(shape &s, std::ofstream &ofst);

double perimeter(shape &s);

#endif //HW1__SHAPE_H_
