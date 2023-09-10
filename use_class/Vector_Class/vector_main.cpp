#include "vect.h"

using namespace VECTOR;

int main(int argc, char const *argv[])
{

    Vector math_vector_1(30.00, 40.00, Vector::RECT);
    Vector math_vector_2(10.00, 20.00, Vector::RECT);

    Vector math_vector_3;

    std::cout << math_vector_1;
    math_vector_1.mode_set(Vector::POL);
    std::cout << math_vector_1;


    std::cout << math_vector_2;
    _mode_set(math_vector_2, Vector::POL);
    std::cout << math_vector_2;

    math_vector_3 = math_vector_1 + math_vector_2;

    std::cout << math_vector_3;

    return EXIT_SUCCESS;
}
