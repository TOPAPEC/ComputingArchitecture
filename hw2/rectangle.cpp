//
// Created by TOPAPEC on 11.10.2021.
//

#include <cstdlib>
#include "rectangle.h"

void rectangle::in(FILE *fptr) {
    fscanf(fptr, "%d%d%d%d", &x_upper_left, &y_upper_left, &x_lower_right, &y_lower_right);
}

void rectangle::in_rnd() {
    x_upper_left = rand() % 20 + 21;
    y_upper_left = rand() % 20 + 21;
    // Гарантируется корректность заданной фигуры
    do {
        x_lower_right = rand() % 20 + 1;
        y_lower_right = rand() % 20 + 1;
    } while (x_lower_right >= x_upper_left || y_lower_right >= y_upper_left);
}

void rectangle::output(FILE *fptr) {
    fprintf(fptr, "It is Rectangle: x_upper_left = %d, y_upper_left = %d,"
                  " x_lower_right = %d, y_lower_right = %d. Perimeter = %f. Color = %s\n",
            x_upper_left, y_upper_left, x_lower_right, y_lower_right, perimeter(), shape::colors_to_string(color));
}

double rectangle::perimeter() {
    return 2 * (abs(x_upper_left - x_lower_right) + abs(y_upper_left - y_lower_right));
}