#include "stock.h"

Stock::_Stock_()
{
    company = "No Name";
    shares = 0;
    share_val = 0.00;
    total_val = 0.00;
}

Stock::_Stock_(const std::string company, long n = 0, double pr = 0.000)
{
    this->company = company;

    if (n < 0)
    {
        std::cout << "Number of shars can't be negative.";
        std::cout << this->company << "Share set to 0." << std::endl;

        shares = 0;
    }
    else
    {
        shares = n;
    }
    share_val = pr;
    set_total();
}

void Stock::buy(long number, double price)
{
    if (number < 0)
    {
        std::cout << "Number of shares purchased can't be negative."
        << "Transaction is aborted." << std::endl;
    } 
    else
    {
        shares += number;
        share_val = price;
        set_total();
    }
}

void Stock::sell(long number, double price)
{
    using std::cout;

    if (number < 0)
    {
       std::cout << "Number of shares purchased can't be negative."
        << "Transaction is aborted." << std::endl;
    }
    else if (number > shares)
    {
        cout << "You can't sell more than you have!"
        << "Transaction is aborted." << std::endl;
    }
    else
    {
        shares -= number;
        share_val = price;
        set_total();
    }
}

void Stock::update(double price)
{
    share_val = price;
    set_total();
}

void Stock::show() const
{
    using std::ios_base, std::cout, std::endl;

    /*
        set format to $0.000
    */
    ios_base::fmtflags orig = 
        cout.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = cout.precision(3);

    cout << "Company: " << company;
    cout << "Shares: " << shares << endl;
    cout << "Share price: $" << share_val << endl;

    cout.precision(2);
    cout << "Total worth: $" << total_val << endl; 

    cout.setf(orig, ios_base::floatfield);
    cout.precision(prec);
}

const _Stock_ & Stock::top_value(_Stock_ & stock) const
{
    if (stock.total_val > total_val)
    {
        return stock;
    }
    else
    {
        return *this;
    }
    
}

Stock::~_Stock_()
{
    std::cout << "class [stock] deleted.....\n";
}