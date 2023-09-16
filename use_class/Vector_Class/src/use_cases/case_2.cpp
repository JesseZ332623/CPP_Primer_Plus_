#include "include/vect.h"

using namespace VECTOR;

int main(int argc, char const *argv[])
{
    Vector vector_1(30, 40, Vector::RECT);

    double vector_length = double(vector_1);

    std::cout << "Length of vector = " << vector_length;
    
    
    return EXIT_SUCCESS;
}
