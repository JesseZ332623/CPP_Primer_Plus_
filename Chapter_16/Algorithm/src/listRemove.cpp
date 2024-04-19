#include <MyLib/myLib.h>

#include <list>

#define LIST_REMOVE_METHOD(__argument)  std::string("std::list<type>::remove(") += std::to_string(__argument) += ")"
#define STD_REMOVE_METHOD(__argument)   std::string("std::remove(") += std::to_string(__argument) += ")"

/**
 * 探究 std::list<type>::remove() 和 std::remove() 的区别
*/
int main(int argc, char const *argv[])
{
    system("cls");
    std::srand(std::time(nullptr));
    using namespace MyLib::SimpleContainerOperator;
    using namespace MyLib::MyLoger;

    std::list<int> la = {11, 45, 60, 12, 32, 11, 56, 89, 323};
    std::list<int> lb = {87, 54, 6, 4354, 45645, 4444, 90};

    loger(std::cout, NOTIFY, "Original list la contents: \n");
    showContainerToStream(std::cout, la);
    printSplitLine(30, '-');

    /*
        std::list 的 remove 成员方法：
        在整张表中搜索目标数值，然后删除所有匹配的数值，并自动调整链表的大小
    */
    la.remove(11);
    loger(std::cout, NOTIFY, "la after using ", LIST_REMOVE_METHOD(11), '\n');
    showContainerToStream(std::cout, la);
    printSplitLine(30, '-');

    loger(std::cout, NOTIFY, "Original list lb contents: \n");
    showContainerToStream(std::cout, lb);
    printSplitLine(30, '-');
    /*
        位于 <algorithm> 头文件的 remove() 算法：
        在两个迭代器划分的范围内搜索目标值，然后删除所有匹配的数值，
        并将链表的元素放在链表的开始位置，并返回一个新的尾部迭代器
        由于该算法并非容器的成员函数，因此不会自动调整链表的大小。
    */
    std::list<int>::iterator listIterB = std::remove(lb.begin(), lb.end(), 4444);

    loger(std::cout, NOTIFY, "lb after using ", STD_REMOVE_METHOD(4444), '\n');
    showContainerToStream(std::cout, lb);
    printSplitLine(30, '-');

    /*
        由于 remove() 算法并不会调整链表的大小，
        因此需要 erase 来移除链表不需要的部分。
    */
    lb.erase(listIterB, lb.end());
    loger(std::cout, NOTIFY, "lb after using erase()\n");
    showContainerToStream(std::cout, lb);
    printSplitLine(30, '-');

    return EXIT_SUCCESS;
}
