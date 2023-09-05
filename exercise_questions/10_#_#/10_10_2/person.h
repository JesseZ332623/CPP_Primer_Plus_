#ifndef _PERSON_H_
#define _PERSON_H_

#include <iostream>
#include <string>
#include <cstring>

using std::string;

class Person
{
    private:
        static const int LIMIT = 25;
        string l_name;
        char f_name[LIMIT];

    public:
        Person() { l_name = ""; f_name[0] = '\0'; }
        Person(const string & ln, const char *fn = "Heyyou");

        void Show() const;

        void Formal_Show() const;

        ~Person() {}
};

#endif