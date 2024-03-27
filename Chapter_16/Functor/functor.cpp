#include "./include/defs.h"

#include <list>

/**
 *  程序的目的很简单，设计一个仿函数（重载了 operator() 的类），
 *  用于完成 std::list::remove_if(functor) 的一元谓词调用。
*/

/**
 * @brief 一个仿函数，其目的就是设置一个界限值（cutOff），
 * 为 std::list::remove_if(functor) 所用
 * 
 * @tparam Type 界限值类型
*/
template <typename Type>
class Limit
{
    private:
        Type cutOff {0};

    public:
        Limit(const Type & __cuf) : cutOff(__cuf) {}

        bool operator()(const Type & __lim) { return __lim > cutOff; }
};

int main(int argc, char const *argv[])
{
    using std::cout, std::list;

    system("cls");
    std::srand(std::time(nullptr));

    Limit<int> limitA(1000); // 设定界限值为 1000

    list<int> listA = {265, 2356531, 342, 3, 467567, 14, 467, 90331};
    list<double> listB;

    /*
        给 listB 随机插入 
    */
    pushRandomValue(listB, 2500, 20, 18.7650);  

    log(cout, NOTIFY, "The Original [List A]:\n");
    showContainerToStream(cout, listA);
    printSplitLine(40, '-');

    log(cout, NOTIFY, "The Original [List B]:\n");
    showContainerToStream(cout, listB);
    printSplitLine(40, '-');

    listA.remove_if(limitA);

    /*
        像 list::sort() 方法，
        需要传入一个二元谓词来指定排序的规则。
    */
    listB.sort([](const double a, const double b) -> bool { return a < b; });
    log(cout, NOTIFY, "The [List B] After Sort:\n");
    showContainerToStream(cout, listB);
    printSplitLine(40, '-');

    /*
        创建一个临时对象，设定界限值为 550.00
    */
    listB.remove_if(Limit<double>(550.00));

    log(cout, NOTIFY, "The [List A] After remove some value bigger than 1000:\n");
    showContainerToStream(cout, listA);
    printSplitLine(40, '-');

    log(cout, NOTIFY, "The [List B] After remove some value bigger than 550:\n");
    showContainerToStream(cout, listB);
    printSplitLine(40, '-');

    return EXIT_SUCCESS;
}
