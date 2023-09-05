#include "struct_operater.h"

_Operater::_Operater()
{
    _operater = new Operater_Struct;

    strcpy(_operater->discrible, "Empty String.");
    _operater->data = 0.00;
}

_Operater::_Operater(const char *discrible, double data)
{
    _operater = new Operater_Struct;

    strcpy(_operater->discrible, discrible);
    _operater->data = data;
}

_Operater * _Operater::operator+(const _Operater & oper_1) const
{
    _Operater *temp_oper = new _Operater;

    strcpy(temp_oper->_operater->discrible, this->_operater->discrible);
    strcat(temp_oper->_operater->discrible, oper_1._operater->discrible);

    temp_oper->_operater->data = this->_operater->data + oper_1._operater->data;

    return temp_oper;
}

void _Operater::show_struct_data() const
{
    using std::cout, std::endl;
    using std::ios_base;

    /*
        set format to $0.00
    */
    ios_base::fmtflags orig =
        cout.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = cout.precision(2);

    cout << "Struct discrible: " << _operater->discrible << ' ';
    cout << "Struct data: " << _operater->data << endl;
}

_Operater::~_Operater()
{
    delete _operater;
}