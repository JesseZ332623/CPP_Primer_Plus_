#include "./emp.h"

int main(int argc, char const *argv[])
{
    Employee _em("Trip", "Harris", "Thumper");

    std::cout << _em << std::endl;

    Manager _ma("Amorphia", "Spindragon", "Nuancer", 5);
    std::cout << _ma << std::endl;

    Fink _fink("Matt", "Oggs", "Oiler", "Juno Barr");
    std::cout << _fink << std::endl;
    _fink.Show_All();

    std::cout << "----------------------------------------------\n";
    Height_Fink _hf(_ma, "Curly Kew");
    _hf.Show_All();

    std::cout << "Press any key for next phase: \n";
    std::cin.get(); system("cls");

    Height_Fink _hf_02;
    _hf_02.Set_All();
    std::cout << _hf_02 << std::endl;

    std::cout << "Using an Abstr_Emp * pointer: " << std::endl;

    Abstr_Emp *_tri[4] = {&_em, &_fink, &_hf, &_hf_02};

    //Abstr_Emp __tri[4] = {_em, _fink, _hf, _hf_02};

    for(int i = 0; i < 4; ++i)
    {
        _tri[i]->Show_All();
    }
    
    return 0;
}
