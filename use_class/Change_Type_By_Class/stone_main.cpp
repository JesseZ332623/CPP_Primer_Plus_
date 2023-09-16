#include "stone_wt.h"
using std::cout;

void display(const Stonewt & stone_t, int n);

void display(const Stonewt & stone_t, int n)
{
    for (int i = 0; i < n; ++i)
    {
        std::cout << "Wow! ";
        stone_t.show_stn();
    }
}

int main(int argc, char const *argv[])
{
#if false
    Stonewt incognito = 275;
    Stonewt wolfe(285.7);
    Stonewt taft(21, 8);

    cout << "The celebrity weighed. ";
    incognito.show_stn();

    cout << "The detective weighed. ";
    wolfe.show_stn(); 

    cout << "The President weighed. ";
    taft.show_lbs();

    display(taft, 2);
    display(422, 2);
#endif

    //Stonewt stont_t(10, 25.58);
    Stonewt stont_t = Stonewt(9, 2.8);

    

    std::cout << "converse to int => ";
    std::cout << int(stont_t) << " pounds.\n";

    std::cout << "coverse to double => ";
    std::cout << double(stont_t) << " pounds.\n";

    return EXIT_SUCCESS;
}


