#ifndef _SPECIALIZATION_H_
#define _SPECIALIZATION_H_

#include <iostream>
#include <string>

/*一个普通的类模板函数*/
template <typename Number>
class Normal_Data
{
    private:
        Number _data;

    public:
        Normal_Data() : _data(0) {}
        Normal_Data(Number _dat) : _data(_dat) {}

        /*获取数据值*/
        Number Get_Data() { return _data; }

        /*计算两个类的数据*/
        Number Caculate(Normal_Data & _dat_1, Normal_Data & _dat_2);

        /*重载 + 计算两个类的数据*/
        Number operator+(Normal_Data & _dat_2);

        /*比较两个类数据是否相等*/
        bool operator==(Normal_Data & _dat_2);

        ~Normal_Data() {}
};

/*针对 double 类型的特化实现*/
template <>
class Normal_Data<double>
{
    private:
        double _data;

    public:
        Normal_Data() : _data(0.0000) {}
        Normal_Data(double _dat) : _data(_dat) {}

        /*获取数据值*/
        double Get_Data() { return _data; }

        /*计算两个类的数据*/
        double Caculate(Normal_Data & _dat_1, Normal_Data & _dat_2);

        /*重载 + 计算两个类的数据*/
        double operator+(Normal_Data & _dat_2);

        /*比较两个类数据是否相等*/
        bool operator==(Normal_Data & _dat_2);

        ~Normal_Data() {}
};

/*针对 std::string 的特化实现*/
template <>
class Normal_Data<std::string>
{
    public:
        using string = std::string;
        using ostream = std::ostream;

    private:
        string _data;
    public:
        Normal_Data() : _data("Null_String") {}
        Normal_Data(string _dat) : _data(_dat) {}

        bool operator==(Normal_Data & _dat_2) { return _data == _dat_2._data; };

        friend ostream & operator<<(ostream & _os, Normal_Data<string> & _str);

        ~Normal_Data() {};
};

#endif