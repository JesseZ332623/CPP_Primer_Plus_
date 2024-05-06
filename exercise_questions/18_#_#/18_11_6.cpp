#include <iostream>
#include <array>

/**
 * 修改下列程序，替换 functor Adder 为 Lamba 表达式，
 * 不允许修改 sum 函数。
*/

const int SIZE = 5;

template <typename __Type>
void sum(std::array<double, SIZE> __a, __Type & __fp);

#if false
class Adder
{
    private:
        double total;

    public:
        explicit Adder(double __q = 0) : total(__q) {}

        void operator()(double __n) { this->total += __n; }

        double getTotal(void) const { return this->total; }
};
#endif

int main(int argc, char const *argv[])
{
    //Adder adder;

    std::array<double, SIZE> tempArray = {32.1, 34.3, 37.8, 35.2, 34.7};


    double arrayTotal = 0.0;

    /**
     * 一个替换 Adder 函数符的 Lamba 表达式，
     * 按引用捕获 arrayTotal，从一个容器里面取值，与它累加。
    */
    auto totalFunc = [&arrayTotal](const double __number) -> void { arrayTotal += __number; };

    sum(tempArray, totalFunc);

    std::cout << "Total of tempArray = " << arrayTotal << '\n';
    
    return EXIT_SUCCESS;
}

template <typename __Type>
void sum(std::array<double, SIZE> __a, __Type & __fp)
{
    for (auto it = __a.begin(); it != __a.end(); ++it)
    {
        __fp(*it);
    }
}