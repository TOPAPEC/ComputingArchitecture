//
// Created by TOPAPEC on 23.09.2021.
//

#include <cstdlib>
#include <cmath>
#include "triangle.h"
extern "C" double perimeter_triangle(int x1, int x2, int x3, int y1, int y2, int y3);
void in(triangle &t, std::ifstream &ifst) {
    ifst >> t.x1 >> t.y1 >> t.x2 >> t.y2 >> t.x3 >> t.y3;
}

double get_side1(triangle &t) {
    return sqrt((t.x1 -t.x2)*(t.x1-t.x2) + (t.y1-t.y2)*(t.y1-t.y2));
}

double get_side2(triangle &t) {
    return sqrt((t.x1 -t.x3)*(t.x1-t.x3) + (t.y1-t.y3)*(t.y1-t.y3));
}

double get_side3(triangle &t) {
    return sqrt((t.x3 - t.x2) * (t.x3 - t.x2) + (t.y3 - t.y2) * (t.y3 - t.y2));
}

bool check_if_triangle_correct(triangle &t) {
    return (get_side1(t) + get_side2(t) > get_side3(t)) &&
        (get_side1(t) + get_side3(t) > get_side2(t)) &&
        (get_side3(t) + get_side2(t) > get_side1(t));
}

void in_rnd(triangle & t) {
    t.x1 = rand() % 20 + 1;
    t.y1 = rand() % 20 + 1;

    do {
        t.x2 = rand() % 20 + 1;
        t.y2 = rand() % 20 + 1;
    } while (t.x2 == t.x1 && t.y1 == t.y2);

    do {
        t.x3 = rand() % 20 + 1;
        t.y3 = rand() % 20 + 1;
    } while (!check_if_triangle_correct(t));
}

double perimeter(triangle &t) {
//    return double(get_side1(t) + get_side2(t) + get_side3(t));
    return perimeter_triangle(t.x1, t.x2, t.x3, t.y1, t.y2, t.y3);
}

void output(triangle &t, std::ofstream &ofst) {
    ofst << "It is Triangle: x1 = " << t.x1 <<
    ", x2 = " << t.x2 << ", x3 = " << t.x3 <<
    ", y1 = " << t.y1 << ", y2 = " << t.y2 <<
    ", y3 = " << t.y3 << ". Perimeter = " <<
    perimeter(t);
}



