#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>

int main(int argc, char const *argv[])
{
    int array[3] = {1, 2, 3};
    
    std::ofstream file("array contence.txt", std::ios::app);

    std::ostream_iterator<int, char> out_iter(std::cout, " ");
    std::ostream_iterator<int, char> file_out_iter(file, " ");

    std::copy(array, array + 3, out_iter);
    std::copy(array, array + 3, file_out_iter);

    file.close();

    return 0;
}
