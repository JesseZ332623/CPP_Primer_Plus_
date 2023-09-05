#include "my_time_1.h"

Time::Time()
{
    hours = minutes = 0;
}

Time::Time(int hour, int minutes)
{
    hours = hour;
    this->minutes = minutes;
}

void Time::add_min(int minutes)
{
    this->minutes += minutes;
    hours += this->minutes / 60;
}

void Time::add_hour(int hour)
{
    this->hours += hour;
}

void Time::reset(int hour, int minutes)
{
    hours = hour;
    this->minutes = minutes;
}

Time Time::operator+(const Time & time) const
{
    Time sum;
    sum.minutes = minutes + time.minutes;
    sum.hours = hours + time.hours + sum.minutes / 60;
    sum.minutes %= 60;  

    return sum;
}

void Time::show() const
{
    std::cout << hours << " hours, " << minutes << " minutes";
    std::cout.put('\n');
}
