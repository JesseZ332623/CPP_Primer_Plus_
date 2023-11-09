#include "./explicit_sp.h"

int main(int argc, char const *argv[])
{
    int arr[5] = {1, 5, 14, 7, 2};
    int arr_2[6] = {5316, 2546724, 2467, 45867, 78, 43};

    Sorted_Array<int, 5> _s_arr(arr);
    Sorted_Array<int, 6> _s_arr_2 = {5316, 2546724, 2467, 45867, 78, 43};

    std::cout << _s_arr << '\n' << _s_arr_2 << '\n';


    printf("%d", *(_s_arr_2.end() - 1));

    //printf("%s", (_s_arr == _s_arr_2) ? "true" : "false");
    
    return EXIT_SUCCESS;
}
