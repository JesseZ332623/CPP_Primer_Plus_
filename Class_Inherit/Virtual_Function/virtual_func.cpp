#include "virtual_func.h"

Base_Class::Base_Class()
{
    _base_info = "Empty string....";
}

Base_Class::Base_Class(std::string _b_info)
{
    std::cout << "Create Base Class" << std::endl;
    _base_info = _b_info;
}

void Base_Class::show()
{
    std::cout << _base_info << std::endl;
}

Base_Class::~Base_Class()
{
    std::cout << "Destroy Base Class" << std::endl;
}

Driver_Class::Driver_Class() : Base_Class()
{
    _driver_info = "Empty string....";
}

Driver_Class::Driver_Class(std::string _b_info, std::string _d_info) : Base_Class(_b_info)
{
    std::cout << "Create Driver Class" << std::endl;
    _driver_info = _d_info;
}

Driver_Class::~Driver_Class()
{
    //Base_Class::~Base_Class();
    std::cout << "Destroy Driver Class" << std::endl;
}