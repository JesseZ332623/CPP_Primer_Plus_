#include "./my_array.h"

int main(int argc, char const *argv[])
{
    using namespace My_Array;

    int array[4] = { 1536, 3567, 768, 34 };

    //PT<int> _new_pt(123);
    Array _new_arr(array, 4);

    std::cout << _new_arr[0] << ' ' << _new_arr.size() << ' ' << _new_arr.capacity() << '\n';

    _new_arr.push_back(123);

    for (int i = 0; i < 5; ++i)
    {
        std::cout << _new_arr[i] << '\t';
    } 

    return EXIT_SUCCESS;
}