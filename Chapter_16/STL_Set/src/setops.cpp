#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>

#include <MyLib/myLogDef.h>
#include <MyLib/mySleep.h>

const int STRING_SIZE = 6;

#define USE_OSTREAM_ITERATOR_TO_OUTPUT false

int main(int argc, char const *argv[])
{
    using std::cout, std::set, std::string, std::ostream_iterator;
    system("cls");

    string strArray_1[STRING_SIZE] = { "buffoon", "thinkers", "for", "heavy", "can", "for" };
    string strArray_2[STRING_SIZE] = { "metal", "any", "food", "elegant", "deliver", "for" };

    /*
        将字符串数组中的字符串们写入集合中，
        集合会根据字符串首字 ASCII 码值进行默认排序

        其次，set 的 key 是唯一的。
        因此 strArray_1 中出现的两个 for 在 setA 中只出现一次。
    */
    set<string> setA(strArray_1, strArray_1 + STRING_SIZE);
    set<string> setB(strArray_2, strArray_2 + STRING_SIZE);

    ostream_iterator<string, char> outIter(cout, " "); 
    auto outputFunc = [](const string & s) { cout << s << ' '; mySleep(40); };

#if USE_OSTREAM_ITERATOR_TO_OUTPUT

    std::copy(setA.begin(), setA.end(), outIter); puts("");
    std::copy(setB.begin(), setB.end(), outIter);

#endif

    cout << CORRECT << "SetA: \n" << ORIGINAL;
    std::for_each(setA.begin(), setA.end(), outputFunc); puts("");

    cout << CORRECT << "SetB: \n" << ORIGINAL;
    std::for_each(setB.begin(), setB.end(), outputFunc); puts("");

    
    /*
        set_union 算法将两个集合合并成一个集合，
        并通过迭代器输出到指定的 流 或 容器中。

        此处通过 ostream_iterator 迭代器将合并后的新集合的内容输出到了标准输出
    */
    cout << CORRECT << "Union of SetA and SetB: \n" << ORIGINAL;
    std::set_union(setA.begin(), setA.end(), setB.begin(), setB.end(), outIter); puts("");

    /*
        set_intersection 算法求两个有序容器的交集，
        并通过迭代器输出到指定的 流 或 容器中。

        此处通过 ostream_iterator 迭代器将合并后的新集合的内容输出到了标准输出
    */
    cout << CORRECT << "SetA and SetB's Intersection: \n" << ORIGINAL;
    std::set_intersection(setA.begin(), setA.end(), setB.begin(), setB.end(), outIter); puts("");

    /*
        set_difference 算法求两个有序容器的差集，
        并通过迭代器输出到指定的 流 或 容器中。

        此处通过 ostream_iterator 迭代器将合并后的新集合的内容输出到了标准输出
    */
    cout << CORRECT << "Difference of SetA and SetB: \n" << ORIGINAL;
    std::set_difference(setA.begin(), setA.end(), setB.begin(), setB.end(), outIter); puts("");


    set<string> setC;

    /*
        使用 set_union 将集合 A B 的键合并后输出给新的集合时要注意，
        函数的第三个参数不能直接用 set<type>::begin()，
        而是应该用 std::insert_iterator<set<type>>(newset, newset.begin())，原因有以下两点：

        1. 关联容器（map，multimap，set，multiset）一般都将 key 看作常量，
           因此 begin() 返回的迭代器是常量迭代器，不可以作为输入迭代器使用。

        2. 和 copy() 算法一样，set_union() 也会覆盖目标容器原来已有的数据，
           这要求被覆盖容器有足够的容量去承载，但此时 setC 是个空集。

        而 insert_iterator 可以解决上述两个问题，他将 copy 转换 insert，
        还模拟了 insert_iterator 的概念，可以用它将信息写入关联容器。
    */
    cout << CORRECT << "SetC: \n" << ORIGINAL;
    std::set_union(setA.begin(), setA.end(), setB.begin(), setB.end(), std::insert_iterator<set<string>>(setC, setC.begin()));
    std::for_each(setC.begin(), setC.end(), outputFunc); puts("");

    /*
        插入没什么好说的，std::set 内置了插入方法，
        无需用户提供，只需要传入插入内容即可。
    */
    setC.insert("grungy");
    cout << CORRECT << "After insert (SetC): \n" << ORIGINAL;
    std::for_each(setC.begin(), setC.end(), outputFunc); puts("");

    /*
        set 中最有用的成员方法莫过于 lower_bound() 和 upper_bound()

        1. lower_bound(key) 将 key 作为参数，返回一个指向大于等于该 key 的迭代器，
           若在目标集合中搜索不到 key，则返回 end()。
        
        2. upper_bound(key) 将 key 作为参数，返回一个指向大于该 key 的迭代器，
           若在目标集合中搜索不到 key，则返回 end()。

        此时 setC 的内容为：

            any buffoon can deliver elegant food for grungy heavy metal thinkers

        通过 setC.lower_bound("ghost") 和 setC.upper_bound("spook") 之后，产生的范围是：

            any buffoon can deliver elegant food for [grungy heavy metal] thinkers

        然后通过 ostream_iterator 迭代器新集合的内容输出到标准输出
    */
    cout << CORRECT << "Showing a range: \n" << ORIGINAL;
    std::copy(setC.lower_bound("ghost"), setC.upper_bound("spook"), outIter); puts("");

    return EXIT_SUCCESS;
}
