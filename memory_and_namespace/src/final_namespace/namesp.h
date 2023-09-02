#include "F:\C++ Primire Plus\memory_and_namespace\src\head_file\defs.h"

namespace pers
{
    struct Person
    {
        std::string f_name;
        std::string l_name;
    };

    void get_person(Person &);
    void show_person(const Person &);
}

namespace debts
{
    using namespace pers;

    struct Debts
    {
        Person name;
        double amount;
    };

    void get_debts(Debts &);
    void show_debts(const Debts &);
    double sum_debts(const Debts *debts, int count);
}