//
// Created by TOPAPEC on 11.10.2021.
//

#include <cstdlib>
#include <math.h>
#include "triangle.h"

void triangle::in(FILE *fptr) {
    fscanf(fptr, "%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
}

double triangle::get_side1() const {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double triangle::get_side2() const {
    return sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
}

double triangle::get_side3() const {
    return sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
}

bool triangle::check_if_triangle_correct() const {
    return (get_side1() + get_side2() > get_side3()) &&
        (get_side1() + get_side3() > get_side2()) &&
        (get_side3() + get_side2() > get_side1());
}

void triangle::in_rnd() {
    x1 = rand() % 20 + 1;
    y1 = rand() % 20 + 1;

    do {
        x2 = rand() % 20 + 1;
        y2 = rand() % 20 + 1;
    } while (x2 == x1 && y1 == y2);

    do {
        x3 = rand() % 20 + 1;
        y3 = rand() % 20 + 1;
    } while (!check_if_triangle_correct());
}

void triangle::output(FILE *fptr) {
    fprintf(fptr, "It is Triangle: x1 = %d, y1 = %d, x2 = %d, y2 = %d, x3 = %d, y3 = %d. Perimeter = %f. Color = %s\n",
            x1, y1, x2, y2, x3, y3, perimeter(), shape::colors_to_string(color));
}

double triangle::perimeter() {
    return double(get_side1() + get_side2() + get_side3());
}