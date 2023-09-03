#include <iostream>
#include <cstring>

struct Stringy
{
    char *str;
    int str_len;
};

const Stringy &set(Stringy &str_gy, const char *str);

/*Function OverLoading....*/
void show(const char *str);                 //#1
void show(const char *str, int str_no);     //#2
void show(const Stringy &str_gy);           //#3
void show(const Stringy &str_gy, int str_no); //#4

const Stringy &set(Stringy &str_gy, const char *str)
{
    strcpy(str_gy.str, str);
    str_gy.str_len = strlen(str);

    return str_gy;
}

void show(const char *str)
{
    std::cout << str << '\n';
}

void show(const char *str, int str_no)
{
    std::cout << str[str_no] << '\n';
}

void show(const Stringy &str_gy)
{
    std::cout << str_gy.str << '\n';
}

void show(const Stringy &str_gy, int str_no)
{
    if (str_no > str_gy.str_len)
    {
        return;
    }

    std::cout << str_gy.str[str_no] << std::endl;
}

int main(int argc, char const *argv[])
{
    Stringy str_gy;
    char testing[] = {"Reality isn't what it used to be"};
    
    set(str_gy, testing);

    show(str_gy);
    show(str_gy, 5);
    show(testing);
    show(testing, 0);

  
    return EXIT_SUCCESS;
}