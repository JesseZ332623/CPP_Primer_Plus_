#include "bank_account.h"

const int Customer_Total = 5;
const double Init_Disposit = 50.00;

string customer_name_set[Customer_Total] =
{
    "Jesse", "Mike", "Amy", "Lee", "Jone"
};

string cuntormer_no_set[Customer_Total] =
{
    "#332623", "#667342", "#998123", "#998120", "#110977"
};

void user_menu()
{
    cout << "|--------------------|" << endl;
    cout << "|1) deposit_money    |" << endl;
    cout << "|2) withdraw_money   |" << endl;
    cout << "|3) show_account_data|" << endl;
    cout << "|4) Quit             |" << endl;
    cout << "|--------------------|" << endl;
}

#if true
int main(int argc, char const *argv[])
{
    system("cls");
    short user_choice = 0;
    double init_disposit = Init_Disposit;
    string user_name;
    size_t user_index = 0;
    double user_money_deposit = 0.00;
    double user_money_withdraw = 0.00;

    Bank_Account *bank_account = new Bank_Account[Customer_Total]
    {
        Bank_Account(customer_name_set[0], cuntormer_no_set[0]),
        Bank_Account(customer_name_set[1], cuntormer_no_set[1]),
        Bank_Account(customer_name_set[2], cuntormer_no_set[2]),
        Bank_Account(customer_name_set[3], cuntormer_no_set[3]),
        Bank_Account(customer_name_set[4], cuntormer_no_set[4])
    };

    
    for (int index = 0; index < Customer_Total; ++index)
    {
        bank_account[index].deposit_money(init_disposit);
    } 

    while (true)
    {
        user_menu();  
        cout << "Enter your choice: ";
        cin >> user_choice;
        switch (user_choice)
        {
            case 1:
                system("cls");
                user_index = 0;
                cout << "Enter your account name: ";
                cin >> user_name;

                for (const auto &tar : customer_name_set)
                {
                    if (tar == user_name)
                    {
                        cout << "Enter your money you want to deposit: $";
                        cin >> user_money_deposit;
                        bank_account[user_index].deposit_money(user_money_deposit);
                        bank_account[user_index].show_account_data();
                        cout << "OK" << endl;
                        break;
                    }
                    else 
                    {
                        ++user_index;
                    }
                }
                if (user_index == Customer_Total)
                {
                    cout <<"User name ["<< user_name << "] Not found...\n";
                }
                break;
            case 2:
                system("cls");
                user_index = 0;
                cout << "Enter your account name: ";
                cin >> user_name;

                for (const auto &tar : customer_name_set)
                {
                    if (tar == user_name)
                    {
                        cout << "Enter your money you want to withdraw: $";
                        cin >> user_money_withdraw;
                        int _case = bank_account[user_index].withdraw_money(user_money_withdraw);
                        if(!_case)
                        {
                            cout << "Enter value could't less than 0.\n";
                            break;
                        }
                        else if (_case == OVER_DISPOSIT)
                        {
                            cout.precision(2);
                            cout << "Your deposit: $ " << bank_account[user_index].get_disposit() << endl
                                 << "You can't depos money more than your disposit (your enter: "
                                 << user_money_withdraw << ')' << endl;
                            break;
                        }
                        else 
                        {
                            cout << "OK" << endl;
                            bank_account[user_index].show_account_data();
                            break; 
                        }
                    }
                    else 
                    {
                        ++user_index;
                    }
                }
                if (user_index == Customer_Total)
                {
                    cout <<"User name ["<< user_name << "] Not found...\n";
                }
                break;

            case 3: 
                system("cls");
                user_index = 0;
                cout << "Enter your account name: ";
                cin >> user_name;

                for (const auto &tar : customer_name_set)
                {
                    if (tar == user_name)
                    {
                        bank_account[user_index].show_account_data();
                    }
                    else 
                    {
                        ++user_index;
                    }
                }
                if (user_index == Customer_Total)
                {
                    cout <<"User name ["<< user_name << "] Not found...\n";
                }
                
                break;
            
            case 4:
                cout << "Have a good time!" << endl;
                exit(EXIT_SUCCESS);

            default:
                cout << "Error choice: (" << user_choice << ')';
                cout << " Please enter again...\n";
                Sleep(1000);
                system("cls");
                break;
        }
        while (cin.get() != '\n')
        {
            continue;
        }
    }
    delete bank_account;
    
    return EXIT_SUCCESS;
}

#endif
