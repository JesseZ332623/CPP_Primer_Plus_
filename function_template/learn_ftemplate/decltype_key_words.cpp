#include <iostream>

/*decltype_key_words.cpp*/
/*
    声明两个泛型参数，使用这两个泛型进行赋值操作时，
    新的变量的类型是不确定的，所以就需要decltype关键字（C++ 11）
    来确定变量的类型.

    decltype关键字是C++11引入的一个新特性，用于自动推断变量的类型。
    它可以帮助我们避免显式地指定类型，从而提高代码的可读性和可维护性。
    decltype的工作原理是，它会根据变量或表达式的类型推导出相应的类型，并返回一个类型对象。
*/


template <typename Type_1, typename Type_2>
auto ft(Type_1 t1, Type_2 t2);

template <typename Type_1, typename Type_2>
auto gt(Type_1 x, Type_2 y) -> decltype(x + y);

template <typename Type_1, typename Type_2>
auto ft(Type_1 t1, Type_2 t2) 
{
    decltype(t1 + t1) re = t1 + t2;

    return re;
}

template <typename Type_1, typename Type_2>
auto gt(Type_1 x, Type_2 y) -> decltype(x + y)
{
    return x * y;
}

int main(int argc, char const *argv[])
{
    std::cout << gt(21, 10.87);
    return EXIT_SUCCESS;
}
