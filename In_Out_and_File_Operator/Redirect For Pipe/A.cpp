#include <iostream>

/*
    在 C/C++ 的 I/O 操作中，我们很好理解 标准输入，标准输出，文件三者之间的 I/O 操作，
    但是却很难理解程序与程序之间的 I/O 操作。

    在操作系统中，程序与程序之间的数据传递可以使用管道（Pipe）来实现。

    只需要运行时在两个程序间加一个 | 来重定向一个程序的标准输出到另一个程序的标准输入。

    如 > .\A.exe | .\B.exe  # 将程序 A 的程序的标准输出重定向到程序 B 的标准输入
*/

int main(int argc, char const *argv[])
{
    /*往标准输出输出一个字符串*/
    std::fprintf(stdout, "Send Some Messege to B.");
    
    return EXIT_SUCCESS;
}
