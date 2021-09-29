//
// Created by Danil Bugrienko on 24.09.2021.
//

#include "shape.h"

shape* in(std::ifstream &ifst) {
    shape *sp;
    int k, color;
    ifst >> k >> color;
    sp = new shape;
    sp->color = static_cast<shape::colors>(color);
    switch(k) {
        case 1:
            sp->k = shape::Rectangle;
            in(sp->r, ifst);
            return sp;
        case 2:
            sp->k = shape::Triangle;
            in(sp->t, ifst);
            return sp;
        case 3:
            sp->k = shape::Circle;
            in(sp->c, ifst);
            return sp;
        default:
            return nullptr;
    }
}

shape* in_rnd() {
    shape *sp;
    sp = new shape;
    sp->color = static_cast<shape::colors>(rand() % 7);
    int k = rand() % 3 + 1;
    switch(k) {
        case 1:
            sp->k = shape::Rectangle;
            in_rnd(sp->r);
            return sp;
        case 2:
            sp->k = shape::Triangle;
            in_rnd(sp->t);
            return sp;
        case 3:
            sp->k = shape::Circle;
            in_rnd(sp->c);
            return sp;
        default:
            return nullptr;
    }
}

static char* colors_to_string(int index) {
    static char *colors_string[7] = {"red", "orange", "yellow", "green", "blue",
                                           "dark_blue", "purple"};
    return colors_string[index];
}

void output(shape &s, std::ofstream &ofst) {
    switch(s.k) {
        case shape::Rectangle:
            output(s.r, ofst);
            ofst << ". Color = " << colors_to_string(s.color) << "\n";
            return;
        case shape::Triangle:
            output(s.t, ofst);
            ofst << ". Color = " << colors_to_string(s.color) << "\n";
            return;
        case shape::Circle:
            output(s.c, ofst);
            ofst << ". Color = " << colors_to_string(s.color) << "\n";
            return;
        default:
            ofst << "Incorrect figure!" << "\n";
    }
}

double perimeter(shape &s) {
    switch(s.k) {
        case shape::Rectangle:
            return perimeter(s.r);
        case shape::Triangle:
            return perimeter(s.t);
        case shape::Circle:
            return perimeter(s.c);
        default:
            return 0.0;
    }
}


