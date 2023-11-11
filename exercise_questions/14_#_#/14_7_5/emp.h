/**
 * 一个比较复杂的菱形继承类设计，需要完成类设计并实现所有类方法，并编写一个测试程序进行测试。
 * 
 * 几个类的关系如下:
 * 
 *                  抽象基类 abstr_emp 公共派生出 employee
 *                  
 *                  抽象基类 abstr_emp 虚公共派生出 manage 和 fink
 * 
 *                  manage 和 fink 派生出 heigh_fink
 *                 （manage 和 fink 虚继承自 abstr_emp，因此共享一个基类）
*/

#ifndef _EMP_H_
#define _EMP_H

#include <iostream>
#include <string>

class Abstr_Emp
{
    public:
        using string = std::string;
    private:
        string f_name;
        string l_name;
        string job;

    public:
        Abstr_Emp() : f_name("No Name"), l_name("No Name"), job("No Job") {}

        Abstr_Emp(const string & _f, const string & _l, const string & _j) : f_name(_f), l_name(_l), job(_j) {}

        virtual void Show_All() const;

        virtual void Set_All();

        friend std::ostream & operator<<(std::ostream & _os, const Abstr_Emp & _emp);

        virtual ~Abstr_Emp() = 0;
};

class Employee : public Abstr_Emp
{
    public:
        Employee() : Abstr_Emp() {}
        Employee(const string & _f, const string & _l, const string & _j) : Abstr_Emp(_f, _l, _j) {}

        virtual void Show_All() const;

        virtual void Set_All();

        ~Employee() {}
};

class Manager : virtual public Abstr_Emp
{
    private:
        int in_charge_of;

    protected:
        int In_Charge_Of() const { return in_charge_of; }

        int & In_Charge_Of() { return in_charge_of; }

    public:
        Manager() : Abstr_Emp() {}

        Manager(const string & _f, const string & _l, const string & _j, int _ico = 0) : Abstr_Emp(_f, _l, _j), in_charge_of(_ico) {}

        Manager(const Abstr_Emp & _e, int _ico) : Abstr_Emp(_e), in_charge_of(_ico) {}

        Manager(const Manager & _m);

        virtual void Show_All() const;

        virtual void Set_All();

        ~Manager() {}
};

class Fink : virtual public Abstr_Emp
{
    public:
        using string = std::string;

    private:
        string reports_to;

    protected:
        const string Reports_To() const { return reports_to; }

        string & Reports_To() { return reports_to; }

    public:
        Fink() : Abstr_Emp() {}

        Fink(const string & _f, const string & _l, 
             const string & _j, const string & rp_t) : Abstr_Emp(_f, _l, _j), reports_to(rp_t) {}

        Fink(const Abstr_Emp & _e, const string & rp_t) : Abstr_Emp(_e), reports_to(rp_t) {}

        Fink(const Fink & _fink);

        virtual void Show_All() const;

        virtual void Set_All();

        ~Fink() {}
};

class Height_Fink : public Manager, public Fink
{
    public:
        using string = std::string;

        Height_Fink() : Manager(), Fink() {}

        Height_Fink(const string & _f, const string & _l, const string & _j,
                   int _ico, string rp_t) : Manager(_f, _l, _j, _ico), Fink(_f, _l, _j, rp_t) {}

        Height_Fink(const Abstr_Emp & _e, const string & rp_t, int _ico) : Manager(_e, _ico), Fink(_e, rp_t) {}

        Height_Fink(const Manager & _manager, const string & rp_t) : Abstr_Emp(_manager), Manager(_manager), Fink(_manager, rp_t) {}

        Height_Fink(const Fink & _fink, int _ico) : Abstr_Emp(_fink), Fink(_fink), Manager(_fink, _ico) {}

        Height_Fink(const Height_Fink & _h_fink) : Fink(_h_fink), Manager(_h_fink) {}

        virtual void Show_All() const;

        virtual void Set_All();

        ~Height_Fink() {}
};

/*
    声明和实现已经部分完成，明天再继续实现。
*/

#endif //_EMP_H_