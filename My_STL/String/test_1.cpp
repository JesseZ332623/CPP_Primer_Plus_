#include "./src/include/_String.h"

using std::cout, std::cin;

const int set_size = 2;

int main(int argc, char const *argv[])
{
    _String *str_set = new _String[set_size];

    for (int index = 0; index < set_size; ++index)
    {
        cout << "Enter the str " << '[' << index << "]: ";
        cin >> str_set[index];
    }

    cout << str_set[0] << std::endl;
    cout << str_set[1] << std::endl;

    if (str_set[0] > str_set[1])
    {
        cout << str_set[0] << std::endl;
    }
    else if (str_set[0] < str_set[1])
    {
        cout << str_set[1] << std::endl;
    }
    else 
    {
        cout << "Equal string...." << std::endl;
    }

    cout << "The number of _String object: " << _String::String_Count() << std::endl;

    delete[] str_set;

    cout << "The number of _String object: " << _String::String_Count() << std::endl;

    return EXIT_SUCCESS;
}
