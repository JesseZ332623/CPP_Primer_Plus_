#include "./include/mySleep.h"
#include "./include/myLogDef.h"

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <ctime>
#include <iterator>

/*
    STL 中除了前面讲到过的几个迭代器，
    还有 insert_iterator，front_insert_iterator，back_insert_iterator 用于元素的插入的迭代器。

    这些迭代器就是很好理解，使用它们就可以控制适配容器的头插和尾插。
*/

/**
 * @brief 随机的往一个队列里面插入数据，通常是数字类型。
 * 
 * @tparam __Tp             队列的元素类型
 * 
 * @param __queue           一个单向队列的引用
 * @param __limit           随机数生成的返回不超过这个值
 * @param __randomCount     生成的次数（通常为 10 次）
 * @param __deviationVal    误差值，用于随机生成小数，不填就为 0
 * 
 * @return non-return
*/
template <typename __Tp>
void pushRandomValue(std::queue<__Tp> & __queue, int __limit, int __randomCount = 10, double __deviationVal = 0.0);

/**
 * @brief 在不改变原队列的情况下输出队列的元素（只能传拷贝了）
 * 
 * @tparam __Tp             队列的元素类型
 * @param __queue           一个单向队列的引用
 * 
 * @return non-return
*/
template <typename __Tp>
void showQueueContent(std::queue<__Tp> __queue);

template <typename __Tp>
void pushRandomValue(std::queue<__Tp> & __queue, int __limit, int __randomCount, double __deviationVal)
{
    std::srand(std::time(nullptr));

    for (int index = 0; index < __randomCount; ++index)
    {
        __queue.push(std::rand() % __limit + __deviationVal);
    }
}

template <typename __Tp>
void showQueueContent(std::queue<__Tp> __queue)
{
    std::size_t index = 0L;

    std::cout << NOTIFY 
              << "This Queue size = " << (__queue.size() * sizeof(__Tp)) << " Bytes.\n" 
              << ORIGINAL;

    while (!__queue.empty())
    {
        std::cout << __queue.front() << ' ';
        __queue.pop();
        delayMilliseconds(60);

        if (index % 5 == 4) { std::cout << '\n'; }
        ++index;
    }
}

int main(int argc, char const *argv[])
{
    system("cls");

    std::queue<double> numberQueue;
    std::vector<double> numberArray = { 1919810.114514 };
    double testData[] = { 234.25, 134.865, 1345.234, 1425.90 };
    

    pushRandomValue(numberQueue, 1000, 5, 12.08);
    showQueueContent(numberQueue);

    std::copy(testData, testData + 4, std::back_insert_iterator<std::vector<double>>(numberArray));
    std::for_each(numberArray.begin(), numberArray.end(), [](const double n) { std::cout << n << ' '; delayMilliseconds(60); });
    //std::copy(testData, testData + 4, std::front_insert_iterator<std::queue<double>>(numberQueue));

    return EXIT_SUCCESS;
}
