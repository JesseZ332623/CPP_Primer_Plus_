#include "./namesp.h"

namespace pers
{
    using std::cin;
    using std::cout;

    void get_person(Person &rp)
    {
        cout << "Enter first name: ";
        cin >> rp.f_name;

        cout << "Enter last name: ";
        cin >> rp.l_name;
    }

    void show_person(const Person &rp)
    {
        cout << "first name:" << rp.f_name << '\n';
        cout << "last name: " << rp.l_name << '\n';
    }
}

namespace debts
{
    void get_debts(Debts &debt)
    {
        get_person(debt.name);

        std::cout << "Enter amount: ";
        std::cin >> debt.amount;
    }

    void show_debts(const Debts & debt)
    {
        show_person(debt.name);
        std::cout << "debt amount: " << debt.amount << '$' << std::endl;
    }

    double sum_debts(const Debts *debts, int count)
    {
        double total_amount = 0;

        for (int index = 0; index < count; ++index)
        {
            total_amount += debts[index].amount;
        }

        return total_amount;
    }
}