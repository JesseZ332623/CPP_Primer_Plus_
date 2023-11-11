#include "./emp.h"

using std::cout, std::endl;

Abstr_Emp::~Abstr_Emp() {}

void Abstr_Emp::Show_All() const 
{
    cout << "Name: " << f_name << ' ' << l_name << endl;
    cout << "Job: " << job << endl;
}

void Abstr_Emp::Set_All()
{
    using std::cin, std::getline;

    cout << "Enter Your First Name: ";
    getline(cin, f_name);

    cout << "Enter Your Last Name: ";
    getline(cin, l_name);

    cout << "Enter Your Job: ";
    getline(cin, job);

    while (cin.get() != '\n') { continue; }
}

std::ostream & operator<<(std::ostream & _os, const Abstr_Emp & _emp)
{
    _emp.Show_All();

    return _os; 
}

void Employee::Show_All() const
{
    Abstr_Emp::Show_All();
}

void Employee::Set_All()
{
    Abstr_Emp::Set_All();
}

Manager::Manager(const Manager & _m) : Abstr_Emp(_m)
{
    In_Charge_Of() = _m.In_Charge_Of();
}

void Manager::Set_All()
{
    Abstr_Emp::Set_All();

    cout << "Enter (IN_CHARGE_OF): ";
    std::cin >> In_Charge_Of();
}

void Manager::Show_All() const
{
    Abstr_Emp::Show_All();

    cout << "In Charge Of: " << In_Charge_Of() << endl;
}

Fink::Fink(const Fink & _fink) : Abstr_Emp(_fink)
{
    Reports_To() = _fink.Reports_To();
}

void Fink::Set_All()
{
    Abstr_Emp::Set_All();

    cout << "Enter your reports to: " << endl;
    std::getline(std::cin, Reports_To());

    //while (std::cin.get() != '\n') { continue; }
}

void Fink::Show_All() const
{
    Abstr_Emp::Show_All();

    cout << "Reports To: " << Reports_To() << endl;
}

void Height_Fink::Set_All()
{
    std::string _temp_report;

    Abstr_Emp::Set_All();

    cout << "Enter (IN_CHARGE_OF): ";
    std::cin >> In_Charge_Of();

    std::cin.ignore();

    cout << "Enter your reports to: " ;
    std::getline(std::cin, _temp_report);

    Reports_To() = _temp_report;
}

void Height_Fink::Show_All() const
{
    Abstr_Emp::Show_All();

    cout << "In Charge Of: " << In_Charge_Of() << endl;

    cout << "Reports To: " << Reports_To() << endl;
}