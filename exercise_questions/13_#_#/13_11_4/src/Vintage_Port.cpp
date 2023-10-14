#include "./include/Vintage_Port.h"

Vintage_Port::Vintage_Port() : Port()
{
    nick_name = new char[NICKNAME_LENGTH];
    years = 0;
}

/*基类中的 style 必须是 vintage*/
Vintage_Port::Vintage_Port(const char *br, int bott, 
                           const char *n_name, int year) : Port(br, BRAND_LIST[3], bott)
{
    if (std::strlen(n_name) > NICKNAME_LENGTH)
    {
        nick_name = new char[NICKNAME_LENGTH];
        std::strcpy(nick_name, "Over Length!");
    }
    else
    {
        nick_name = new char[std::strlen(n_name) + 1];
        std::strcpy(nick_name, n_name);
    }

    years = year;
}

Vintage_Port::Vintage_Port(const Vintage_Port & vintage_port) : Port(vintage_port)
{
    nick_name = new char[std::strlen(vintage_port.nick_name) + 1];

    std::strcpy(nick_name, vintage_port.nick_name);
    years = vintage_port.years;
}

Vintage_Port & Vintage_Port::operator=(const Vintage_Port & vintage_port)
{
    if (this == &vintage_port) { return *this; }

    delete[] nick_name;

    Port::operator=(vintage_port);
    nick_name = new char[std::strlen(vintage_port.nick_name) + 1];
    std::strcpy(nick_name, vintage_port.nick_name);
    years = vintage_port.years;

    return *this;
}

void Vintage_Port::Show() const
{
    Port::Show();
    cout << "Nick Name: " << nick_name << endl;
    cout << "Years: " << years << endl; 
}

ostream & operator<<(ostream & _os, const Vintage_Port & vintage)
{
    _os << (Port)vintage << ", ";
    _os << vintage.nick_name << ", " << vintage.years;

    return _os;
}