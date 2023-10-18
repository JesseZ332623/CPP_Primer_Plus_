/**
 * brass_account.h
 * @author by Jesse_EC
 * @date 2023.10.18
*/

/*
    Pontoon 银行要求我开发两个类：
        1）Brass_Account类 用于表示基本支票账户
            账户信息：
            1.客户姓名
            2.账号
            3.当前的余额

            可执行的操作：
            1.创建账户
            2.存款
            3.取款
            4.显示账户信息

        2）Brass_Plus类，继承自 Brass_Account类 用于 Plus 用户的支票账户，提供 <透支保护特性>
            账户信息：
            1.透支上限
            2.透支贷款利率
            3.当前透支总额

            可执行的操作（无需新增操作，但有两种操作的实现不同）：
            1.对于取款操作，必须考虑透支保护
            2.显示操作必须显示 Brass_Plus类的其他信息
            
        透支保护特性:
        1.若用户签出一张超过他存款的支票，但超出的数额不是很大（默认 $500 以内，有些客户限额不同），
        银行将支付这张支票，但对超出的部分收取额外的费用（利率默认是 11.125%，有些客户利率不同），并追加罚款。

        2.银行可以修改客户的利率和透支限额

        3.账户记录客户所欠的金额（透支数额 + 利息），用户不得通过常规存款或从其他账户转帐的方式偿付，
        必须用现金交给银行的工作人员，如有必要，之间上门催债，还清欠款后，欠款金额归零。
*/

/*
    date:2023.10.18
    使用 抽象基类 Abstract Base Class(ABC) 实现这个程序。
*/

#ifndef _BRASS_ACCOUNT_
#define _BRASS_ACCOUNT_

#include <string>
#include <iostream>
#include <fstream>

using std::string;

/*
    Account 是一个抽象基类，
    将 Brass_Account 和 Brass_Plus 类中的特点。
    抽象基类不能被创建为对象，但是可以被其他类继承。

    如果 一个类内出现了纯虚函数 如：virtual void View_Account() const = 0;
    那么该类就是一个 抽象基类。
*/
class Account
{
    private:
        string full_name;
        string account_no;
        double balence;

    /*
        新访问限定符 protected：
        对于外部代码来说，该限定符和 private 类似，
        它的特性只能在类继承中体现出来：
        派生类可以访问基类的 protected 限定成员，但不能访问基类的 private 成员。
    */
    protected:
        /*一个处理输出格式的结构体*/
        struct Formatting
        {
            std::ios_base::fmtflags flag;
            std::streamsize pr;
        };
        /*返回账户姓名*/
        const std::string & Full_Name() const { return full_name; }

        /*返回账号*/
        string Account_No() const { return account_no; }

        /*设置格式*/
        Formatting Set_Format() const;

        /*重设格式*/
        void Restore(Formatting & format) const;

    public:
        /*抽象基类的构建函数*/
        Account(const string & _f = "NULL_Body", const string & _account = "No Account", double _bal = 0.0000);

        /*取钱*/
        void Deposit(double _amount);

        /*返回余额*/
        const double Balence() const { return balence; }

        /*存钱*/
        virtual void With_Draw(double _amount) = 0;

        /*显示账户信息*/
        virtual void View_Account() const = 0;

        virtual ~Account() {}
        
};

/*Brass_Account 类 公共继承自 抽象基类 Account*/
class Brass_Account : public Account
{
    public:
        Brass_Account(const string & _f = "NULL_Body", 
                      const string & _account = "No_Account", double _bal = 0.0000) : Account(_f, _account, _bal) {}

        /*存钱*/
        virtual void With_Draw(double _amount);

        /*显示账户信息*/
        virtual void View_Account() const;

        ~Brass_Account() {};
};

class Brass_Plus : public Account
{
    private:
        double max_loan;    /*最大透支额度*/
        double rate;        /*透支贷款利率*/
        double owns_bank;   /*当前透支额度*/

    public:
        /*初始化用户信息，欠款额度，利率等数据*/
        Brass_Plus(const string & fn = "NULL_Body", const string acc = "NULL_NO", 
                    double bal = 0.0000, double ml = 500.00, double rate = 0.11125);
        Brass_Plus(const Brass_Account & ba, double ml = 500.00, double rate = 0.11125);

        /*重设最大透支额度*/
        void Reset_Max(double m) { max_loan = m; }

        /*重设透支贷款利率*/
        void Reset_Rate(double r) { rate = r; }

        /*重设欠款*/
        void Rest_Owes() { owns_bank = 0; }
        
        /*取钱*/
        virtual void With_Draw(double amt);

        /*显示账户信息*/
        virtual void View_Account() const;

        friend std::ostream & operator<<(std::ostream & _os, const Brass_Plus & _bp);

        virtual ~Brass_Plus() {}       
};

#endif