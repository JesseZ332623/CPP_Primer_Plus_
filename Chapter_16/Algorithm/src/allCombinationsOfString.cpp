
#include <MyLib/myLogDef.h>
#include <string>
#include <algorithm>

#define LINUX false
#define WINDOWS_X86 true

/**
 * 程序的目标很简单，从标准输入中读取数据到字符串，
 * 然后通过 next_permutation() 算法计算该字符串所有排列组合的可能。
 * 
 * 由于稍微长一点的字符串的排列组合数量都会非常大，
 * 就没有必要使用 delay() 来浪费时间了。
*/

int main(int argc, char const *argv[])
{
    using namespace MyLib::MyLog;

#if LINUX
    system("clear");

#elif WINDOWS_X86
    system("cls");

#endif

    std::string letterString;
    std::size_t combinationAmount = 1L;

    log(std::cout, NOTIFY, "Please enter the new letter: \n");
    
    while (std::getline(std::cin, letterString) && letterString != ".quit")
    {
        system("cls");
        
        log(std::cout, CORRECT, "Permutations of ", letterString, " is: \n");
        std::sort(letterString.begin(), letterString.end());

        log(std::cout, ORIGINAL, letterString, '\t');

        while (std::next_permutation(letterString.begin(), letterString.end()))
        {
            log(std::cout, ORIGINAL, letterString, '\t');
            ++combinationAmount;

            if ((combinationAmount - 1) % 5 == 4) { log(std::cout, ORIGINAL, '\n'); }
        }
        log(std::cout, CORRECT, "\nCombination Amount = ", combinationAmount, '\n');

        log(std::cout, NOTIFY, "\nEnter Next String: \n");

        combinationAmount = 1L;
    }

    log(std::cout, CORRECT, "Done.\n");

    return EXIT_SUCCESS;
}
