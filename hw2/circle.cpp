//
// Created by TOPAPEC on 11.10.2021.
//

#include <math.h>
#include <cstdlib>
#include "circle.h"

void circle::in(FILE *fptr) {
    fscanf(fptr, "%d%d%d", &x_center, &y_center, &radius);
}

void circle::in_rnd() {
    x_center = rand() % 20 + 1;
    y_center = rand() % 20 + 1;
    radius = rand() % 20 + 1;
}

void circle::output(FILE *fptr) {
    fprintf(fptr, "It is Circle: x_center = %d, y_center = %d,"
                  " radius = %d. Perimeter = %f. Color = %s\n",
            x_center, y_center, radius, perimeter(), shape::colors_to_string(color));
}

double circle::perimeter() {
    return 2.0 * M_PI * radius;
}