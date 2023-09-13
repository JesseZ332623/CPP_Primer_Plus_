#include "./classes_def.h"

int main(int argc, char const *argv[])
{
    using std::cout, std::endl, std::list, std::vector;

    vector<double> vec = {10, 21, 13, 15, 88, 125, 56, 1000, 1332, 170};

    Basic_Class *base_set = new Basic_Class[2]
    {
        Basic_Class(),
        Basic_Class("Basic Class 2", vec)
    };

    base_set[0].show_data();
    base_set[1].show_data();

    base_set[1].copy_data(base_set[0], 5);

    cout << "\nclass 0 data: \n";
    base_set[0].show_data();

    delete[] base_set;
    
    return 0;
}
