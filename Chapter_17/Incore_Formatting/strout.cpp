
#include <MyLib/cinCheck.h>

/**
 * C++ 标准库提供的，通过 iostream 使用相同的接口，
 * 实现程序和 string 对象之间的 I/O。
*/
#include <sstream>
#include <string>
#include <algorithm>


/**
 * 读取 string 对象中的格式化信息写入或将格式化信息写入 string 对象中被称为内核格式化（Incore Formatting）。
*/

using namespace MyLib::MyLoger;
using namespace MyLib::cinCheck;

int main(int argc, char const *argv[])
{
    system("cls");

    std::ostringstream outStrStream;
    std::string hardDisk, result;
    MessageStrings messages = 
    {
        "What's it is capacity in GB? ",
        "Invalid input! Only intenger please~\n"
    };
    int capacity = 0;

    NOTIFY_LOG("What's the name of your hard disk? ");
    std::getline(std::cin, hardDisk);

    istreamInputAndCheck(std::cin, capacity, messages);

    printSplitLine(45, '-');
    loger(
            outStrStream, NOTIFY,
            "The hard disk ", hardDisk, 
            " has capacity of ", capacity, " gigabytes.\n"
        );

    result = outStrStream.str();

    std::cout << result;
    loger(
            std::cout, NOTIFY,
            "String result size = ", result.size(), '\n'
       );

    DONE
    return EXIT_SUCCESS;
}
