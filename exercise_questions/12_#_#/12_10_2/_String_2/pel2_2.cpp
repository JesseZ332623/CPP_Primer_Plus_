/**
 * pel2_2.cpp
 * @author by Jesse_EC
 * @date 2023.9.28
 * 
 * 一个升级版 _String 类的测试用例，
 * 旨在测试 _String 类的所有功能。
*/

#include "./src/include/_String.h"

using namespace std;

int main(int argc, char const *argv[])
{
    _String s1(" and I am a C++ Student.");
    _String s2 = "Please enter your name: ";
    _String s3;

    cout << s2;
    cin >> s3;

    s2 = "My name is: " + s3;

    cout << s2 << endl;

    s2 = s2 + s1;
    s2.string_upper();

    cout << "The string\n" << s2 << "\ncontains " << s2.appear_times('A')
         << " 'A' characters in it." << endl;

    s1 = "Red";

    _String rgb[3] = {_String(s1), _String("green"), _String("blue")};

    cout << "Enter the name of a primary color for mixing right: ";
    _String ans;

    bool success = false;

    while (cin >> ans)
    {
        ans.string_low();
        for (int index = 0; index < 3; ++index)
        {
            if (ans == rgb[index])
            {
                cout << "That's right!\n";
                success = true;
                break;
            }
        }
        if (success) { break; }
        else
        {
            cout << "Try again!\n";
        }
    }
    
    cout << "Done.";

    return EXIT_SUCCESS;
}
