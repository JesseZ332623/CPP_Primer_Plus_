#ifndef _MY_TIME_0_H_
#define _MY_TIME_0_H_

#include <iostream>

class Time
{
    private:
        int hours;
        int minutes;
    
    public:
        Time();
        Time(int hour, int minutes = 0);

        void add_min(int minutes);

        void add_hour(int hour);

        void reset(int hour = 0, int minutes = 0);

        Time sum(const Time & time) const;

        void show() const;

        ~Time() {}
};

#endif
