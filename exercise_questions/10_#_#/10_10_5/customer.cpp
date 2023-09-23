#include "customer.h"

using std::cin, std::cout, std::endl;

void set_digital(size_t digital)
{
    using std::ios_base, std::cout;

    ios_base::fmtflags orig = 
                       cout.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = cout.precision(digital);
}

Customer_t::Customer_t()
{
    for (int index = 0; index < TOTAL_CUSTOMER; ++index)
    {
        cout << "customer (" << index + 1 << ')';

        cout << "enter your full name: ";
        cin >> client[index].full_name;

        cout << "enter your payment: $";
        cin >> client[index].payment;

        cout.put('\n');
    }

    total_payment = 0.00;

    cout << "Init data complite...\n";
    Sleep(1000);
    system("cls");
}

Customer_t::Customer_t(std::vector<std::string>::iterator full_name_iter, 
                       double *payment)
{
    for (int index = 0; index < TOTAL_CUSTOMER; ++index)
    {
        client[index].full_name = *full_name_iter;
        client[index].payment = payment[index];
        ++full_name_iter;  
    }

    total_payment = 0.00;

    cout << "Init data complite...\n";
}

void Customer_t::show_stack_data() const
{
    set_digital(2);

    for (int index = 0; index < TOTAL_CUSTOMER; ++index)
    {
        cout.precision(2);
        cout << "----------------------------------" << endl;
        cout << "Name: " << client[index].full_name << endl;
        cout << "Payment $" << client[index].payment << endl;
        cout << "----------------------------------" << endl;
    }
}

void Customer_t::customer_push()
{
    for (int index = 0; index < TOTAL_CUSTOMER; ++index)
    {
        customer.push(client[index]);
    }
}

void Customer_t::customer_pop()
{
    for (int index = 0; index < TOTAL_CUSTOMER; ++index)
    {
        _Customer temp = customer.top();
        customer.pop();
        total_payment += temp.payment;
    }
}

