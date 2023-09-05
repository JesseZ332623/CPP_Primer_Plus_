#include "my_time_1.h"

int main(int argc, char const *argv[])
{
    using std::cout, std::endl;

    Time *my_time_set = new Time[3]
    {
        Time(3, 45),
        Time(8, 32),
        Time(12, 43)
    };
    Time total_time;

    for (int index = 0; index < 3; ++index)
    {
        total_time = total_time + my_time_set[index];
    }

    total_time.show();

    delete[] my_time_set;
    
    return EXIT_SUCCESS;
}
