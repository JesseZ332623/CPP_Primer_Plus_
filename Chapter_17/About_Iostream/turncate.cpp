#include <MyLib/myLogerDef.h>

const int STRING_LENGTH_LIMIT = 10;

using namespace MyLib::MyLoger;

/**
 * @brief C++ 标准 I/O 经典操作，处理掉输入缓冲区中剩余的，换行符之前的字符流。
*/
inline void eatLine(void) { while (std::cin.get() != '\n') { continue; } }

void showInfo(const char * __name, const char * __title);

int main(int argc, char const *argv[])
{
    std::system("cls");

    char name[STRING_LENGTH_LIMIT];
    char title[STRING_LENGTH_LIMIT];

    NOTIFY_LOG("Enter you name (not over 10 words): ");
    std::cin.get(name, STRING_LENGTH_LIMIT);

    if (std::cin.peek() != '\n')
    {
        WARNING_LOG("Sorry only support 10 words for your name...\n");
    }

    eatLine();

    loger(std::cout, NOTIFY, "Dear ", name, ", Enter your title:\n");
    std::cin.get(title, STRING_LENGTH_LIMIT);

    if (std::cin.peek() != '\n')
    {
        WARNING_LOG("Sorry only support 10 words for your title...\n");
    }

    showInfo(name, title);

    DONE

    return EXIT_SUCCESS;
}

void showInfo(const char * __name, const char * __title)
{
    loger(std::cout, CORRECT, "Name: ", __name, "\tTitle: ", __title, "\n");
}