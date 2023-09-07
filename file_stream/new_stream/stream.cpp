#include <fstream>
#include <iostream>
#include <vector>

const size_t data_len = 5;
const double arr_list[data_len] = {63.857, 1341.89564, 5203.357, 356.14, 90.56478};

/**
  将数组的数据写入 vector 中，并返回该 vector 的迭代器
* @param array_list a double type array
* @return std::vector<double>::iterator
*/
std::vector<double>::iterator writer_vecter_data(const double *array_list);

void write_data_infile();

std::vector<double>::iterator writer_vecter_data(const double *array_list)
{  
    std::vector<double> temp_data;
    
    if (!arr_list)
    {
        return temp_data.begin();
    }

    for (int index = 0; index < data_len; ++index)
    {
        temp_data.push_back(array_list[index]);
    }

    return temp_data.begin();
}

void write_data_infile()
{
    std::vector<double>::iterator data_iter;

    std::fstream file("vector_data.txt", std::ios::out);

    if (!file)
    {
        std::cerr << "Create file failed...\n";
        exit(EXIT_FAILURE);
    }

    data_iter = writer_vecter_data(arr_list);

    for (size_t index = 0; index < data_len; ++index)
    {
        file << *data_iter++ << '\t';
    }

    file.close();
}

int main(int argc, char const *argv[])
{  
    write_data_infile();
    
    return EXIT_SUCCESS;
}
