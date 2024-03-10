#ifndef _SALES_H_
#define _SALES_H_

#include <stdexcept>
#include <string>
#include <cstring>
#include <algorithm>

class Sales
{
    public:
        enum {MONTH = 12};

    private:
        double gross[MONTH];
        int year;

    public:
        class BadIndex : public std::logic_error
        {
            private:
                int bedIndexVal;

            public:
                explicit BadIndex(int __index, 
                                  const std::string & __what = "Index error in Sales object\n");

                int getBedIndex() const { return bedIndexVal; }

                virtual ~BadIndex() throw() {}
        };

        /**
         * @brief 构建函数其一，仅设置 year，并使用 memset() 初始化 gross 数组
         * 
         * @param __year 年份
        */
        explicit Sales(int __year = 0);

        /**
         * @brief 构建函数其二，设置年份和工资数组的值
         * 
         * @param __year    年份
         * @param __gross   工资数组
         * @param __n       工资数组的长度
        */
        Sales(int __year, const double * __gross, int __n);

        int getYear() const { return year; }

        virtual double operator[](int __index) const;
        virtual double & operator[](int __index);

        virtual ~Sales() {}
};

class LabledSales : public Sales
{
    private:
        std::string lable;

    public:
        class NBadIndex : public Sales::BadIndex
        {
            private:
                std::string lableIndex;

            public:
                NBadIndex(const std::string & __lable, int __index, 
                          const std::string & __what = "Index error in LableSales object\n");

                const std::string & getLableIndex() const { return lableIndex; }

                virtual ~NBadIndex() throw() {}
        };

        explicit LabledSales(const std::string & __lable = "none", int __year = 0);
        LabledSales(const std::string & __lable, int __year, const double * __gross, int __n);

        const std::string & getLabel() const { return lable; }

        virtual double operator[](int __index) const;
        virtual double & operator[](int __index);

        virtual ~LabledSales() {}
};

#endif // _SALES_H_