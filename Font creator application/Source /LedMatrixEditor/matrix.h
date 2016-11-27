#ifndef MATRIX_H
#define MATRIX_H

#include <math.h>
#include <stdio.h>
#include <string.h>

class Matrix
{
public:

    Matrix();

    void set_pixel(int x,int y,bool state);

    void generate_hex(char message[256]);
    void generate_dec(char message[256]);
    void generate_bin(char message[256]);

    void generate_for_device(char message[256]);

private:

    int _matrix[8][8];
};

#endif // MATRIX_H
