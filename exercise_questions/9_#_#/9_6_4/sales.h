#ifndef _SALES_H_
#define _SALES_H_

#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.system.h>

/*计算数据的 平均值 最大值 最小值*/
inline double get_max_val(std::vector<double> &_sales);
inline double get_min_val(std::vector<double> &_sales);
inline double get_average_val(std::vector<double> &_sales);

namespace SALES     /*名称空间 SALES*/
{
    const int QUARTES = 4; 
    
    struct sales
    {
        std::vector<double> _sales;
        double average;
        double max;
        double min;
    };

    /*计算*/
    double Calculate(std::vector<double> &_sales, double (*get_val)(std::vector<double> &_sales));

    /*设置sales结构体的值*/
    /*
        将矢量 arr 的数据 写入 sales 结构体中，
        并计算这些数据的最大值，最小值，平均值，并写入
    */
    void Set_Sales(sales &sale, std::vector<double> arr, int n);

    /*Set_Sales 函数的第一个重载*/
    /*
        只需传入sales结构体的引用，
        靠cin 和 cout 来提示用户输入数据
    */
    void Set_Sales(sales &sale);

    /*展示 Set_Sales 结构体的数据*/
    void Show_Sales(const sales &sale);
} 

#endif