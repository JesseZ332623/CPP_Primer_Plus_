#include <iostream>
#include <cstring>

/*
    C++ 新特性：函数默认值
    可以在声明函数的时候设置默认值，如果调用函数没有传入那个参数，那么就按默认值来。
*/
char *left_str(char *str, int len = 4);

char *left_str(char *str, int len)
{
    if (len < 0)
    {
        return nullptr;
    }
    
    char *left_string = new char[len + 1];
    int index = 0;

    for (index = 0; index < len && str[index]; ++index)     /*判断条件：索引值小于传入长度 并且 不超出传入字符串的长度*/
    {
        left_string[index] = str[index];
    }
    while (index <= len)
    {
        str[index++] = '\0';
    }
    
    return left_string;
}

int main(int argc, char const *argv[])
{
    char *new_str = new char[30];

    strcpy(new_str, "This is a test string......");

    std::cout << left_str(new_str, 15) << std::endl;

    delete new_str;

    return EXIT_SUCCESS;
}
