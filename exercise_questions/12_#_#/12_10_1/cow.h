#ifndef _COW_H_
#define _COW_H_

#include <iostream>
#include <cstring>
#include <iomanip>

/*
    12_10_1 实现一些简单的类方法：
    给这个 Cow 类提供实现，并编写一个使用所有成员函数的小程序。
*/
class Cow
{
    private:
        char name[20];
        char * hobby;
        double weight;

    public:
        Cow();
        Cow(const char * nm, const char *ho, double wt);
        Cow(const Cow & cow);

        Cow & operator=(const Cow & c);

        void Show_Cow() const;

        ~Cow();
};

#endif