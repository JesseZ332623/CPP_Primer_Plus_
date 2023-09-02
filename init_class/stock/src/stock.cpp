#include "./stock.h"



Stock::Stock()
{
    company = "No Name";
    shares = 0;
    share_val = 0.00;
    total_val = 0.00;
}

Stock::Stock(const std::string company, long n, double pr)
{
    this->company = company;

    if (n < 0)
    {
        color_t.text_color(RED);
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
        color_t.text_color(RED);
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
        color_t.text_color(RED);
        std::cout << "Number of shares purchased can't be negative."
                  << "Transaction is aborted." << std::endl;
        color_t.text_color(WHITE);
    }
    else if (number > shares)
    {
        color_t.text_color(RED);
        cout << "You can't sell more than you have!"
             << "Transaction is aborted." << std::endl;
        color_t.text_color(WHITE);
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

    cout << "---------------------------------------" << endl;
    cout << "Company: " << company << ' ';
    cout << "Shares: " << shares << endl;
    cout << "Share price: $" << share_val << endl;

    cout.precision(2);
    cout << "Total worth: $" << total_val << endl;

    cout.setf(orig, ios_base::floatfield);
    cout.precision(prec);
    cout << "---------------------------------------" << endl;
}

const Stock &Stock::top_value(Stock &stock) const
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

Stock::~Stock()
{
    //color_t.text_color(RED);
    std::cout << "\033[31mclass [stock] deleted.....\033[0m\n";
}