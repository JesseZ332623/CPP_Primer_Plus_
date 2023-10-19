#include "./include/brass_account.h"

using std::cout, std::cin;
using std::endl;

/*首先实现 抽象基类 Account 的构建函数*/
Account::Account(const string & _f, 
                const string & _account, double _bal)
{
    full_name = _f;
    account_no = _account;
    balence = _bal;
}

/*存钱*/
void Account::Deposit(double _amount)
{
    /*显然我们不允许用户传入负值*/
    if (_amount < 0)
    {
        cout << "Negative deposit is not allowed, "
             << "Deposit is cancelled..." << endl;
    }

    balence += _amount;
}

/*取钱*/
/*
    抽象基类只需完成最基本的功能，
    不同类型用户的实现会分开搞。
*/
void Account::With_Draw(double _amount)
{
    balence -= _amount;
}

/*设置格式*/
/*
    打开浮点标志位，要求输出只保留两位小数。
*/
Account::Formatting Account::Set_Format() const
{
    Formatting _format;

    _format.flag = cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
    _format.pr = cout.precision(2);

    return _format;
}

/*重设格式*/
void Account::Restore(Formatting & _format) const
{
    cout.setf(_format.flag, std::ios_base::floatfield);
    cout.precision(_format.pr);
}

void Brass_Account::With_Draw(double _amount)
{
    /*显然我们不允许用户传入负值，或其他垃圾数据*/
    if (_amount < 0)
    {
        cout << "With draw must be positive, "
             << "Deposit is cancelled..." << endl;
    }
    /*当然，普通用户也没有能力取出超出他存款的钱*/
    else if (_amount > Balence())
    {
        cout << "With draw amount must be positive, "
             << "Deposit is cancelled..." << endl;
    }

    Account::With_Draw(_amount);
}

void Brass_Account::View_Account() const
{
    Formatting _format = Set_Format();

    cout << "Brass Client: " << Full_Name() << endl;
    cout << "Account No. " << Account_No() << endl;
    cout << "Your Balence: $" << Balence() << endl;

    Restore(_format);
}

/*初始化用户信息，欠款额度，利率等数据*/
Brass_Plus::Brass_Plus(const string & fn, const string & acc, 
                    double bal, double ml, double rate) : Account(fn, acc, bal)
{
    max_loan  = ml;
    this->rate = rate;
    owns_bank = 0.0000;
}

Brass_Plus::Brass_Plus(const Brass_Account & ba, double ml, double rate) : Account(ba)
{
    max_loan  = ml;
    this->rate = rate;
    owns_bank = 0.0000;
}

/*显示账户信息*/
/*
    Brass_Plus 类别的账户要输出的内容比较多，如下：
    1）账户名
    2）账号
    3）余额
    4）最大透支额度
    5）目前欠银行多少钱
    6）目前的欠款利率
*/
void Brass_Plus::View_Account() const
{
    Formatting _format = Set_Format();

    cout << "Brass Client: " << Full_Name() << endl;
    cout << "Account No. " << Account_No() << endl;
    cout << "Your Balence: $" << Balence() << endl;
    cout << "Maxinum loan: $" << max_loan << endl;
    cout << "Owen to bank: $" << owns_bank << endl;

    cout.precision(3);

    cout << "Loan rate: " << 100 * rate << '%' << endl;

    Restore(_format);
}

/*取钱*/
void Brass_Plus::With_Draw(double _amount)
{
    Formatting _format = Set_Format();

    double _balence = Balence();

    /*要取的钱小于账户余额，直接调用 ABC 里面的方法即可*/
    if (_amount <= _balence) { Account::With_Draw(_amount); }

    /*
        如果 Brass_Plus 类型的用户打算透支自己的账户，
        就要先计算出透支的钱和利息，再进行扣款
    */
    else if (_amount <= _balence + max_loan - owns_bank)
    {
        double advance = _amount - _balence;
        owns_bank += advance * (1.0 + rate);

        /*输出透支的钱和要支付的利息*/
        cout << "Bank Advance: $" << advance << endl;
        cout << "Finance Chage: $" << advance * rate << endl;

        Deposit(advance);
        Account::With_Draw(_amount);
    }
    else
    {
        /*要是用户透支了自己账户的钱外加银行给予的透支额度，那么需要拒绝*/
        cout << "Credit limit exceed. Transaction cancelled...." << endl;
    }

    Restore(_format);
}