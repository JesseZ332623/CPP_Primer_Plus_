#include <iostream>

double up(double __x) { return 2.0 * __x; }

void r1(const double & __rx) { std::cout << "const double & __rx" << std::endl; }

void r1(double && __rx) { std::cout << "doubel && __rx" << std::endl; }

int main(int argc, char const *argv[])
{
    double w = 10;

    r1(w);

    /**
     * w + 1 返回一个右值，匹配的最佳重载函数是：
     * 
     * void r1(double && __rx) { std::cout << "doubel && __rx" << std::endl; }
    */
    r1(w + 1);

    /**
     * 同上，up() 的返回值是一个右值，匹配的最佳重载函数也是：
     * 
     * void r1(double && __rx) { std::cout << "doubel && __rx" << std::endl; }
    */
    r1(up(w));
    
    return EXIT_SUCCESS;
}
