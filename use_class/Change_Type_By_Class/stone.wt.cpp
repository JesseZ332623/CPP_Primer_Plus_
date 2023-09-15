#include "./stone_wt.h"

Stonewt::Stonewt(double lbs)
{
    stone =  int(lbs);
    pds_left = int(lbs) % LBS_PER_STN + lbs - int(lbs);
    pounds = lbs;
}

Stonewt::Stonewt(int stn, double lbs)
{
    stone = stn;
    pds_left = lbs;
    pounds = stn * LBS_PER_STN + lbs;
}

Stonewt::Stonewt()
{
    stone = pds_left = pounds = 0;
}

void Stonewt::show_lbs() const
{
    std::cout << stone << " stones, " << pds_left << " pounds.\n";
}

void Stonewt::show_stn() const
{
    std::cout << pounds << " pounds.\n";
}

Stonewt::operator int() const
{
    return int(pounds + 0.5);
}

Stonewt::operator double() const
{
    return pounds;
}