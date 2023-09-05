#include "plorg.h"

Plorg::Plorg(std::string name, int satisfaction)
{
    if (name.length() < NAME_LEN)
    {
        this->name = name;
    }
    else
    {
        this->name = name.substr(0, NAME_LEN);
    }

    this->satisfaction = satisfaction;
}

void Plorg::modify_satisfaction(int & satisfaction)
{
    this->satisfaction = satisfaction;
}

void Plorg::report_info() const
{
    using std::cout;

    cout << "Name: " << name << ' '
         << "Satisfaction: " << satisfaction
         << std::endl;
}

int main(int argc, char const *argv[])
{   
    Plorg plorg;
    int user_satis = 0;

    plorg.report_info();

    std::cout << "Enter your satisfaction please: ";
    std::cin >> user_satis;

    plorg.modify_satisfaction(user_satis);

    plorg.report_info();

    return EXIT_SUCCESS;
}
