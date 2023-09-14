#ifndef _BASIC_CLASS_DEF_H_
#define _BASIC_CLASS_DEF_H_

#include <iostream>
#include <string>
#include <vector>
#include <list>

class Basic_Class
{
    private:
        std::string basic_class_desc;
        std::vector<double> class_data;

    public:
        Basic_Class();
        Basic_Class(std::string str, std::vector<double> data);

        const std::vector<double> ret_class_dat() { return class_data; }

        virtual bool copy_data(Basic_Class & tar, size_t copy_count) const;

        virtual void show_data();

        ~Basic_Class() {}
};

class Derive_Class : private Basic_Class
{
    private:
        std::list<int> *list_data;

    public:
        Derive_Class();
        Derive_Class(std::list<int> & dat);

        bool copy_data(Derive_Class & tar) const;

        void show_data();


        ~Derive_Class();

};

#endif