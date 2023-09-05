#include "struct_operater.h"


int main(int argc, char const *argv[])
{
    system("cls");

    _Operater _operater_[2]
    {
        _Operater("Hello ", 10.00),
        _Operater("World!", 21.00)
    };

    _Operater *temp_oper = _operater_[0] + _operater_[1];

    _operater_[0].show_struct_data();
    _operater_[1].show_struct_data();

    temp_oper->show_struct_data();
    
    delete temp_oper;

    return EXIT_SUCCESS;
}
