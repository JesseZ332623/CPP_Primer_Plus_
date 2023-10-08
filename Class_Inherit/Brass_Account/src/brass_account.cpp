#include "./include/brass_account.h"

using std::cout;
using std::endl;

typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;

format set_format();

void restore(format f, precis p);

/*将浮点类型的输出设为小数点输出，而不是指数*/
format set_format()
{
    // 设置小数点位数 ###.##
    return cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}

/*设置输出的小数点总宽度*/
void restore(format f, precis p)
{
    cout.setf(f, std::ios_base::floatfield);
    cout.precision(p);
}

/*初始化用户信息*/
Brass_Account::Brass_Account(const string &fn, const string acc, double bal)
{
    full_name = fn;
    account_no = acc;
    balence = bal;
}

/*存钱*/
void Brass_Account::Deposit(double amt)
{
    if (amt < 0)
    {
        /*不允许负存款*/
        cout << "Negative deposit not allowed; "
             << "deposit is cancelled." << endl;
    }
    else
    {
        balence += amt;
    }
}

/*返回余额*/
const double Brass_Account::Balence() const
{
    return balence;
}

/*取钱*/
void Brass_Account::With_Draw(double amt)
{
    format init_state = set_format();
    precis prec = cout.precision(2);

    if (amt < 0)
    {
        cout << "with_draw amount must be positive; "
             << "with_draw canceled." << endl;
    }
    else if (amt <= balence)
    {
        balence -= amt;
    }
    else
    {
        cout << "with_draw amont of $" << amt << " exceeds your balance." << endl
             << "with_draw canceled." << endl;
    }

    restore(init_state, prec);
}

/*显示账户信息*/
void Brass_Account::View_Account() const
{
    format init_state = set_format();
    precis prec = cout.precision(2);

    cout << "Client: " << full_name << endl;
    cout << "Account Name: " << account_no << endl;
    cout << "Balance: $" << balence << endl;

    restore(init_state, prec);
}

std::ostream & operator<<(std::ostream & _os, const Brass_Account & _bs)
{
    format init_state = set_format();
    precis prec = cout.precision(2);

    _os << "Client: " << _bs.full_name << endl;
    _os << "Account Name: " << _bs.account_no << endl;
    _os << "Balance: $" << _bs.balence << endl;
    
    restore(init_state, prec);
    
    return _os;
}

Brass_Plus::Brass_Plus(const string &fn, const string acc,
                       double bal, double ml, double rate) : Brass_Account(fn, acc, bal)
{
    max_loan = ml;
    owns_bank = 0.0000;
    this->rate = rate;
}

Brass_Plus::Brass_Plus(const Brass_Account & ba, double ml, double rate) : Brass_Account(ba)
{
    max_loan = ml;
    owns_bank = 0.0000;
    this->rate = rate;
}

/*取钱*/
void Brass_Plus::With_Draw(double amt)
{
    format init_state = set_format();
    precis prec = cout.precision(2);
    
    /*从 父类方法 Balence 获取余额*/
    double bal = Balence();

    /*若 要取的钱小于原余额*/
    if (amt <= bal)
    {
        /*直接执行取钱操作，当然必须明确这是父类的方法，不然会造成混乱*/
        Brass_Account::With_Draw(amt);
    }
    /*
        Plus 用户的当前余额 = 原余额 + 透支额度 - 当前透支额度
        若 用户要取的钱小于这个值，就是透支操作
    */
    else if (amt <= bal + max_loan - owns_bank)
    {
        /*透支的钱 = 要取的钱 - 原余额*/
        double advance = amt - bal;

        /*当前透支额度 += 透支的钱 * 利率(%)*/
        owns_bank += advance * (1.0 + rate);

        /*输出 欠款 和 要缴纳的利息*/
        cout << "Bank of advance: $" << advance << endl;
        cout << "Finance charge: $" << advance * rate << endl;

        Deposit(advance);
        Brass_Account::With_Draw(amt);
    }
    /*取出的钱超过了用户的愈合以及可透支的余额时，退出系统*/
    else
    {
        cout << "Credit limit exceed. Transaction cancelled." << endl;
    }

    restore(init_state, prec);
}

void Brass_Plus::View_Account() const
{
    format init_state = set_format();
    precis prec = cout.precision(2);

    /*输出账户基本信息*/
    Brass_Account::View_Account();
    /*再输出透支额度相关的信息*/
    cout << "Max Loan: $" << max_loan << endl;
    cout << "Owed to bank: $" << owns_bank << endl;
    cout.precision(3);
    cout << "Loan rate: " << rate * 100 << '%' << endl; 

    restore(init_state, prec);
}

std::ostream & operator<<(std::ostream & _os, const Brass_Plus & _bp)
{
    format init_state = set_format();
    precis prec = cout.precision(2);

    _os << (Brass_Account)_bp;

    _os << "Max Loan: $" << _bp.max_loan << endl;
    _os << "Owed to bank: $" << _bp.owns_bank << endl;

    cout.precision(3);
    _os << "Loan rate: " << _bp.rate * 100 << '%' << endl;

    restore(init_state, prec);

    return _os;
}

void p_line()
{
    std::cout << "------------------------------" << std::endl;
}