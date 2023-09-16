#ifndef _COMPLEX_H_
#define _COMPLEX_H_

#include <iostream>

namespace COMPLEX
{
    class Complex
    {
        private:
            double real_number;
            double imaginary_number;
        
        public:
            Complex();
            Complex(double real_number, double imaginary_number);

            void set_real(double real_num) { real_number = real_num; }
            void set_imaginary(long double imag_num) { imaginary_number = imag_num; }

            Complex operator+(Complex & comp_2) const;

            Complex operator-(Complex & comp_2) const;

            Complex operator*(Complex & comp_2) const;

            Complex operator*(double x) const;
            friend Complex operator*(double x, Complex & comp)
            {
                return Complex(x * comp.real_number, x * comp.imaginary_number);
            }

            Complex operator~() const;

            friend std::ostream & operator<<(std::ostream & _os, Complex & comp)
            {
                _os << '(' << comp.real_number << ", " << comp.imaginary_number << "i)";

                return _os;
            }

            friend std::istream & operator>>(std::istream & _enter, Complex & comp)
            {
                double real_number;
                double imaginary_number;   

                std::cout << "Real Number: ";
                _enter >> real_number;

                std::cout << "Imaginary Numbe: ";
                _enter >> imaginary_number;

                comp.set_real(real_number);
                comp.set_imaginary(imaginary_number);

                return _enter;
            }

            ~Complex() {}
    };
};

#endif
