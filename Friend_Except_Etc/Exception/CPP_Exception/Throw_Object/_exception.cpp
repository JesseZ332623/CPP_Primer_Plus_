#include "./_except_class.h"
#include <cmath>

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

int main(int argc, char const *argv[])
{
    double x, y, z;

    printf("Enter two number: ");

    while (scanf("%lf %lf", &x, &y))
    {
        /*
            try 块标识特定的异常可能被激活的代码块，
            如果出现异常 throw 后就跳转至 catch 块。
        */
        try
        {
            z = h_mean(x, y);
            printf("The Harmonic Mean of %lf ,%lf is: %lf\n", x, y, z);
            printf("The Squart Root of %lf, %lf is: %lf\n", x, y, g_mean(x, y));

            printf("Enter two number: <press q to quit>: ");
        }
        /*
            catch 接收 俩函数中因错误入参而抛出的 h_except 和 g_except 对象，
            然后在块中显示错误信息和后续的处理。

            try catch 的组合类似于 if else，可以允许这样的语法：

            try {...}
            catch(...) {....}
            catch(...) {....}
        */
        catch (Bad_H_Mean & h_except)
        {
            h_except.message();
            printf("Enter two number: <press q to quit>: ");
            continue;
        }
        catch (Bad_G_Mean & g_except)
        {
            printf("%s", g_except.message());

            printf("Exit.....\n");

            break;
        }
    }

    while (getchar() != '\n') { continue; }

    puts("Done...");
    
    return EXIT_SUCCESS;
}
