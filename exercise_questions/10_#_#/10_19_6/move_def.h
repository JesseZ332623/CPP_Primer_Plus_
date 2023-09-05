#ifndef _MOVE_DEF_H_
#define _MOVE_DEF_H_

#include <iostream>
#include <string>
//#include <windows.system.h>

class Move
{
    private:
        double x;
        double y;

    public:
        Move(double a = 0, double b = 0);

        void show_move() const;

        Move add(const Move & m) const;

        void reset(double a = 0, double b = 0);

        ~Move() {}
};

#endif