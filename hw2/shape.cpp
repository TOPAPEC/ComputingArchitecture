//
// Created by TOPAPEC on 08.10.2021.
//
//
// Created by Danil Bugrienko on 24.09.2021.
//

#include <cstdio>
#include <cstdlib>
#include "shape.h"
#include "rectangle.h"
#include "triangle.h"
#include "circle.h"

shape::shape() {}

shape::~shape() {}

shape *shape::generic_init_input(FILE *fptr) {
    int type, color;
    shape *object;
    fscanf(fptr, "%d%d", &type, &color);
    printf("%d %d\n", type, color);
    switch (type) {
        case 1:object = new rectangle();
            break;
        case 2:object = new triangle();
            break;
        case 3:object = new circle();
            break;
        default:object = nullptr;
    }
    object->in(fptr);
    object->color = static_cast<shape::colors>(color);
    return object;
}

shape *shape::generic_init_rand() {
    int type, color;
    type = rand() % 3 + 1;
    color = rand() % 7;
    shape *object;
    switch (type) {
        case 1:object = new rectangle();
            break;
        case 2:object = new triangle();
            break;
        case 3:object = new circle();
            break;
        default:object = nullptr;
    }
    object->in_rnd();
    object->color = static_cast<shape::colors>(color);
    return object;
}

char *shape::colors_to_string(int index) {
    static char *colors_string[7] = {"red", "orange", "yellow", "green", "blue",
                                     "dark_blue", "purple"};
    return colors_string[index];
}

void shape::in_rnd() {};
void shape::in(FILE *fptr) {};
void shape::output(FILE *fptr) {};
double shape::perimeter() {};





