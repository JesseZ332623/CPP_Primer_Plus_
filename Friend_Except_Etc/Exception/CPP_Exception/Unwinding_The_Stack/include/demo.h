#ifndef _DEMO_H_
#define _DEMO_H_

#include "./def.h"

class Demo
{
    private:
        std::string _word;

    public:
        Demo(const std::string _str);

        void show() const;

        ~Demo();
};

Demo::Demo(const std::string _str)
{
    _word = _str;
    printf("Demo %s Created.\n", _word.c_str());
}

void Demo::show() const
{
    printf("Demo %s is lives!\n", _word.c_str());
}

Demo::~Demo()
{
    printf("Demo %s Destroyed.\n", _word.c_str());
}

#endif