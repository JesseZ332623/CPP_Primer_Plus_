#include <iostream>
#include <exception>

#include <MyLib/myLogerDef.h>

using namespace MyLib::MyLoger;

int main(int argc, char const *argv[])
{
    /*
        设置 std::ios_base::failbit 
        在引发 std::ios_base::failure 异常时抛出
    */
    std::cin.exceptions(std::ios_base::failbit);

    std::cout << "Enter numbers: ";
    int sum = 0;
    int input;

    try
    {
        while (std::cin >> input)
        {
            sum += input;
        }
    }
    catch(const std::ios_base::failure & __failExcept)
    {
        ERROR_LOG(__failExcept.what());
    }
    
    loger(std::cout, NOTIFY, "The last value entered = ", input, '\n');
    loger(std::cout, NOTIFY, "Sum = ", sum, '\n');

    DONE

    return EXIT_SUCCESS;
}