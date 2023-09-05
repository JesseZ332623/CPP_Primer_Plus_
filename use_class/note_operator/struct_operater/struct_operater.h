#ifndef _STRUCT_OPERATER_H_
#define _STRUCT_OPERATER_H_

#include <iostream>
#include <cstring>
#include <windows.system.h>

const int STR_LEN = 10;

typedef struct Operater_Struct
{
    char discrible[STR_LEN];
    double data;

} Operater_s;

class _Operater
{
    private:
        Operater_s *_operater;

    public:
        _Operater();
        _Operater(const char *discrible, double data = 0.00);

        _Operater *operator+(const _Operater & oper_1) const;

        void show_struct_data() const;

        ~_Operater(); 
};

#endif