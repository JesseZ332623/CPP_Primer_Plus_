#ifndef _STOCK_H_
#define _STOCK_H_

#include <iostream>
#include <string>

#include "change_terminal_color.h"

class Stock
{
    private:    
        std::string company;
        int shares;
        double share_val;
        double total_val;
        void set_total() { total_val = shares * share_val; }

    public:
        Change_Color color_t;
        Stock();
        Stock(const std::string company, long n = 0, double pr = 0.000);

        void buy(long number, double price);

        void sell(long number, double price);

        void update(double price);

        void show() const;

        const Stock & top_value(Stock & stock) const;

        ~Stock();
};



#endif

