#include "person.h"

Person::Person(const string & ln, const char *fn)
{
    this->l_name = ln;
    strcpy(this->f_name, fn);
}

void Person::Show() const
{
    using std::cout, std::endl;

    cout << f_name << '.' << l_name << endl;
}

void Person::Formal_Show() const
{
    using std::cout, std::endl;

    cout << l_name << '.' << f_name << endl;
}