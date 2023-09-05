#include "move_def.h"

Move::Move(double a, double b)
{
    x = a;
    y = b;
}

void Move::show_move() const
{
    using std::cout;

    cout << "x = " << x << ' '
         << "y = " << y << std::endl;
}

Move Move::add(const Move & m) const
{
    Move temp;
    temp.x = m.x;
    temp.y = m.y;

    return temp;
}

void Move::reset(double a, double b)
{
    x = a;
    x = b;
}