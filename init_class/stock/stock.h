#ifndef _STOCK_H_
#define _STOCK_H_

#include <iostream>
#include <string>

class _Stock_
{
    private:    
        std::string company;
        int shares;
        double share_val;
        double total_val;
        void set_total() { total_val = shares * share_val; }

    public:
        _Stock_();
        _Stock_(const std::string company, long n = 0, double pr = 0.000);

        void buy(long number, double price);

        void sell(long number, double price);

        void update(double price);

        void show() const;

        const _Stock_ & top_value(_Stock_ & stock) const;

        ~_Stock_();
};

typedef _Stock_ Stock;

#endif

