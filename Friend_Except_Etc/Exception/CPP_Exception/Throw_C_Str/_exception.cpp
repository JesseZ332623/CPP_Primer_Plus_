/**
 * C++ 异常是对程序运行过程中发生的异常情况（例如除数为 0，解引用空指针等）的一种响应（Response）。
 * 异常提供了将控制权从程序的一个部分传递到另一个部分的途径。
 * 
 * 对异常的处理有 3 个组成部分：
 * 
 *      1.引发异常      2.使用处理程序捕获异常      3.使用 try 块
 * 
 * throw 关键字表示引发异常（实际上是跳转，即命令程序跳转到另一条语句），其语法为：
 *  
 *      throw string | object;
 * 
 * 紧随其后的值表示了异常的特征。
 * 
 * try 块标识特定的异常可能被激活的代码块，它后面紧跟 catch 块，用于报告异常和进行后续的处理，三者的语法大致如下：
 * 
 * void function()
 * {
 *      exception happen:
 *          throw "error describe" | exception_object
 * }
 * 
 * int main()
 * {
 *      try
 *      {
 *          function();
 *      }
 *      catch(const char *_except | std::exception _except)
 *      {
 *          std::cout << _except | _except.what() << '\n';
 *          
 *          Subsequent processing.......            
 *      }
 *      
 *      return EXIT_SUCCESS;
 * }
*/

#include <iostream>

double h_mean(double _a, double _b);

double h_mean(double _a, double _b)
{
    /*
        如果出现 a = -b 的情况，就抛出异常,
        如果这个函数在 try 块内，程序直接跳转到 catch 块部分进行报告和处理。
    */
    if (_a == -_b)
    {
        throw "bad h_mean(), arguments a = -b not allowed.";
    }

    /*如果没有问题，则计算调和平均数并返回。*/
    return 2.0 * _a * _b / (_a + _b);
}

int main(int argc, char const *argv[])
{
    double x, y, z = 0;

    printf("Enter two numbers: ");

    while (std::cin >> x >> y)
    {
        /*
            try 块标识特定的异常可能被激活的代码块，
            如果出现异常 throw 后就跳转至 catch 块。
        */
        try
        {
            z = h_mean(x, y);
        }
        catch (const char *_except) //catch 接收 throw 抛出的字符串或对象
        {
            printf("%s\n", _except);        /*输出错误信息*/

            printf("Enter new number set <Enter q to quit>: ");     /*后续处理*/
            continue;
        }
        printf("Harmonic mean of %lf and %lf is: %lf\n", x, y, z);

        printf("Enter next number set <Enter q to quit>: ");
    }

    while (std::getchar() != '\n') { continue; }

    printf("Done.");

    return EXIT_SUCCESS;
}

/**
 * 从上面可以看出，异常执行的流程如下：
 * 
 *      1.程序在 try 块中调用 h_mean()。
 * 
 *      2.h_mean() 引发异常，从而执行 catch 块，
 *      并将 throw 关键字抛出的字符串赋值给 const char *_except 。
 * 
 *      3.catch 块返回到 while 循环的开始位置。
*/