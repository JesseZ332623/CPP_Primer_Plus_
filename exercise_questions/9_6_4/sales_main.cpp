#include "sales.h"

using namespace SALES;
using std::vector;

int main(int argc, char const *argv[])
{
    system("cls");

    struct sales sales;
    vector<double> data = {9.8765, 457.5879, 231.11, 224.09};
    sales._sales.reserve(QUARTES);  

    Set_Sales(sales);
    Show_Sales(sales);

    sales._sales.clear();
    
    Set_Sales(sales, data, QUARTES);
    Show_Sales(sales);

    return EXIT_SUCCESS;
}

