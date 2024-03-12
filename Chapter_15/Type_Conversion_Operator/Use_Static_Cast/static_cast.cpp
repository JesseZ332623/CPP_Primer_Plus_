#include <iostream>

using std::cout;

/*
    static_cast 运算符和 前面几个一样：

        static_cast<type-name>(expression)

    仅当 type-name 可被隐式的转换为 expression 所属的类型，
    或 expression 被隐式的转换为 type-name 所属的类型时，上述的转换是合法的，
    否则会抛 bad_cast 异常。
*/

class High {};                  // 基类 High
class Low : public High {};     // 子类 Low 派生自 High

class Pond {};                  // 和上述两者无关的类 Pond

enum Number_List { ZERO = 0, FIRST, SECOND, THIRD, FORTH };

int main(int argc, char const *argv[])
{
    High bar;
    Low blow;

    High * pb = static_cast<High *>(&blow);     // 合法，从 子 -> 父，属向上转换 (up-cast)，可以显示的进行

    /*
        合法。虽然 父 -> 子，
        属向下转换（down-cast)，显示进行是不允许的，但是使用该运算符就可以了，
        使用时需要格外注意类的设计，别让父类虚函数指针指向了一个未定义的子类方法中去。
    */
    Low * pz = static_cast<Low *>(&bar);

    /*
        毫不相干的两个类在没有设立规则的情况下肯定是不合法的，甚至会被编辑器识别出来。
    */
    // Pond * pmer = static_cast<Pond *>(&blow);

    /*
        当然，可以拿该运算符对枚举类型进行转换。
    */
    Number_List numList = FORTH;
    int forth = static_cast<int>(numList);

    if (forth == numList)
        std::cout << forth << " = " << numList;

    return 0;
}
