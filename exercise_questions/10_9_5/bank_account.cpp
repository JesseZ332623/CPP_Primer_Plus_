#include "bank_account.h"

/*初始化类私有数据*/
/*10_9_7 构造函数答案*/
Bank_Account::Bank_Account()
{
    cout << "Init account data: " << endl;

    cout << "Enter account name: ";
    cin >> account_name;

    cout << "Enter account no. ";
    cin >> account_no;

    disposit = 0.00;
}

Bank_Account::Bank_Account(string & account_name, string & account_no)
{
    cout << "Init account data: [" << account_name << ']' << endl;

    this->account_name = account_name;
    this->account_no = account_no;
    this->disposit = 0.00;
}

bool Bank_Account::deposit_money(double & money)
{
    if (money < 0)
    {
        return false;
    }

    disposit += money;

    return true;
}

int Bank_Account::withdraw_money(double & money)
{
    if (money < 0)
    {
        return false;
    }
    else if (disposit - money < 0)  /*当然，用户不可能取出比余额还要大的钱*/
    {
        return OVER_DISPOSIT;
    }

    disposit -= money;

    return true;
}

void Bank_Account::show_account_data()
{
    using std::ios_base;

    ios_base::fmtflags orig = 
                       cout.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = cout.precision(2);

    cout << "-----------------------------------------" << endl;
    cout << "Account Name: " << account_name << endl;
    cout << "Acount No. " << account_no << endl;
    cout.precision(2);
    cout << "Account disposit: $" << this->disposit << endl;
    cout << "-----------------------------------------" << endl;
}

Bank_Account::~Bank_Account() {}