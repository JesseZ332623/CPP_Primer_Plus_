#ifndef _VINTAGE_PORT_H_
#define _VINTAGE_PORT_H_

#include "./Port.h"

const int NICKNAME_LENGTH = 25;

const int NICKNAME_TYPES = 3;

const char NICKNAME_LIST[NICKNAME_TYPES][NICKNAME_LENGTH] = 
{
    "i.e.", "The Noble or Old Velvet", "etc."
};

class Vintage_Port : public Port
{
    private:
        char *nick_name;
        int years;

    public:
        Vintage_Port();
        Vintage_Port(const char *br, int bott, const char *n_name, int year);
        Vintage_Port(const Vintage_Port & vintage_port);

        Vintage_Port & operator=(const Vintage_Port & vintage_port);

        void Show() const;

        friend ostream & operator<<(ostream & _os, const Vintage_Port & vintage);

        ~Vintage_Port() { delete[] nick_name; }
};

#endif