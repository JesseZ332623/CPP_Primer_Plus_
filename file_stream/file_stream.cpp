#include <iostream>
#include <fstream>
#include <cstdlib>
#include <array>

int main(int argc, char const *argv[])
{
    std::ofstream file_stream;
    std::array<double, 10> data_list = {0};

    file_stream.open("testing_data.txt");

    file_stream.precision(6);

    std::cout << "Enter the data ";
    for(int data_index = 0; data_index < 10; ++data_index)
    {
        file_stream.width(4);
        std::cout << data_index + 1 << ": ";
        std::cin >> data_list[data_index];
        file_stream << data_list[data_index] << ' ';

        if (data_index % 5 == 0 && data_index != 0)
        {
            file_stream << std::endl;
        }
        
    }

    file_stream.close();

    return EXIT_SUCCESS;
}
