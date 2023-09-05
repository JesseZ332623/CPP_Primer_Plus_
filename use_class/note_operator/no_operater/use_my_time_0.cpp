#include "my_time_0.h"

int main(int argc, char const *argv[])
{
    using std::endl, std::cout;

    Time planning(1, 45), codding(2, 40), fixing(5, 55);
    Time total;

    cout << "planning time: ";
    planning.show();

    cout << "coding time: ";
    codding.show();

    cout << "fixing time: ";
    fixing.show();

    total = codding.sum(fixing);
    total = total.sum(planning);

    cout << "Today I spand ";
    total.show();
    
    return EXIT_SUCCESS;
}
