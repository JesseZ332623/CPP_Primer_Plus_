#include "include/_complex.h"
#include <windows.system.h>

using namespace COMPLEX;

int main(int argc, char const *argv[])
{
    system("cls");

    using std::cout, std::cin;

#if true
    Complex a(3.0, 4.0);
    Complex c;
    Complex temp;
    

    cout << "Enter a complex number (q to quit): \n";

    while (cin >> c)
    {
        Complex conjugate_c = ~c;

        cout << "c is: " << c << '\n';
        cout << "complex conjugate is: " << conjugate_c << '\n';
        cout << "a is: " << a << '\n';

        temp = a + c;
        cout << "a + c = " << temp << '\n';

        temp = a - c;
        cout << "a - c = " << temp << '\n';

        temp = a * c;
        cout << "a * c = " << temp << '\n';
        
        //temp = c * 2;
        temp = 2 * c;
        cout << "2 + c = " << temp << '\n';

        cout << "Enter a complex number (q to quit): \n";
        while (cin.get() != '\n')
        {
            continue;
        } 
    }
    
    cout << "\nDone.";
#endif

    return EXIT_SUCCESS;
}
