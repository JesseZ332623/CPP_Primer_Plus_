#ifndef _SCOPE_H_
#define _SCOPE_H_

#include <iostream>
#include <string>
#include <new>
#include <windows.system.h>

struct chaff        /*结构体 chaff 需要分配36字节*/
{
    char dross[30];
    int slag;
};

typedef class Scope_Class
{

    public:
        std::string str;
        void oil(int texas, std::string str);

} Scope;

template <typename Type>
inline Type Calculate(Type a, Type b);

#endif