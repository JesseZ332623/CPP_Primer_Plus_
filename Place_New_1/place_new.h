#ifndef _PLACE_NEW_
#define _PLACE_NEW_

#include <iostream>
#include <string>
#include <new>

using std::string;
using std::cin, std::cout;

const int BUFFER = 512;

class Place_New
{
    private:
        string words;
        int number;

    public:
        Place_New(const string & _str = "Just Testing...", int n = 0)
        {
            words = _str;
            number = n;

            cout << words << " was constructed.\n";
        }

        void show()
        {
            cout << "class data(int)" << number << std::endl;
            cout << "string contence: " << words;
        }

        ~Place_New() {}

};

#endif 