/**
 * base_derives.h 基类与派生类
 * @author by Jesse_EC
 * @date 2023.9.30
*/

/*
    首先复习 C++ 类的三大访问权限：

        1.public 成员可以被任何外部代码访问

        2.protected 介于 公有/私有 之间，可以被派生类访问，
        但不能被外部代码访问

        3.privite 成员只能被类自己访问

    然后是派生类可以访问基类成员的三大权限：

        1.class Derives : public Base       公有继承
        基类的 public 和 protected 成员在派生类中访问权限不变,依旧是 public 和 protected。

        2.class Derives : protected Base    受保护的继承
        基类的 public 成员变为 protected,protected 成员不变,还是 protected。

        3.class Derives : privite Base      私有继承
        基类的 public 和 protected 成员在派生类中都变为 private 访问权限。
*/


#ifndef _BASE_DERIVES_
#define _BASE_DERIVES_

#include <iostream>

/*基类 Base*/
class Base
{
    private:
        int base_data;

    public:
        Base(int base_data = 0);

        friend std::ostream & operator<<(std::ostream & _os, Base & _base);

        const int get_base_data() { return base_data; }

        ~Base();
};

/*基类 Base 派生出一个类 Derives*/
class Derives : public Base
{
    private:
        int derives_data;

    public:
        int _b_dat;

        Derives(int derives_data = 0);

        friend std::ostream & operator<<(std::ostream & _os, Derives & _derives);

        ~Derives();
};

#endif
