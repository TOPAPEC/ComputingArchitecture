//
// Created by TOPAPEC on 11.10.2021.
//

#ifndef HW2__TRIANGLE_H_
#define HW2__TRIANGLE_H_

#include <cstdio>
#include "shape.h"

class triangle : public shape {
    int x1, x2, x3, y1, y2, y3;
public:
    void in(FILE *fptr) override;
    void in_rnd() override;
    void output(FILE *fptr) override;
    double perimeter() override;
    double get_side1() const;
    double get_side2() const;
    double get_side3() const;
    bool check_if_triangle_correct() const;
};

#endif //HW2__TRIANGLE_H_
