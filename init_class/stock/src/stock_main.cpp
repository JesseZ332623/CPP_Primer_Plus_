#include "./stock.h"

using namespace std;

const int STOCKS = 4;

int main(int argc, char const *argv[])
{
    Change_Color text_color;
    cout << argc << ' ' << argv[0] << endl;

    Stock stocks[STOCKS] = 
    {
        Stock("Nano_Smart", 12, 20.0),
        Stock("Boffo_Objects", 200, 2.0),
        Stock("Momolithic_Obelisks", 130, 3.25),
        Stock("Fleep_Enterprices", 60, 6.5)     
    };

    const Stock *top = stocks;
    int cl_index = 0;

    text_color.text_color(BLUE);
    cout << "The stock array contence: " << endl;
    for (cl_index; cl_index < STOCKS; ++cl_index)
    {
        stocks[cl_index].show();
    }
    text_color.text_color(WHITE);

    /*
        找出最大值 
        这个原理类似于选择排序，一第一个元素为基准，
        于其余元素依次比较，直到找到最大值。
    */
#if true
    cl_index = 1;
    for (cl_index; cl_index < STOCKS; ++cl_index)
    {
        top = &top->top_value(stocks[cl_index]);
    }

    text_color.text_color(GREEN);
    cout << "The most valuable holding:" << endl;
    top->show();
    text_color.text_color(WHITE);
    
#endif
    
    return EXIT_SUCCESS;
}
