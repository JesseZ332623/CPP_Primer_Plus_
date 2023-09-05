#ifndef _PLORG_H_
#define _PLORG_H_

#include <iostream>
#include <cstring>

const size_t NAME_LEN = 19;

class Plorg
{
    private:
        std::string name;
        int satisfaction;

    public:
        Plorg(std::string name = "Plorga", int satisfaction = 50);

        void modify_satisfaction(int & satisfaction);

        void report_info() const;

        ~Plorg() {}
};

#endif