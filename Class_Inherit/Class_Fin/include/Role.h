/*
    这个文件旨在总结类的所有特性，包括：
    1）基类，派生类，抽象基类
    2）类默认函数，拷贝构造函数，移动构造函数，参数化构造函数，虚构造函数，析构函数

    继承 - 子类可以继承父类的属性和方法
    多态 - 子类可以重写父类的方法
    封装 - 将属性和方法封装在类中,可以控制访问性
    组合 - 类可以包含其他类的对象作为成员
    静态成员 - 类可以有静态的属性和方法,不需要实例化就可以访问
    接口 - 类可以实现接口,接口定义类的规范
    抽象类 - 不能实例化的类,用于继承和实现抽象方法
    访问修饰符 - 控制类成员的可访问性(public、protected、private)
    属性 - 类变量,用于表示对象的状态
    方法 - 类函数,在对象上执行操作的代码
*/

/*
    设计一个游戏中的角色类Role,要求如下:

    1.角色分为普通角色 NormalRole 和 Boss 角色 BossRole, BossRole 继承自 NormalRole
        NormalRole 有 血量 hp、攻击力 atk 和 防御力 def 作为属性;
        BossRole 另外有护盾量 shield 作为属性
    2.NormalRole 和 BossRole 都有受伤 logic() 和 攻击 fight() 方法;
    BossRole 的逻辑不同, 需重写这两个方法

    提供获取所有属性的 getter 方法, 和设置血量、攻击力、防御力的 setter 方法
    NormalRole 和 BossRole 的其他公共逻辑抽取到抽象父类 Role 中, 包含计算总生命值的方法 getTotalLifeValue()
    提供 NormalRole 和 BossRole 的参数化构造函数、拷贝构造函数、移动构造函数
    Role 类设计为单例模式, 只允许一个实例存在。

    提供一个生成角色的工厂类 RoleFactory, 根据名称创建不同角色
    编写测试主函数,测试各种类的用法。
*/

#ifndef _ROLE_H_
#define _ROLE_H_

#include "./defs.h"

/* 1 防御 可以抵消 5 点生命*/
const float _DEFENSE = 5;

/*
    抽象基类 Role
    作为 普通角色 和 Boss 角色 的 ABC，
    私有数据为：
        float hp        角色的血量
        float attack    角色的攻击力
        float defense   角色的防御力

    提供的操作为：
    protected:
        virtual void logic();   角色受伤
        virtual void fight();   角色攻击

    public:
        Role(float _hp, float _att, float _def);      参数化构造函数

        Role(Role & _role);                           复制构造函数

        Role(Role && _role);                          移动构造函数

        virtual void getter();                        获取所有属性

        virtual void setter(float _hp, float _att, float _def);     设置属性

        virtual float Get_Total_Life();                计算一个角色可以承受的伤害

        virtual Role & oprator=(const Role & _role);                符号重载拷贝函数

        ~Role();                                       析构函数
*/
class Role
{
    private:
        float hp;       /*角色的血量*/
        float attack;   /*角色的攻击力*/
        float defence;  /*角色的防御力*/

    protected:
        virtual void logic(float _damage);   /*角色受伤*/
        //virtual void fight();               /*角色攻击*/

    public:
        Role(float _hp, float _att, float _def);            /*参数化构造函数*/

        Role(const Role & _role);                           /*复制构造函数*/

        Role(Role && _role);                                /*移动构造函数*/

        virtual void getter() const;                              /*获取所有属性*/

        virtual bool setter(float _hp, float _att, float _def);     /*设置属性*/

        virtual float Get_Total_Life() const;                             /*计算一个角色可以承受的伤害*/

        virtual Role & operator=(const Role & _role);               /*符号重载拷贝函数*/

        ~Role() {};                                                 /*析构函数*/
};  


#endif