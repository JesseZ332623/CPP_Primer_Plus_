#ifndef _MORE_TEMP_ARGUMENT_H_
#define _MORE_TEMP_ARGUMENT_H_

/*使用多个类型参数的模板类*/

/**
 * 
 * 模板可以包含多个参数。
 * 假设希望类可以保存两种值，则可以创建并使用一个多参数的模板类，如下所示：
 * 
 *          template<typename Type_1, typename Type_2, ...>  或
 * 
 *          template<class Type_1, class Type_2, ...>
 * 
 * 可以有 n 个 typename，这取决于用户的使用（在 C++ 11 标准之前，使用 class 关键字来设置模板参数）。
 * 
 * 当然，类模板也可以设置默认类型，语法如下所示：
 *          
 *          template<typename Type_1, typename Type_2 = default_type, ...> class A {....};
 * 
 * 如果在使用这个类时有如下声明：
 *          
 *          A<int> object_a
 * 
 * 那么第二个模板参数会被自动替换为 default_type
 * 
 * 接下来编写一个小程序，详细说明多个参数类型的模板类的使用。
*/

#include <iostream>
#include <string>

template<typename Type_1, typename Type_2 = int>
class Pair
{
    private:
        Type_1 a;
        Type_2 b;

    public:
        /*模板类构建函数*/
        Pair(const Type_1 & _t1_val, const Type_2 & _t2_val) : a(_t1_val), b(_t2_val) {}

        /*返回 私有数据 a 的 引用*/
        Type_1 & first();

        /*返回 私有数据 b 的 引用*/
        Type_2 & second();

        /*返回 私有数据 a 的 拷贝*/
        Type_1 first() const { return a; }

        /*返回 私有数据 b 的 拷贝*/
        Type_2 second() const { return b; }

        ~Pair() {};
};

/*在外部实现模板类方法，就得先声明模板，然后再声明类的具体类型*/
template<typename Type_1, typename Type_2>
Type_1 & Pair<Type_1, Type_2>::first()
{
    return a;
}

template<typename Type_1, typename Type_2>
Type_2 & Pair<Type_1, Type_2>::second()
{
    return b;
}

#endif