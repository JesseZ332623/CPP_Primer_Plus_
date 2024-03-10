#include "./include/sales.h"

Sales::BadIndex::BadIndex(int __index, 
                          const std::string & __what) : logic_error(__what), bedIndexVal(__index) {}

Sales::Sales(int __year) : year(__year) 
{
    std::memset(this->gross, 0, MONTH * sizeof(double));
}

Sales::Sales(int __year, const double * __gross, int __n) : Sales(__year) // 委托构造函数
{
    int limit = (__n < MONTH) ? __n : MONTH;        // 确保 __n 的值不会大于 12

    // 拷贝相应的数据
    std::copy(__gross, __gross + limit, this->gross);
}

double Sales::operator[](int __index) const
{
    if (__index > MONTH || __index < 0) { throw BadIndex(__index); }

    return this->gross[__index];
}

double & Sales::operator[](int __index)
{
    if (__index > MONTH || __index < 0) { throw BadIndex(__index); }

    return this->gross[__index];
}

LabledSales::NBadIndex::NBadIndex(const std::string & __lable, int __index, 
                                  const std::string & __what) : Sales::BadIndex(__index, __what), lableIndex(__lable) {}

LabledSales::LabledSales(const std::string & __lable, int __year) : Sales(__year), lable(__lable) {}

LabledSales::LabledSales(const std::string & __lable, 
                         int __year, const double * __gross, int __n) : Sales(__year, __gross, __n), lable(__lable) {}

double LabledSales::operator[](int __index) const
{
    if (__index < 0 || __index > MONTH) { throw NBadIndex(getLabel(), __index); }

    return Sales::operator[](__index);
}

double & LabledSales::operator[](int __index)
{
    if (__index < 0 || __index > MONTH) { throw NBadIndex(getLabel(), __index); }

    return Sales::operator[](__index);
}