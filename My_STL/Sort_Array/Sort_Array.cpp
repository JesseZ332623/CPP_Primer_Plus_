/*为 Sort_Array 编写一个测试用例*/

#include "./Sort_Array.h"
#include <string>
#include <array>

/*学生人数*/
const size_t SIZE = 10;

int main(int argc, char const *argv[])
{

#if false
    system("cls");
    double *score = new double[SIZE];

    double value = 0.0;
    std::cout << "Enter Student score (Student Count: " << SIZE << "): " << std::endl;

    for (int index = 0; index < SIZE; ++index)
    {
        std::cin >> value;
        score[index] = value;
    }
    
    Sorted_Array<double, SIZE> score_array = score;

    std::cout << "----------------------------------------------------------" << std::endl;

    std::cout << score_array << std::endl;

    std::cout << "The No.1 Student score: " << *score_array.begin() << '\n';
    std::cout << "The Bed Student score: " << *score_array.end() << '\n';

    delete[] score;

#endif

    std::array<const char *, 10> arr;

    
    

    return EXIT_SUCCESS;
}
