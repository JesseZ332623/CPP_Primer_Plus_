#include <iostream>
#include <cstring>

#define C_STYLE_STRING_INPUT false
#define STD_STRING_INPUT false

/*
    这个宏用于跳过标准输入中的换行符
*/
#define REMOVE_NEWLINE_IN_STDIN while(std::getchar() != '\n') { continue; }

int main(int argc, char const *argv[])
{
    using std::cin, std::cout, std::endl, std::string;

/*
    对于 C 风格字符串，标准库提供以下 3 种输入方式
*/
#if C_STYLE_STRING_INPUT
    char info[100] = {"0"};

    cin >> info;                    // #1 仅从标准输入读取一个字符，遇到空格或换行符就停止了
    cout << info << endl;
    std::memset(info, 0, 100);

    REMOVE_NEWLINE_IN_STDIN

    cin.get(info, 100);              // #2 从标准输入读取指定数目的字符，会遗留换行符在标准输入中
    cout << info << endl;
    std::memset(info, 0, 100);

    REMOVE_NEWLINE_IN_STDIN

    cin.getline(info, 100);          // #3 从标准输入读取指定数目的字符，丢弃换行符
    cout << info << endl;
    std::memset(info, 0, 100);
#endif

/*
    对于 std::string 则有以下 2 种输入方式：
*/
#if STD_STRING_INPUT

    string currentTime;
    cout << "Enter current local time: \n";
    cin >> currentTime;                         // #1 从标准输入读取一行，遇到空格或换行符就停止了

    REMOVE_NEWLINE_IN_STDIN

    cout << currentTime << endl;

    cout << "Enter current local time: \n";
    std::getline(cin, currentTime);             // #2 从标准输入读取一行，会保留空格和换行符

    cout << currentTime << endl;

#endif

    return EXIT_SUCCESS;
}
