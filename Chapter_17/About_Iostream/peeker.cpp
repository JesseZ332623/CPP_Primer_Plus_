#include <MyLib/myLogerDef.h>

using namespace MyLib::MyLoger;

int main(int argc, char const *argv[])
{
    char ch;

    NOTIFY_LOG("Enter a string use '#' to end mark:\n");

    while (std::cin.get(ch))
    {
        if ( ch != '#' ) { std::cout << ch; }
        else 
        {
            /**
             * putback() 方法把指定字符放回标准输入流之中。
            */
            std::cin.putback(ch);
            break;
        }
    }

    /**
     * 显然，标准输入流从理论角度来说是无限长的，
     * 因此 std::cin.eof() 的返回值不太可能为 true
    */
    if (!std::cin.eof()) 
    {
        std::cin.get(ch);
        loger(std::cout, NOTIFY, "\n[", ch, "] is next input character.\n");
    }
    else
    {
        ERROR_LOG("End of file reached.\n");
        std::exit(EXIT_SUCCESS);
    }

    /**
     * peek() 方法用于查看输入流中的下一个字符并返回，
     * 此处用于判断输入流中的下一个字符是否为 '#'，来觉得何时终止输入。
    */
    while(std::cin.peek() != '#')
    {
        std::cin.get(ch);
        std::cout << ch;
    }

    if (!std::cin.eof()) 
    {
        std::cin.get(ch);
        loger(std::cout, NOTIFY, "\n[", ch, "] is next input character.\n");
    }
    else
        ERROR_LOG("End of file reached.\n");

    DONE
    return EXIT_SUCCESS;
}
