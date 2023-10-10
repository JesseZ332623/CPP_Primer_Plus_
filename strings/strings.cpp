#include <iostream>
#include <string>
#include <cstring>
#include <array>

int replace(char *str, char ch_1, char ch_2);

int replace(char *str, char ch_1, char ch_2)
{
    int replace_time = 0;
    int str_len = strlen(str);
    for (int i = 0; i < str_len; ++i)
    {
        if (*(str + i) == ch_1)
        {
            *(str + i) = ch_2;
            ++replace_time;
        }
    }
    if (!replace_time)
    {
        std::cout << "Traget charset NOT FOUND....\n";
        return -1;
    }

    return replace_time;
}

int main(int argc, char const *argv[])
{
    char str_1[] = {"E:/CPP_Primire_Plus/strings"};    
    char *s_ptr = (char *)std::memmove(s_ptr, str_1, std::strlen(str_1) + 1);

    std::cout << s_ptr << std::endl;
    std::cout << str_1 << '\n';

    return EXIT_SUCCESS;
}
