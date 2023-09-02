#include <iostream>
#include <cstring>

/*
    C++ 新特性：函数重载
    通过使用不同的参数列表来实现函数的重载。
    编译器会更具上下文来识别。
*/

/*显示字符串函数的重载*/
void show_string(const char *str);
void show_string(const char *str, int len);

/*显示数字位数函数的重载*/
unsigned long show_digit(unsigned long num, unsigned int ct);

void show_string(const char *str)
{
    std::cout << str << std::endl;
}

void show_string(const char *str, int len)
{
    if (len > strlen(str))
    {
        return;
    }
    for (int index = 0; index < len; ++index)
    {
        std::cout << str[index];
    }

    std::cout.put('\n');
}

unsigned long show_digit(unsigned long num, unsigned int ct)
{
    unsigned int digit = 1;
    unsigned long n = num;

    if (ct == 0 || num == 0)
    {
        return 0;
    }
    while (n /= 10)
    {
        digit++;
    }
    if (digit > ct)
    {
        ct = digit - ct;
        while (ct--)
        {
            num /= 10;
        }
        return num;
    }
    else
    {
        return num;
    }
}

int main(int argc, char const *argv[])
{
    char str[10] = {"aaaabbbbc"};

    // show_string(str);

    // show_string(str, 5);

    std::cout << show_digit(123456789, 7) << std::endl;

    return EXIT_SUCCESS;
}
