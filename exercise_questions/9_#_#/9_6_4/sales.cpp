#include "sales.h"

using namespace SALES;

/*计算数据的 平均值 最大值 最小值*/
inline double get_max_val(std::vector<double> &_sales)
{ 
    std::vector<double>::iterator max_iter = std::max_element(std::begin(_sales), std::end(_sales));

    return *max_iter;
}

inline double get_min_val(std::vector<double> &_sales)
{
    std::vector<double>::iterator min_iter = std::min_element(_sales.begin(), _sales.end());

    return *min_iter;
}

inline double get_average_val(std::vector<double> &_sales)
{
    double total = 0.00;
    int element_count = 0;
    std::vector<double>::iterator iter = _sales.begin();

    for (iter; iter < _sales.end(); ++iter)
    {
        total += *iter;
        ++element_count;
    }

    return total / element_count;
}
namespace SALES
{
    /*计算*/
    double Calculate(std::vector<double> &_sales, double (*get_val)(std::vector<double> &_sales))
    {
        return get_val(_sales);
    }

    /*设置sales结构体的值*/
    /*
        将矢量 arr 的数据 写入 sales 结构体中，
        并计算这些数据的最大值，最小值，平均值，并写入
    */
    void Set_Sales(sales &sale, std::vector<double> arr, int n)
    {
        sale._sales.reserve(n);
        int index = 0;
        
        for (index; index < n; ++index)
        {
            sale._sales.push_back(arr[index]);
        }

        sale.max = Calculate(sale._sales, get_max_val);
        sale.min = Calculate(sale._sales, get_min_val);
        sale.average = Calculate(sale._sales, get_average_val);
    }

    /*Set_Sales 函数的第一个重载*/
    /*
        只需传入sales结构体的引用，
        靠cin 和 cout 来提示用户输入数据
    */
    void Set_Sales(sales &sale)
    {
        using std::cout, std::cin, std::endl;
        double dat = 0.000;
        

        cout << "Enter the data contence (size: " << QUARTES << ')' << endl;
       
        for (int index = 0; index < QUARTES; ++index)
        {
            cin >> dat;
            sale._sales.push_back(dat);
        }

        sale.max = Calculate(sale._sales, get_max_val);
        sale.min = Calculate(sale._sales, get_min_val);
        sale.average = Calculate(sale._sales, get_average_val);
    }

    /*展示 Set_Sales 结构体的数据*/
    void Show_Sales(const sales &sale)
    {
        using std::cout, std::endl;

        auto iter = sale._sales.begin();

        cout << "--------------------------------------------" << endl;
        cout << "The Sale Contence: " << endl;
        for (iter; iter < sale._sales.end(); ++iter)
        {
            cout << *iter << '\t';
        }
        cout << endl;
        cout << "max value: " << sale.max << endl;
        cout << "min value: " << sale.min << endl;
        cout << "average value: " << sale.average << endl;
        cout << "--------------------------------------------" << endl;
    }
}