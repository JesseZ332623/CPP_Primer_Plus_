/**
 * 通常，引发异常的函数将传递一个对象。
 * 这样做的优点是，可以使用不同的异常类型来区分不同的函数在不同的情况下引发的异常。
 * 
 * 此外，对象可以携带信息，程序员可以根据这些信息来确定引发异常的原因。
 * 同时，catch 块可以根据这些信息来决定采取什么样的措施。
*/

#ifndef __EXCEPT_CLASS_H_
#define __EXCEPT_CLASS_H_

#include <iostream>

/*为 h_mean 和 g_mean 函数编写异常类*/

class Bad_H_Mean
{
    private:
        double _v1;
        double _v2;

    public:
        /*构建函数，传入错误参数*/
        Bad_H_Mean(double _a = 0, double _b = 0) : _v1(_a), _v2(_a) {}

        /*message 负责报告问题所在*/
        void message();
};

inline void Bad_H_Mean::message()
{
    printf("h_mean(%lf, %lf): Invalid argument: a = -b\n", _v1, _v2);
}

class Bad_G_Mean
{
    public:
        double _v1;
        double _v2;

        /*构建函数，传入错误参数*/
        Bad_G_Mean(double _a = 0, double _b = 0) : _v1(_a), _v2(_b) {}

        /*message 负责报告问题所在，但这个函数返回字符串，所以实现会有所不同*/
        const char * message();
};

inline const char * Bad_G_Mean::message()
{
    return "g_mean() arguments should >= 0\n";
}

#endif