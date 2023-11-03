#include "./tp_stack.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

const int NUM = 10;

const char * file_set[NUM] = 
{
    "1: Hank Gilgamesh", "2: Kiki Ishtar",
    "3: Betty Rocker", "4: Ian Flagranti",
    "5: Wolfgang Kibble", "6: Portial Koop",
    "7: Joy Almondo", "8: Xaverie Paprika",
    "9: Juan Moore", "10: Misha Mache"
};

int main(int argc, char const *argv[])
{  
    std::srand(std::time(NULL));

    int stack_size = 0;

    /*输入栈大小*/
    std::cout << "Please Enter Stack Size: ";
    std::cin >> stack_size;

    /*根据栈大小创建栈*/
    Stack<const char *> in_basket(stack_size);

    const char *out_basket[NUM];

    int processed = 0;
    int next_in = 0;

    while (processed < NUM)
    {
        if (in_basket.isempty()) { in_basket.push(file_set[next_in++]); }

        else if (in_basket.isfull()) { in_basket.pop(out_basket[processed++]); }

        else if (std::rand() % 2 && next_in < NUM) { in_basket.push(file_set[next_in++]); }

        else { in_basket.pop(out_basket[processed++]); }
    }

    for (int index = 0; index < NUM; ++index)
    {
        std::cout << out_basket[index] << std::endl;
    }

    std::cout << "Bye\n";

    return EXIT_SUCCESS;
}
