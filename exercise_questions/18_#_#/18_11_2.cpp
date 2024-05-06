/**
 * 在下述程序中，那些函数调用不对？为什么？
 * 
 * 对于合法的函数调用，指出其引用的参数指向的是什么？
*/

#include <iostream>

double up(double __x) { return 2.0 * __x; }

void r1(const double & __rx) { std::cout << __rx << std::endl; }
void r2(double & __rx) { std::cout << __rx << std::endl; }
void r3(double && __rx) { std::cout << __rx << std::endl; }

int main(int argc, char const *argv[])
{
    double w = 10.0;

    r1(w);      // w 为左值，函数 r1 接收一个只读左值引用，合法

    /**
     * w + 1 产生的中间值是右值，
     * 可以绑定到 r1 的参数 --- 一个只读左值引用上。
    */
    r1(w + 1); 
    r1(up(w));  // up 按值传递左值 w，返回一个右值给 r1 当参数
    r2(w);      // w 为左值，函数 r2 接收一个左值引用，合法

    /**
     * w + 1 产生的中间值是右值，
     * 而 r2 需要传入一个非 const 左值引用，语句非法。
    */
    //r2(w + 1);
    
    /**
     * up 按值传递左值 w，返回一个右值,
     * 而 r2 需要传入一个非 const 左值引用，语句非法。
    */
    //r2(up(w));
    
    /**
     * w 为左值，但 r3 需要一个非 const 右值引用，语句非法。
    */
    //r3(w);

    /**
     * w + 1 和 up() 的返回值都为右值，
     * 所以可以作为 r3 的参数，合法。
    */
    r3(w + 1);
    r3(up(w));
    
    return EXIT_SUCCESS;
}
