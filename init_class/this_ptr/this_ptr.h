#include <iostream>
#include <string>

class This_Ptr
{
    private:
        std::string class_name;
    public:
        This_Ptr(const std::string &str);

        /*
            求两个对象中，私有字符串字符串变量长度较长的那个对象，
            并返回这个对象的引用。
        */
        const This_Ptr & get_longer(const This_Ptr & this_ptr) const;

        std::string show_name() const { return class_name; };

        ~This_Ptr();
};

class Stock
{
    private:
        double total_val;

    public:
        Stock(double value);

        double total() const { return total_val; };

        double _total() const { return this->total_val; }

        /*
            一种比较高级的比较两个类数据的函数声明。

            该函数隐式的访问一个对象（括号中的 const Stock & stock），
            而显示的访问另一个对象  （分号前的 const），
            并返回其中一个对象的引用。
        */
        const Stock & topval(const Stock & stock) const;

        ~Stock();
};

/*
    传入两个 object 的引用，
    然后比较两个类内部私有数据 total_val 的大小。
    如果第一个 object 的数据比较大，则返回 true
    否则返回 false，其他意外情况也返回 false 。

    但这种方法不够高级（滑稽）
*/
bool data_compare(Stock &stock_1, Stock &stock_2);

