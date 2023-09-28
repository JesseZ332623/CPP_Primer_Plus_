#include "./_Stack.h"
#include <cstdlib>
#include <ctime>

int main(int argc, char const *argv[])
{
    std::srand(std::time(0));
    std::ofstream file("skt_1_dat.txt");

    _Stack stk_1(10);
    _Stack skt_2;
    Item _dat[10] = {0};
    
    for (int index = 0; index < 10; ++index)
    {
        stk_1.push(rand() % 15 + 1);
    }

    skt_2 = stk_1;

    std::cout << "stk_1 contence: \n";
    std::cout << stk_1;

    std::cout << "stk_2 contence: \n";
    std::cout << skt_2;

    std::cout << "the _dat contence: \n";
    for (int index = 0; index < 10; ++index)
    {
        stk_1.pop(_dat[index]);
        std::cout << _dat[index] << '\t';
    }


    file << stk_1;

    file.close();

    return EXIT_SUCCESS;
}
