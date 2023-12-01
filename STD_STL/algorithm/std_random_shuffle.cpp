#include <iostream>
#include <bits/stl_algo.h>
#include <vector>
#include <random>

void RANDOM_SHUFFLE();
void SHUFFLE();

/*
    std::random_shuffle()
    由于随机性不强，开销较大 O(n)，泛用性不强，已经在 C++17 标准中被废弃。

    目前由 std::shuffle() 来代替 std::random_shuffle()
*/
void RANDOM_SHUFFLE()
{
    std::vector<int> _data = {1, 2, 3, 4, 5};

    auto _rule = [](int _number) { printf("%d\t", _number); };

    std::for_each(_data.begin(), _data.end(), _rule); putchar('\n');

    /*对 _data 进行随机排序，使用默认的排序算法*/
    std::random_shuffle(_data.begin(), _data.end());

    std::for_each(_data.begin(), _data.end(), _rule); putchar('\n');
}

void SHUFFLE()
{
    std::vector<int> _data = {1543, 123, 245, 245, 23, 5};

    auto _rule = [](int _number) { printf("%d\t", _number); };

    std::for_each(_data.begin(), _data.end(), _rule); putchar('\n');

    /*
        使用更加泛用，可靠的 shuffle 函数。
        配合使用 STL 的默认随机引擎（std::default_random_engine），
        每次调用都随机生成一个种子（std::random_device{}()），这样随机性更强。（位于 <random> 头文件中）
    */
    std::shuffle(_data.begin(), _data.end(), std::default_random_engine(std::random_device{}()));

    std::for_each(_data.begin(), _data.end(), _rule); putchar('\n');
}

int main(int argc, char const *argv[])
{
    //RANDOM_SHUFFLE();

    SHUFFLE();

    return EXIT_SUCCESS;
}
