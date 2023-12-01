#include <iostream>
#include <bits/stl_algo.h>
#include <vector>
#include <list>

/*
    std::sort() 顾名思义，就是给一个容器内的数据排序，泛用性非常高，用法如下：

    std::sort(container.iterator, container.iterator, (function) or (lamba));

    其中 (function) or (lamba) 参数用于指定你排序的规则，比如升序或降序。
    若不指定默认为升序排序。

    std::sort 一般采用混合排序算法，通常采取如下策略：

    1. 对于大数据集使用 快速排序 和 堆排序。
    2. 当 （1.）将数据分解到小数据集后，开始切换到插入排序。


    此外，一个自定义的容器要匹配 std::sort() 就必须重载以下运算符：

    比较运算符 '<' : 用于升序排序
              '>' : 用于降序排序
              
*/

/*
    对一个 STL 容器 vector 进行排序，这很简单，
    传入迭代器指定返回，以及一个函数指针或对象确定规则即可。
*/
void SORT_STD_VECTOR()
{
    std::vector<int> _data = {3125, 245, 352, 13, 1253, 24, 12, 43, 895};

    /*两个排序规则，分别是升序 和 降序*/
    auto ascending_order = [](const int _element_1, const int _element_2) -> bool { return _element_1 < _element_2; };
    auto descending_order = [](const int _element_1, const int _element_2) -> bool { return _element_1 > _element_2; };

    printf("Original Data:\n");
    for (auto & index : _data) { printf("%d\t", index);} puts("");

    std::sort(_data.begin(), _data.end(), ascending_order);

    printf("After Sort By Ascending_Order:\n");
    for (auto & index : _data) { printf("%d\t", index);} puts("");

    std::sort(_data.begin(), _data.end(), descending_order);

    printf("After Sort By Ascending_Order:\n"); 
    for (auto & index : _data) { printf("%d\t", index);} puts("");
}

/*
    对一个 STL 容器 list 进行排序，list 的底层实现是双向链表，这是非连续且非线性的数据结构，应此不匹配 std::sort()。
    因此必须使用 list 内部的 sort 方法进行排序，该方法使用并归排序就地对 list 排序。
*/
void SORT_STD_LIST()
{
    std::list<int> _data = {134, 13, 1245, 18, 134, 144234567, 3511};

    auto ascending_order = [](const int _a, const int _b) -> bool { return _a < _b; };
    auto descending_order = [](const int _a, const int _b) -> bool { return _a > _b; };

    //std::sort(_data.begin(), _data.end(), ascending_order);

    _data.sort(ascending_order);

    for (auto & index : _data) { printf("%d\t", index);} puts("");
}

int main(int argc, char const *argv[])
{
    //SORT_STD_VECTOR();

    SORT_STD_LIST();

    return EXIT_SUCCESS;
}
