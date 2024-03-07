#include "./include/RTTI_1.h"
#include <typeinfo>

int main(int argc, char const *argv[])
{
    Grand grand(114514);
    Superb superb;

    Grand & grandRef = grand;

    /*
        也可以将 dynamic_cast<> 运算符用作引用类型的转换，
        但由于没有空指针对应的引用值，因此若出现失败的类型转换，
        则会抛出 std::bad_cast 异常，该异常类派生自 exception 类
    */
    try
    {
        Superb & rs = dynamic_cast<Superb &>(grandRef);
    }
    catch (const std::bad_cast & failedTypeCast)
    {
        std::cout << failedTypeCast.what() << '\n';
    }

    return EXIT_SUCCESS;
}
