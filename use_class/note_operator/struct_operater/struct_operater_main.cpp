#include "struct_operater.h"

int main(int argc, char const *argv[])
{
    system("cls");

    _Operater _operater_[3]
    {
        _Operater("Hello ", 41.21),
        _Operater("World! ", 21.65),
        _Operater("Jesse is here.", 100.01)
    };
    std::string str = "Good Job for codding!";

    _operater_[0].show_struct_data();
    _operater_[1].show_struct_data();

    _Operater *temp_oper;

    temp_oper = _operater_[0] + _operater_[1];

    temp_oper->show_struct_data();
    
    delete temp_oper;

    return EXIT_SUCCESS;
}
