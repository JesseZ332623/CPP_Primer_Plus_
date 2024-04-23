#include <iostream>
#include <string>
#include <exception>

/*
    头文件 <iostream> 掌管 C++ 的标准输出和标准输入（通常是从键盘到屏幕），可以分为以下 8 个 对象：

    1. std::cin 与 std::wcin 用于标准输入流，wcin 用于处理 wchar_t（宽字符） 类型

    2. std::cout 与 std::wcout 用于标准输出流，wcout 用于处理 wchar_t（宽字符） 类型

    3. std::cout 与 std::wcerr 用于处理标准错误流，但这两个流没有被缓冲，也就是不结果缓冲区，直接发送给标准错误流（通常是屏幕），wcerr 用于处理 wchar_t（宽字符） 类型

    4. std::clog 与 std::wclog 和 （3） 一样，也处理标准错误流，但是没有 （3） 那么紧急，需要经过缓冲区再发送给屏幕


    一些 I/O 类的派生关系如下：

    ios 类派生出 ostream istream 和 streambuf 类，前两者用于标准输入输出，而 streambuf 类用于管理 I/O 缓冲区的内存

    ostream 和 istream 两个类派生出 iostream 类，它同时具有输入和输出的功能。
*/

int main(int argc, char const *argv[])
{
    /*
        奇怪的是，我好像用不了 std::w### 的标准输入输出流
    */
    std::cout << "out put to screen(default).\n";

    int number = 0;
    std::cin >> number;

    std::cout << "The number is: " << number << std::endl;

    /*
        clog 通常输出程序的运行状况
    */
    try
    {
        std::clog << "Load #.jpg \n";

        /*故意抛一个运行时错误*/
        throw std::runtime_error("Load image failed....");
    }
    catch (const std::exception & _e)
    {
        /*
            而 cerr 通常输出程序的错误信息
        */
        std::cerr << "opps! Something is wrong!" << std::endl;
        std::cerr << _e.what() << std::endl;
    }

    
    return 0;
}
