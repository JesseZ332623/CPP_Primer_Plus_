#include <initializer_list>
#include <stdexcept>

#include <MyLib/myLib.h>

using namespace MyLib::MyLoger;

double sum(std::initializer_list<double> __numList);
double everage(std::initializer_list<double> __numList);

int main(int argc, char const *argv[])
{
    std::system("cls");
    
    try
    {
        loger(std::cout, ORIGINAL, "List 1: 2 + 3 + 4 = ", sum({2, 3, 4}), '\n');
        loger(std::cout, ORIGINAL, "List 1: (2 + 3 + 4) / 3 = ", everage({2, 3, 4}), '\n');

        std::initializer_list<double> dl = {1.1, 2.2, 3.3, 4.4, 5.5};

        loger(std::cout, ORIGINAL, "List dl: 1.1 + 2.2 + 3.3 + 4.4 + 5.5 = ", sum(dl), '\n');

        /*这种做法合法但不安全*/
        //dl = {16.0, 32.0, 64.0, 128.0, 256.0};
        std::initializer_list<double> ct = {16.0, 32.0, 64.0, 128.0, 256.0};
        
        loger(std::cout, ORIGINAL, "List ct: 16.0 + 32.0 + 64.0 + 128.0 + 256.0 = ", sum(ct), '\n');
        loger(std::cout, ORIGINAL, "List ct: (16.0 + 32.0 + 64.0 + 128.0 + 256.0) / 5 = ", everage(ct), '\n');

        sum({});
        everage({});
    }
    catch (std::invalid_argument & __except)
    {
        ERROR_LOG(__except.what());
    }

    DONE
    return EXIT_SUCCESS;
}

double sum(std::initializer_list<double> __numList)
{
    if (__numList.size() > 0)
    {
        double totalValue = 0.00;
        for (std::initializer_list<double>::const_iterator listIter = __numList.begin(); listIter < __numList.end(); ++listIter)
        {
            totalValue += *listIter;
        }

        return totalValue;
    }
    else

        throw std::invalid_argument("Empty initializer_list! From sum(std::initializer_list<double> __numList)\n");
}

double everage(std::initializer_list<double> __numList)
{
    if (__numList.size() > 0)

        return sum(__numList) / __numList.size();

    else
    
        throw std::invalid_argument("Empty initializer_list! From everage(std::initializer_list<double> __numList)\n");
}