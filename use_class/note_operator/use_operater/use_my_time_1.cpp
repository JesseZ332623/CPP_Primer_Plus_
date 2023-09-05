#include "my_time_1.h"

const std::string plan_set[3] = 
{
    "Working", "Play", "Sleep"
};

int main(int argc, char const *argv[])
{
    using std::cout, std::endl;

    Time *my_time_set = new Time[3]
    {
        Time(3, 45),        /*Working*/
        Time(8, 32),        /*Play*/
        Time(12, 43)        /*Sleep*/
    };
    Time total_time;

    for (int index = 0; index < 3; ++index)
    {
        my_time_set[index].show();
        total_time = total_time + my_time_set[index];
    }

    Time _temp_total = my_time_set[0].operator+(my_time_set[1]);
    cout << plan_set[0] << " + " << plan_set[1] << " = ";
     _temp_total.show();

    cout << "Today I spand: ";

    total_time.show();

    delete[] my_time_set;
    
    return EXIT_SUCCESS;
}