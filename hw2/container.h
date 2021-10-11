//
// Created by TOPAPEC on 08.10.2021.
//
#include <stdio.h>
#include "shape.h"

#ifndef COMPUTINGARCHITECTURE_HW2_CONTAINER_H_
#define COMPUTINGARCHITECTURE_HW2_CONTAINER_H_

class container {
 public:
    container();
    ~container();

    void in(FILE *fptr);
    void in_rnd(int size);
    void output(FILE *fptr);
    double perimeter_sum();
    void clear();
    void shaker_sort();

 private:
    int length;
    static const int MAX_LENGTH = 10000;
    shape** cont;
};
#endif //COMPUTINGARCHITECTURE_HW2_CONTAINER_H_
