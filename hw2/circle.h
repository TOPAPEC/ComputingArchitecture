//
// Created by TOPAPEC on 11.10.2021.
//

#ifndef HW2__CIRCLE_H_
#define HW2__CIRCLE_H_

#include <cstdio>
#include "shape.h"

class circle : public shape {
    int x_center, y_center, radius;
public:
    void in(FILE *fptr) override;
    void in_rnd() override;
    void output(FILE *fptr) override;
    double perimeter() override;
};

#endif //HW2__CIRCLE_H_
