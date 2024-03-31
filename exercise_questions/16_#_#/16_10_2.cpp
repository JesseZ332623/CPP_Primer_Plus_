#include <MyLib/myLogDef.h>

#include <cctype>
#include <csignal>
#include <limits>
#include <algorithm>

/**
 * @brief 强行结束程序需要清理 I/O 流，所以需要重设 CTRL + C 的行为。
*/
void endBehaviorHandle(int __signalIndex);

/**
 * @brief 判断传入字符是否为处数字字符和字母字符之外的字符（标点符号）
*/
bool isInterpunction(const unsigned char __ch);

void endBehaviorHandle(int __signalIndex)
{
    switch(__signalIndex)
    {
        case SIGINT:
            /*
                做梦都没想到，signal 库居然不适配 C++ 标准 I/O，
                换成 C 标准 I/O，一切都解决了。。
            */
            printf("\033[38;5;1mForcefully ending.\033[38;5;7m\n");
            std::exit(EXIT_SUCCESS);
            break;

        default:
            break;
    }
}

bool isInterpunction(const unsigned char __ch)
{
    if (std::isalnum(__ch) || std::isalpha(__ch)) { return false; }

    return true;
}

/**
 * @brief 老题目，判断一个字符串是否为回文，但这次要活用 STL 算法。
 * 
 * @param __str 一个字符串的拷贝
 * 
 * @return 一个 bool 类型，表面是不是回文字符串
*/
bool isPalindromeString(std::string & __str);

bool isPalindromeString(std::string & __str)
{
    using namespace MyLib::MyLog;
    /*
        对字符串做两方面处理：
        1. 全部转成小写
        2. 处理掉所有标点符号
    */
    std::transform(
                    __str.cbegin(), __str.cend(), __str.begin(), 
                    [] (unsigned char n) { return std::tolower(n); }
                  );

    while (true)
    {
        std::string::iterator interpunctionIter = \
        std::find_if(
                        __str.begin(), __str.end(), 
                        [](const unsigned char __ch) -> bool { return isInterpunction(__ch); }
                    );

        if (interpunctionIter == __str.end()) { break; }

        __str.erase(interpunctionIter);  
    }

    /*
        当经过上述两步处理后，字符串长度为 0，
        很可能意味着用户只输入了标点符号，或者非法输入，所有也要返回 false
    */
    if (__str.size() == 0) 
    {
        log(std::cout, WARNING, "Invald Input!\n");
        return false;
    }

    std::string reverseString; reverseString.resize(__str.size());
    std::reverse_copy(__str.cbegin(), __str.cend(), reverseString.begin());

    if (__str == reverseString) { return true; }

    return false;
}

int main(int argc, char const *argv[])
{
    using namespace MyLib::MyLog;

    system("cls");

    /*
        注册信号函数，指定 CTRL + C 的行为。
    */
    std::signal(SIGINT, endBehaviorHandle);

    log(std::cout, NOTIFY, "This Program Check The String You Input Is PalindromeString or Not.\n");
    
    std::string userInput;

    log(std::cout, NOTIFY, "Please enter something: ");

    while (std::getline(std::cin, userInput) && (userInput != ".quit"))
    {
        if (isPalindromeString(userInput))
        {
            log(std::cout, CORRECT, "String: [", userInput, "] is PalindromeString!\n");
        }
        else
        {
            log(std::cout, WARNING, "String: [", userInput, "] is not a PalindromeString!\n");
        }

        log(std::cout, NOTIFY, "Please enter something again: \n");
    }

    log(std::cout, CORRECT, "Done.\n");

    return EXIT_SUCCESS;
}
