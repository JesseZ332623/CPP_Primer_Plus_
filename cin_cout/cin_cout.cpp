#include <iostream>

using namespace std;

void Use_Cin_Cout()
{
    cout << __FILE__ << __DATE__ << __TIME__ << endl;

    int value = 0;

    cout << "Enter something:" << endl;

    cin >> value;

    cout << "The value of this is:" << value << '.';

    cout << "Bye Jesse_EC";
}

