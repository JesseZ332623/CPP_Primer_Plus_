#ifndef _VIRTUAL_FUNC_H_
#define _VIRTUAL_FUNC_H_

#include <iostream>
#include <string>

class Base_Class
{
    private:
        std::string _base_info;

    public:
        Base_Class();
        Base_Class(std::string _b_info);

        virtual void show();

        virtual ~Base_Class();
};

class Driver_Class : public Base_Class
{
    private:
        std::string _driver_info;

    public:
        Driver_Class();
        Driver_Class(std::string _b_info, std::string _d_info);

        //void show();

        ~Driver_Class();
};

#endif