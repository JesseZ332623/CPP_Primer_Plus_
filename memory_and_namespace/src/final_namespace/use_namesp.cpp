#include "./namesp.h"

void other(void);
void another(void);

void other(void)
{
    using std::cin;
    using std::cout;
    using namespace debts;

    Person dg = {"Doodles", "Glister"};
    Debts zippy[3];

    show_person(dg);

    for (int i = 0; i < 3; ++i)
    {
        get_debts(zippy[i]);
    }
    for (int i = 0; i < 3; ++i)
    {
        show_debts(zippy[i]);
    }

    cout << "Total amount: " << sum_debts(zippy, 3) << std::endl;
}

void another(void)
{
    using pers::Person;

    Person collector = {"Milo", "Rightshift"};
    pers::show_person(collector);
}

int main(int argc, char const *argv[])
{
    using debts::Debts;
    using debts::show_debts;

    Debts golf = {{"Benny", "Goatsniff"}, 120.00};

    show_debts(golf);

    other();
    another();
    return EXIT_SUCCESS;
}

