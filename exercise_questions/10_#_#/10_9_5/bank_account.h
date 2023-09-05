#ifndef _BANK_ACCOUNT_H_
#define _BANK_ACCOUNT_H_

#include <iostream>
#include <iomanip>
#include <string>
//#include <vector>
#include <windows.system.h>

using std::cin, std::cout, std::endl, std::string;

#define OVER_DISPOSIT 2

class Bank_Account
{
    private:
        string account_name;
        string account_no;
        double disposit;
    
    public:
        /*初始化类私有数据*/
        Bank_Account();
        Bank_Account(string & account_name, string & account_no);
        
        /*存钱*/
        bool deposit_money(double & money);
        
        /*取钱*/
        const double get_disposit() const { return this->disposit; }
        int withdraw_money(double & money);

        /*展示数据*/
        void show_account_data();

        /*类析构函数*/
        ~Bank_Account();
};

#endif