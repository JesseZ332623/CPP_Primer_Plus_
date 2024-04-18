#include <iostream>
#include <algorithm>
#include <vector>
#include <valarray>
#include <array>
#include <cmath>

#include <MyLib/myLib.h>

#define EXAMPLE false
#define PROGRAM_LIST true

int main(int argc, char const *argv[])
{
    using namespace MyLib::MyLoger;
    using namespace MyLib::SimpleContainerOperator;
    using MyLib::MyDelay::delay;

    system("cls");

#if EXAMPLE
    std::vector<double> numberList = {9, 16, 25, 19356, 245376, 245, 2456546086};
	std::vector<double> resultList(numberList.size());

    std::valarray<int> intengerList = {1, 2, 3, 4, 5};
    std::vector<int> resultIntList(intengerList.size());

    /**
     * 像书中型如 
     *      std::transform(numberList.begin(), numberList.end(), resultList.begin(), std::log);
     * 的语法在新标准中是不允许的，可以使用 Lamba 表达式 “取出” 容器内的每一个数据在进行相应的计算。
    */
    std::transform(
                    numberList.begin(), numberList.end(), resultList.begin(), 
                    [](const double __num) { return std::log(__num); }
                  );

    /**
     * valarray 容器重载了很多算术运算符，
     * 可以对容器内的所有数据进行统一的算术操作。
    */
    //intengerList = 10 * intengerList;
    intengerList *= 10;
    
    log(std::cout, NOTIFY, "Content of intengerList: \n");
    for (const int num : intengerList)
    {
        std::cout << num << '\t';
    }puts("");

	log(std::cout, NOTIFY, "Content of resultList: ");
    showContainerToStream(std::cout, resultList);
#endif // EXAMPLE

#if PROGRAM_LIST
    std::vector<double> data;
    double tempNumber;

    loger(std::cout, NOTIFY, "Enter numbers (<= 0 to quit input):\n");
    while (std::cin >> tempNumber && tempNumber > 0) { data.push_back(tempNumber); }
    std::size_t dataSize = data.size();
    if (!dataSize) { loger(std::cout, ERROR, "Empty Input.\n"); return -1; }

    std::sort(data.begin(), data.end());

    //showContainerToStream(std::cout, data, true);

    // 实例化一个 std::valarray<double> 类对象，初始化为 data 的长度
    std::valarray<double> numbersList(dataSize);
    std::size_t index = 0L;

    /*
        由于 std::valarray 没有迭代器的概念，
        所以用不了 STL 算法，只能手动拷贝。
    */
    for(; index < dataSize; ++index) { numbersList[index] = data[index]; }

    std::valarray<double> logNumList(dataSize);
    std::valarray<double> resultLits(dataSize);

    /**
     * 一些数学函数和运算符也对 std::valarray 容器做了重载，
     * 可以统一的对该容器内的数据进行数学计算。
     * 
     * 比如此处，就是对 numbersList 整个 std::valarray<double> 类对象的数据求以 10 为底的对数值。
    */
    logNumList = std::log10(numbersList);

    /**
     * 将 logNumList 内的所有数据 * 2.0 再加上 numbersList 内的所有数据，示例如下：
     * 
     * logNumList =  (({3, 6, 9}) * 2)
     *     +            +  +  +
     * numbersList =   {1, 2, 3}
     * 
     * resultLits  =   {7, 14, 21}
    */
    resultLits = numbersList + 2.0 * logNumList;

    std::cout.setf(std::ios_base::fixed);
    std::cout.precision(4);

    printSplitLine(75, '-');
    loger(std::cout, NOTIFY, "log(numbersList[index])\t\tlogNumList[index] * 2 + numbersList[index]\n");
    printSplitLine(75, '-');
    for (index = 0L; index < dataSize; ++index)
    {
        std::cout.width(14);
        std::cout << logNumList[index];
        std::cout.width(40);
        std::cout << resultLits[index] << '\n';
        delay(45);
    }
    printSplitLine(75, '-');
#endif

    loger(std::cout, CORRECT, "Done.\n");

    return EXIT_SUCCESS;
}