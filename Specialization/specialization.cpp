#include "./specialization.h"

template <typename Number>
Number Normal_Data<Number>::Caculate(Normal_Data & _dat_1, Normal_Data & _dat_2)
{
    return _dat_1.Get_Data() + _dat_2.Get_Data();
}

template <typename Number>
Number Normal_Data<Number>::operator+(Normal_Data & _dat_2)
{
    return Get_Data() + _dat_2.Get_Data();
}

template <typename Number>
bool Normal_Data<Number>::operator==(Normal_Data & _dat_2)
{
    return Get_Data() == _dat_2.Get_Data();
}

double Normal_Data<double>::Caculate(Normal_Data & _dat_1, Normal_Data & _dat_2)
{
    return Get_Data() + _dat_2.Get_Data();
}

double Normal_Data<double>::operator+(Normal_Data & _dat_2)
{
    return Get_Data() + _dat_2.Get_Data();
}

bool Normal_Data<double>::operator==(Normal_Data & _dat_2)
{
    return Get_Data() == _dat_2.Get_Data();
}

std::ostream & operator<<(std::ostream & _os, Normal_Data<std::string> & _str)
{
    _os << _str._data << std::endl;

    return _os;
}