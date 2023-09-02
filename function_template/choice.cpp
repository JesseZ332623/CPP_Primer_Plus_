#include <iostream>

template <typename Type>
Type lesser(Type a, Type b)
{
    return a < b ? a : b;
}

int lesser(int a, int b)
{
    a = a < 0 ? -a : a;
    b = b < 0 ? -b : b;

    return a < b ? a : b;
}
int main(int argc, char const *argv[])
{
    double x = 15.35, y = 100.77;
    std::cout << lesser(-10, 21) << std::endl;
    std::cout << lesser(x, y) << std::endl;
    std::cout << lesser<int>(x, y) << std::endl;

    return EXIT_SUCCESS;
}
