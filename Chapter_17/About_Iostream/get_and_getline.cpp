#include <MyLib/myLogerDef.h>

#include <limits>
#include <cstring>

const int STRING_LENGTH_LIMIT = 256;

int main(int argc, char const *argv[])
{
    using namespace MyLib::MyLoger;

    system("cls");

    char inputStr[STRING_LENGTH_LIMIT];

    loger(std::cout, NOTIFY, "Enter a string for a std::cin.getline() processing:\n");

    /**
     * 从标准输入读取字符流到长度为 STRING_LENGTH_LIMIT 的字符串 inputStr，
     * 以 '#' 为结束标志，且丢弃 '#' 字符
    */
    std::cin.getline(inputStr, STRING_LENGTH_LIMIT, '#');

    loger(std::cout, CORRECT, "Here is your input: [", inputStr, "] ", "Length = ", std::strlen(inputStr), '\n');
    printSplitLine(45, '-');

    char ch;

    /**
     * 读取输入流中 '#' 字符后的一个字符给 ch
    */
    std::cin.get(ch);
    loger(std::cout, NOTIFY, "The next input character is: ", ch, '\n');
    printSplitLine(45, '-');
    
    /**
     * 读取完毕后，如果 ch 不是换行符，
     * 那么就清除输入流中直到下一个换行符前的所有字符，准备下一次新的输入
    */
    if (ch != '\n') { std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); }
    std::memset(inputStr, 0, std::strlen(inputStr));


    loger(std::cout, NOTIFY, "Enter a string for a std::cin.get() processing:\n");

    /**
     * `std::istream &std::istream::get(char *__s, std::streamsize __n, char __delim)` 和 
     * `template<> std::istream &std::istream::getline(char *__s, std::streamsize __n, char __delim)`
     * 的区别在于：前者会丢弃 __delim 字符而后者不会。
    */
    std::cin.get(inputStr, STRING_LENGTH_LIMIT, '#');
    loger(std::cout, CORRECT, "Here is your input: [", inputStr, "] ", "Length = ", std::strlen(inputStr), '\n');

    std::cin.get(ch);
    loger(std::cout, CORRECT, "The next input character is: ", ch, '\n');
    printSplitLine(45, '-');

    DONE

    return EXIT_SUCCESS;
}
