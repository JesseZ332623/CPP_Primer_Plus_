#include <iostream>
#include <cfloat>

bool h_mean(double _a, double _b, double * _ans);

bool h_mean(double _a, double _b, double * _ans)
{
    // 如果传入 10，-10，那么将计算 2.0 * 10 * (-10) / (10 + (-10))
    //这会造成除数为 0 的情况，得出的结果无意义
    if (_a == -_b)
    {
        *_ans = DBL_MAX;    /*DBL_MAX 宏 是 double 类型的最大值，在这个程序中被当成错误码使用*/

        return false;
    }

    /*计算调和平均数*/
    *_ans = 2.0 * _a * _b / (_a + _b);

    return true;
}

int main(int argc, char const *argv[])
{
    double x, y, z;

    printf("Enter two numbers: ");

    while (std::cin >> x >> y)
    {
        if(h_mean(x, y, &z))
        {
            printf("Harmonic mean of %lf and %lf is: %lf\n", x, y, z);
        }
        else
        {
            printf("One Value should not be the negative of the other - try again.\n");
        }   

        printf("Enter next number set <Enter q to quit>: ");
    }

    while (std::getchar() != '\n') { continue; }

    printf("Done.");

    return EXIT_SUCCESS;
}
