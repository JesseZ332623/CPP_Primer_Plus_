#include <iostream>
#include <cstdlib>

/*本文件主要了解 std::abort 函数的用法*/

double h_mean(int a, int b);

double h_mean(int a, int b)
{
    if (a == -b)
    {
        printf("untenable arguments to h_mean function.\n");

        /**
         * abort()  函数用于强行终止程序，它的典型实现是：
         * 向标准错误（stderr）发送消息：abnormal program termination（程序异常终止）。
         * 随后终止程序。它还返回一个随实现而异的值，告诉操作系统或者父进程，处理失败。
         * 
         * 至于 abort() 函数刷不刷新文件缓冲区，取决于实现。
        */
        std::abort();
    }

    return 2.0 * a * b / (a + b);
}

int main(int argc, char const *argv[])
{
    int x, y, z;

    printf("Enter two numbers: ");

    while (std::cin >> x >> y)
    {
        z = h_mean(x, y);

        printf("Harmonic mean of %d and %d is: %d\n", x, y, z);

        printf("Enter next number set <Enter q to quit>: ");
    }

    printf("Done.");

    return EXIT_SUCCESS;
}
