#ifndef _STONE_WT_
#define _STONE_WT_

#include <iostream>
#include <string>

class Stonewt
{
    private:
        enum { LBS_PER_STN = 14 };      /* 1 英石 = 14 磅 */

        int stone;
        double pds_left;
        double pounds;
    
    public:
        Stonewt();
        Stonewt(double lbs);
        Stonewt(int stn, double lbs);
        
        void show_lbs() const;
        void show_stn() const;

        /*conversion function*/
        explicit operator int() const;
        explicit operator double() const;

        ~Stonewt() {};
};

#endif
