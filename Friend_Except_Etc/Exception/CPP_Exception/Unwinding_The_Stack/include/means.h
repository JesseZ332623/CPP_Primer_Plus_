#include "./def.h"
#include "./demo.h"
#include "./_except_class.h"

/**
 * 求 a 和 b 的调和平均数
 * 
 * @param _a number a
 * @param _b number b
 * 
 * @return harmonic mean
*/
double h_mean(double _a, double _b);

/**
 * 求 a * b 的 平方根
 * 
 * @param _a number a
 * @param _b number b
 * 
 * @return square root
*/
double g_mean(double _a, double _b);

/*调用 h_mean 和 g_mean 并计算结果*/
double means(double _x, double _y);

double h_mean(double _a, double _b)
{
    /*若检查到错误入参，便抛出 Bad_H_Mean 异常类*/
    if (_a == -_b) 
    {
        throw Bad_H_Mean(_a, _b);
    }

    return 2.0 * _a * _b / (_a + _b);
}

double g_mean(double _a, double _b)
{
    /*若检查到错误入参，便抛出 Bad_G_Mean 异常类*/
    if (_a < 0 || _b < 0)
    {
        throw Bad_G_Mean(_a, _b);
    }

    return std::sqrt(_a * _b);
}

double means(double _x, double _y)
{
    double am, hm, gm;

    Demo _d2("Found in means()");

    am = (_x + _y) / 2.0;       /*计算入参的算术平均数*/

    try
    {
        hm = h_mean(_x, _y);
        gm = g_mean(_x, _y);
    }
    catch (Bad_H_Mean & _bg)
    {
        _bg.message();
        printf("Caught in means()\n");
        throw;
    }
    _d2.show();

    return (am + hm + gm) / 3;
}