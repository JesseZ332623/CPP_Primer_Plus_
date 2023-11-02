#include <iostream>
#include <cstring>
#include "./multiple_inheritance.h"

const int LIMIT = 5;

int main(int argc, char const *argv[])
{
    using std::cout, std::cin, std::endl;
    using std::strchr;

    Worker *lolas[LIMIT];
    int ct = 0;

    for (ct; ct < LIMIT; ++ct)
    {
        char choice;
        cout << "Enter the employee category: \n"
             << "w: waiter \t  s: singer \t"
             << "t: singing_waiter \t q: quit\n";
        cin >> choice;

        while (strchr("wstq", choice) == NULL)
        {
            cout << "Please enter a w, s, t or q: ";
            cin >> choice;
        }
        if (choice == 'q') { break; }

        switch (choice)
        {
            case 'w': lolas[ct] = new Waiter; break;
            case 's': lolas[ct] = new Singer; break;
            case 't': lolas[ct] = new SingingWaiter; break;
        }
        cin.get();
        lolas[ct]->set();
    }
    system("cls");
    cout << "Here ia your Staff: \n";
    int index = 0;

    for (index; index < ct; ++index)
    {
        cout << endl;
        lolas[index]->show();
    }
    for (index = 0; index < ct; ++index) { delete lolas[index]; }
  
    cout << "Bye!\n";
    
    return EXIT_SUCCESS;
}