#include <iostream>

inline double sqrt_func(double x) { return x * x; }

double sqrt_func_(double x) { return x * x; }

int main(int argc, char const *argv[])
{
    int arguement = 10;
    double value_1 = sqrt_func(++arguement); 
    double value_2 = sqrt_func_(12.765 + 67548);

    std::cout << value_1 << ' ' << value_2;

    return EXIT_SUCCESS;
}
