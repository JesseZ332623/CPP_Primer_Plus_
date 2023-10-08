#include <iostream>
#include "./include/brass_account.h"

const int CLIENTS = 2;

int main(int argc, char const *argv[])
{
    using std::cin, std::cout, std::endl;

    Brass_Account *p_client[CLIENTS];

    std::string temp;           /*client name*/
    std::string temp_num;      /*client's account number*/
    double temp_bal;           /*opening balance*/
    char kind;                 /*user choice*/

    for (int index = 0; index < CLIENTS; ++index)       /*循环给每一个对象输入数据*/
    {
        cout << "Enter the client name:";               /*客户姓名*/
        getline(cin, temp);
        cout << "Enter client's account number: ";      /*客户账号*/
        getline(cin, temp_num);
        cout << "Enter opening balance: $";             /*客户存款*/
        cin >> temp_bal;

        /*
            客户选择账号类型    1.普通账户  2.Plus 账户
        */
        cout << "Enter 1 for Brass_Account, Enter 2 for Brass_Plus: ";  
        while (cin >> kind && (kind != '1' && kind != '2'))
        {
            cout << "Please enter 1 or 2: ";
        }
        /*
            若是普通账户，就用 new 关键字 和 Brass_Account 构建函数创建 Brass_Account 类
        */
        if (kind == '1')    
        {
            p_client[index] = new Brass_Account(temp, temp_num, temp_bal);
        }
        /*
            若是 PLUS 用户，则要求用户输入额外信息再构建
        */
        else
        {
            double t_max, trate;
            cout << "Enter the overdraft limit: $";     /*可透支余额*/
            cin >> t_max;

            /*贷款利率 用小数的形式输入*/
            cout << "Enter the interest rate " << "as a decimal fraction: ";    
            cin >> trate;

            /*创建 Brass_Plus 类*/
            p_client[index] = new Brass_Plus(temp, temp_num, temp_bal, t_max, trate);
        }
        while (cin.get() != '\n') { continue; }
    }

    cout << endl;

    /*输出类信息 并逐个销毁对象数组中的成员*/
    for (int index = 0; index < CLIENTS; ++index)       
    {
        p_client[index]->View_Account();
        cout << endl;

        delete p_client[index];
        p_client[index] = nullptr;
    }
    
    cout << "Done.";

    return EXIT_SUCCESS;
}
