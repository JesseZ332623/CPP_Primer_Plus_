#include "vect.h"
#include <cmath>

using std::sqrt, std::sin, std::cos, std::atan, std::atan2, std::pow;
using std::cout;

namespace VECTOR
{
    const double Red_to_Deg = 45.00 / atan(1.0);

    void Vector::set_mag()
    {
        mag = sqrt(pow(x, 2) + pow(y, 2));
    }

    void Vector::set_ang()
    {
        if (x == 0.0 && y == 0.0)
        {
            ang = 0.0;
        }
        else
        {
            ang = atan2(y, x);
        }
    }

    void Vector::set_x()
    {
        x = mag * cos(ang);
    }

    void Vector::set_y()
    {
        y = mag * sin(ang);
    }

    Vector::Vector()
    {
        mag = ang = 0;
        x = y = 0;
        mode = RECT;
    }

    Vector::Vector(double n1, double n2, Mode form)
    {
        mode = form;

        if (mode == RECT)
        {
            x = n1;
            y = n2;

            set_mag();
            set_ang();
        }
        else if (mode == POL)
        {
            mag = n1;
            ang = n2 / Red_to_Deg;

            set_x();
            set_y();
        }
        else 
        {
            cout << "Incurrent to 3rd argument to Vector() --";
            cout << "Vecter data set to 0." << std::endl;
            mag = ang = 0;
            x = y = 0;
            mode = RECT;
        }
    }

    void Vector::reset(double n1, double n2, Mode form)
    {
        mode = form;

        if (mode == RECT)
        {
            x = n1;
            y = n2;

            set_x();
            set_y();
        }
        else if (mode == POL)
        {
            mag = n1;
            ang = n2 / Red_to_Deg;

            set_mag();
            set_ang();
        }
        else 
        {
            cout << "Incurrent to 3rd argument to Vector() --";
            cout << "Vecter data set to 0." << std::endl;
            mag = ang = 0;
            x = y = 0;
            mode = RECT;
        }
    }

    void Vector::mode_set(Mode _mode)
    {
        mode = _mode;
    }

    Vector Vector::operator+(const Vector & vec) const
    {
        return Vector(x + vec.x, y + vec.y);
    }

    Vector Vector::operator-(const Vector & vec) const
    {
        return Vector(x - vec.x, y - vec.y);
    }

    Vector Vector::operator-() const
    {
        return Vector(-x, -y);
    }

    Vector Vector::operator*(double n) const
    {
        return Vector(x * n, y * n);
    }

    Vector operator*(double n, const Vector & vec)
    {
        return n * vec;
    }

    std::ostream & operator<<(std::ostream & os, Vector & vec)
    {
        if (vec.mode == Vector::RECT)
        {
            os << "(x, y) = (" << vec.x << ',' << vec.y << ')';
            os.put('\n');
        }
        else if (vec.mode == Vector::POL)
        {
            os << "(m, a) = (" << vec.mag << ',' << vec.ang * Red_to_Deg << ')';
            os.put('\n');
        }
        else
        {
            os << "Vector object mode is invalid" << std::endl;
        }

        return os;
    }

    void _mode_set(Vector & vec, VECTOR::Vector::Mode _mode)
    {
        vec.mode_set(_mode);
    }
    
};