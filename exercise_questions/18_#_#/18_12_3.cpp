/**
 * 编写并测试可变参数模板函数 sumValue()，
 * 它接受任意长度的参数列表（可以是数值，也可以是除数值外的类型），
 * 并以 long double 类型返回这些数值的和。
*/

#include <MyLib/myLogerDef.h>

template <typename ... __args>
long double sumValue(__args ... __argument);

int main(int argc, char const *argv[])
{
    using namespace MyLib::MyLoger;

    CORRECT_LOG(sumValue(1, 2, 3, 'a'));
    return 0;
}

template <typename ... __args>
long double sumValue(__args ... __argument)
{
    long double result = 0;

    (result += ... += __argument);

    return result;
}