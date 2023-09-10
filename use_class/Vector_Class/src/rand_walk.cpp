#include "include/vect.h"
#include <cstdlib>
#include <ctime>
#include <windows.system.h>

int main(int argc, char const *argv[])
{
    using namespace std;
    using VECTOR::Vector;

    system("cls");

    srand(time(0));

    Vector step;
    Vector result(0.00, 0.00, Vector::RECT);

    double direction = 0.00;
    double target = 0.00;
    double d_step = 0.00;

    unsigned long int steps = 0;
    
    cout << "Enter target distance (q to quit): ";
    while (cin >> target)
    {
        cout << "Enter step length: ";
        if (!(cin >> d_step))
        {
            break;
        }

        while (result.magval() < target)
        {
            direction = rand() % 360;
            step.reset(d_step, direction, Vector::POL);
            result = result + step;
            steps++;
        }
        cout << "After " << steps << " steps, the subject "
                                     "has the following location:\n";
        cout << result;
        result.mode_set(Vector::POL);
        cout << result << endl;
        cout << "Average outward distance per step = "
             << result.magval() / steps << endl;
        steps = 0;
        result.reset(0.00, 0.00, Vector::RECT);
        cout << "Enter target distance (q to quit): ";                            
    }
    cout << "Bye!\n";
    cin.clear();
    while (cin.get() != '\n')
    {
        continue;
    }

    return EXIT_SUCCESS;
}
