#include "include/vect.h"

using namespace VECTOR;

void print_line(size_t lines);

void print_line(size_t lines)
{
    std::cout.put('\n');
    while (lines--)
    {
        std::cout.put('-');
    }
    std::cout.put('\n');
}

int main(int argc, char const *argv[])
{

    Vector math_vector_1(30.00, 40.00, Vector::RECT);
    Vector math_vector_2(10.00, 20.00, Vector::RECT);

    Vector math_vector_3;

    /*math_vector_1 对象的矢量值*/
    std::cout << "math_vector_1 contence: \n";
    std::cout << math_vector_1;
    math_vector_1.mode_set(Vector::POL);
    std::cout << math_vector_1;
    print_line(25);

    /*math_vector_2 对象的矢量值*/
    std::cout << "math_vector_2 contence: \n";
    std::cout << math_vector_2;
    mode_set(math_vector_2, Vector::POL);
    std::cout << math_vector_2;
    print_line(25);

    /*矢量相加*/
    /*vector_1 + vector_2*/
    std::cout << "vector_1 + vector_2 = \n";
    math_vector_3 = math_vector_1 + math_vector_2;
    std::cout << math_vector_3;
    mode_set(math_vector_3, Vector::POL);
    std::cout << math_vector_3;
    print_line(25);

    /*矢量相减*/
    /*vector_1 - vector_2*/
    std::cout << "vector_1 - vector_2 = \n";
    math_vector_3 = math_vector_1 - math_vector_2;
    std::cout << math_vector_3;
    mode_set(math_vector_3, Vector::POL);
    std::cout << math_vector_3;
    print_line(25);

    /*矢量倍增*/
    /* math_vector_1 * 3*/
    std::cout << "math_vector_1 * 3 = \n";
    math_vector_3 = math_vector_1 * 3;
    std::cout << math_vector_3;
    mode_set(math_vector_3, Vector::POL);
    std::cout << math_vector_3;
    print_line(25);

    return EXIT_SUCCESS;
}
