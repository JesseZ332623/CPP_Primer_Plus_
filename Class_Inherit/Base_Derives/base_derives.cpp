#include "./base_derives.h"

Base::Base(int base_data)
{
    std::cout << "The Base Class Created.....\n\n";
    this->base_data = base_data;
}

std::ostream & operator<<(std::ostream & _os, Base & _base)
{
    _os << "Base data = [" << _base.base_data << "]\n\n";

    return _os;
}

Base::~Base()
{
    std::cout << "Destroy Base Class.....\n\n";
}

Derives::Derives(int derives_data) : Base(derives_data)
{
    std::cout << "The Derives Class Created.....\n\n";
    this->_b_dat = get_base_data();
    this->derives_data = derives_data;
}

std::ostream & operator<<(std::ostream & _os, Derives & _derives)
{
    _os << "Base data = [" << _derives._b_dat << "]\n\n";
    _os << "Derives data = [" << _derives.derives_data << "]\n\n";

    return _os;
}

Derives::~Derives()
{
    std::cout << "Destroy Derives Class....\n\n";
}