#include "include/_complex.h"

using namespace COMPLEX;

Complex::Complex()
{
    real_number = 0.0000;
    imaginary_number = 0.0000;
}

Complex::Complex(double real_num, double imaginary_num)
{
    real_number = real_num;
    imaginary_number = imaginary_num;
}

Complex Complex::operator+(Complex & comp_2) const
{
    return Complex(real_number + comp_2.real_number, imaginary_number + comp_2.imaginary_number);
}

Complex Complex::operator-(Complex & comp_2) const
{
    return Complex(real_number - comp_2.real_number, imaginary_number - comp_2.imaginary_number);
}

Complex Complex::operator*(Complex & comp_2) const
{
    return Complex(
        (real_number * comp_2.real_number) - imaginary_number * comp_2.imaginary_number,
        (real_number * comp_2.imaginary_number + imaginary_number * comp_2.real_number)
    );
}

Complex Complex::operator*(double x) const
{
    return Complex(x * real_number, x * imaginary_number);
}

Complex Complex::operator~() const
{                                                  
    return Complex(real_number, -imaginary_number);
}