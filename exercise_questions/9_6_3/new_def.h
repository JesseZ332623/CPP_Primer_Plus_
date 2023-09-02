#ifndef _NEW_DEF_H_
#define _NEW_DEF_H_

#include <iostream>
#include <new>
#include <cstring>

const int buffer_size = 48;

typedef struct chaff
{
    char dross[20];
    int slag;
} Chaff;

void show_chaff(const Chaff & chaffs);

#endif