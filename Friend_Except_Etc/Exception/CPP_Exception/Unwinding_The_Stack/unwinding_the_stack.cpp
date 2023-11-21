/**
 * 假设 try 块没有调用引发异常的函数，而是调用了 “对引发异常的函数进行调用的函数”，
 * 则程序流程将从引发异常的函数跳转到包含 try 块和处理程序的函数，这涉及到（栈解退 Unwinding The Stack）的操作。
 * 
 * 首先，回顾一下 C++ 是如何处理函数调用和返回的：
 * C++ 通过将信息放在栈（Stack）中来处理函数调用。程序将调用函数的指令的地址（返回地址）放到栈中。
 * 当被调用的函数执行完毕后，程序将使用该地址来确定从哪里开始继续执行。假设有这样的代码：
 * 
 * int function(int _value) 
 * {
 *      .....
 *      
 *      return result;
 * }
 * 
 * 
 * int main(int argc, char const *argv[])
 * {
 *      int ans = function(102);
 * 
 *      return 0;
 * }
 * 
 * 它的执行流程是：
 * 
 * 1.调用 main 函数，这是整个程序的入口。
 * 2.创建整型变量 ans，并初始化默认值为 0。
 * 3.调用 function 函数，传入常量 102。
 * 4.在调用 function 函数时，将赋值运算符 = 的地址入栈，作为函数的返回地址。
 * 5.跳转执行 function 函数。
 * 6.function 执行完 return 语句后，返回一个结果存储到 ans 中，随后出栈，跳转回 main 函数中的返回地址。
 * 7.继续执行 main 函数的流程，直到该函数返回，程序才算结束。
 * 
 * 需要补充的是：
 * 1.函数调用将参数放到栈中，这些参数被视为自动变量（auto），由编译器决定其生死。
 * 2.如果函数内部创建了新的变量，其生命周期也是自动的。
 * 3.如果函数内部调用了别的函数，或者函数本身（递归），则后者的信息也会被添加到栈中（这就是为什么递归太深会爆栈的原因）以此类推，
 * 当函数内部的函数调用完成时，会销毁栈顶元素，同时返回到调用这个函数的函数处，以此类推。
 * 4.每个函数都在结束时自动释放其自动变量。如果变量是类对象，则类的析构函数将被调用。
*/

/*
    现在，假设函数由于出现异常（而非返回）而终止，则程序也将释放栈中的内存，
    但不会在栈的第一个返回地址停下，而是不断的释放，直到找到一个位于 try 块中的返回地址。
    随后，控制权将转到块尾的异常处理程序，而非函数调用后面的第一条语句。该过程被称为栈解退（Unwinding The Stack）。

    引发机制的一个非常重要的特性是，对于栈中的自动类对象，类的析构函数将被调用（和函数的返回相同）。
    然而和函数返回不同的是，函数返回仅处理该函数放在栈中的对象，
    而 throw 语句则处理 try 块 和 throw 之间整个函数调用序列放在栈中的对象。

    如果没有栈解退这种特性，引发异常后，对于中间函数调用放在栈中的自动类对象，其析构函数将不会调用。
*/

#include "./include/_except_class.h"
#include "./include/demo.h"
#include "./include/means.h"

int main(int argc, char const *argv[])
{
    using std::cout, std::cin, std::endl;

    double x, y, z;

    {
        Demo _d1("Found Block in main()");
        printf("Enter two numbers: ");

        while (scanf("%lf %lf", &x, &y))
        {
            try
            {
                z = means(x, y);
                printf("The mean mean of %lf and %lf is: %lf\n", x, y, z);
                printf("Enter the next pair: "); 
            }
            catch (Bad_H_Mean & _hg)
            {
                _hg.message();

                printf("Enter two numbers again: ");
                continue;
            }
            catch (Bad_G_Mean & _bg)
            {
                _bg.message();

                printf("Exit.\n");
                break;
            }
        }

        _d1.show();
    }
    
    while (getchar() != '\n') { continue; }
    
    printf("Done.\n");

    return 0;
}