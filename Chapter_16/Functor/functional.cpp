#include "./include/defs.h"

#include <functional>
#include <vector>


int main(int argc, char const *argv[])
{
    system("cls");

    std::vector<int> result = {1, 2, 3, 4, 5};

    std::transform(
                    result.begin(), result.end(), 
                    std::ostream_iterator<int, char>(std::cout, " "), 
                    std::bind(std::plus<int>(), std::placeholders::_1, 114514)
                  );



    return EXIT_SUCCESS;
}
