//
// Created by TOPAPEC on 11.10.2021.
//

#ifndef HW2__RECTANGLE_H_
#define HW2__RECTANGLE_H_

#include <cstdio>
#include "shape.h"

class rectangle : public shape {
    int x_upper_left, x_lower_right, y_upper_left, y_lower_right;
public:
    void in(FILE *fptr) override;
    void in_rnd() override;
    void output(FILE *fptr) override;
    double perimeter() override;
};

#endif //HW2__RECTANGLE_H_
