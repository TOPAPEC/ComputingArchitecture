//
// Created by TOPAPEC on 08.10.2021.
//

#ifndef HW2__SHAPE_H_
#define HW2__SHAPE_H_

class shape {
public:
    enum colors {
        red,
        orange,
        yellow,
        green,
        blue,
        dark_blue,
        purple
    };
    colors color;
    shape();
    ~shape();
    static shape *generic_init_input(FILE *fptr);
    static shape *generic_init_rand();
    virtual void in(FILE *fptr);
    virtual void in_rnd();
    virtual void output(FILE *fptr);
    virtual double perimeter();
//    void clear();
    static char *colors_to_string(int index);

};
#endif //HW2__SHAPE_H_
