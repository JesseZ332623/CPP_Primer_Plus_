//#include <iostream>
#include <algorithm>
#include <cstring>
#include <stdexcept>

#include <MyLib/myLogerDef.h>

using namespace MyLib::MyLoger;

#define TEMPLATE true
#define NO_TEMPLATE false

#define SHOW_CONTENT(__array, __size) \
                    std::for_each(__array, __array + __size, \
                    [](const decltype(*__array) __n) -> void { std::cout << __n << ' '; }); \
                    std::cout << std::endl;

#if NO_TEMPLATE
/**
 * @brief 传入一个 C 风格数组和它的元素数，
 *        砍掉数组中所有重复的元素，并返回处理后的数组长度。
 * 
 * @param __array C 风格数组
 * @param __size  数组元素数
 * 
 * @return 处理后的数组长度
*/
int reduce(long int *__array, std::size_t __size);
#endif

/**
 * @brief 一个给数组去重的算法，适配数组和字符串
 * 
 * @param __array 数组或字符串
 * @param __size  数组元素数
 * 
 * @return 处理后的数组长度
*/
template <typename ArrayType>
int reduce(ArrayType __array[], std::size_t __size);

/**
 * @param 测试用例 A 测试数组的去重
*/
void testCaseA(void);

/**
 * @param 测试用例 B 测试字符串的去重
*/
void testCaseB(void);

int main(int argc, char const *argv[])
{
    system("cls");
    
    testCaseA();

    printSplitLine(50, '-');

    testCaseB();

    DONE

    return EXIT_SUCCESS;
}

#if NO_TEMPLATE
int reduce(long int *__array, std::size_t __size)
{
    if (!__array || !__size) { throw std::invalid_argument("NULL array or 0 size!\n"); }

    /*先按升序给 __array 排序*/
    std::sort(__array, __array + __size);

    /*将 __array 中所有的重复数据放在数组后面并返回 重复元素的起始迭代器*/
    long int * notUniqueBegin = std::unique(__array, __array + __size);

    /*返回去重后的数组元素数*/
    return notUniqueBegin - __array;
}
#endif

template <typename ArrayType>
int reduce(ArrayType __array[], std::size_t __size)
{
    if (!__array || !__size) { throw std::invalid_argument("NULL array or 0 size!\n"); }

    /*先按升序给 __array 排序*/
    std::sort(__array, __array + __size);

    ArrayType * notUniqueBegin = std::unique(__array, __array + __size);

    return notUniqueBegin - __array;
}

void testCaseA(void)
{
    long int array[] = {1, 1, 1, 4, 4, 4, 4, 4, 4, 114514, 114514, 1919810, 1, 1, 1, 4, 4, 4, 114514, 457893524, 1234, 58679, 0x121212};
    std::size_t arraySize = sizeof(array) / sizeof(decltype(*array));

    loger(std::cout, NOTIFY, "Before reduce(), array size = ", arraySize, "\nContent: \n");
    SHOW_CONTENT(array, arraySize);

    int reducedSize = reduce(array, arraySize);

    printSplitLine(50, '-');

    loger(std::cout, NOTIFY, "After reduce(), array size = ", reducedSize, "\nContent: \n");

    SHOW_CONTENT(array, reducedSize);

    printSplitLine(50, '-');
}

void testCaseB(void)
{
    /*Stop that! Get some help due~*/
    char cStyleString[] = {"Stop that! Get some help due~"};
    std::size_t stringLength = std::strlen(cStyleString);

    loger(std::cout, NOTIFY, "Before reduce(), string size = ", stringLength, "\nContent: \n", cStyleString, '\n');

    int reducedSize = reduce(cStyleString, stringLength);

    printSplitLine(50, '-');

    loger(std::cout, NOTIFY, "After reduce(), string size = ", reducedSize, "\nContent: \n");

    SHOW_CONTENT(cStyleString, reducedSize);

    printSplitLine(50, '-');
}
