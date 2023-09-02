#include "this_ptr.h"

This_Ptr::This_Ptr(const std::string &str)
{
    this->class_name = str;
}

/*
    求两个对象中，私有字符串字符串变量长度较长的那个对象，
    并返回这个对象的引用。
*/
const This_Ptr & This_Ptr::get_longer(const This_Ptr & this_ptr) const
{
    std::cout << "The address of object (use this member function): " << this << std::endl;
    if (this_ptr.class_name.length() > this->class_name.length())
    {
        return this_ptr;
    }
    else
    {
        return *this;
    }
}

This_Ptr::~This_Ptr()
{
    std::cout << "Class [This_Ptr] deleted.....\n";
}

Stock::Stock(double value)
{
    this->total_val = value;
}

/*
    传入两个 object 的引用，
    然后比较两个类内部私有数据 total_val 的大小。
    如果第一个 object 的数据比较大，则返回 true
    否则返回 false，其他意外情况也返回 false 。

    但这种方法不够高级（滑稽）
*/
bool data_compare(Stock &stock_1, Stock &stock_2)
{
    if (stock_1.total() > stock_2.total())
    {
        return true;
    }
    else if (stock_1.total() < stock_2.total())
    {
        return false;
    }
    else
    {
        std::cout << "Other case....." << std::endl;
        return false;
    }
}

/*
    一种比较高级的比较两个类数据的函数声明。

    该函数隐式的访问一个对象（括号中的 const Stock & stock），
    而显示的访问另一个对象  （分号前的 const），
    并返回其中一个（数据较大）的对象的引用。
*/
const Stock & Stock::topval(const Stock & stock) const
{
    std::cout << stock.total_val << ' ' << this->total_val << std::endl;
    std::cout << stock.total_val << ' ' << total_val << std::endl;
    std::cout.put('\n');

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
    std::cout << "Class [Stock] deleted....." << std::endl;
}

int main(int argc, char const *argv[])
{
    
#if false
    Stock stock(12.76523);   
    Stock _stock(13.0999);

    if(data_compare(stock, _stock))
    {
        std::cout << "data of Object [stock] value: " << stock.total() << std::endl;
    }
    else
    {
        std::cout << "data of Object [_stock] value: " << _stock.total() << std::endl;
    }
#endif

    This_Ptr this_1("_Object 01_");
    This_Ptr this_2("Object 02");

    std::cout << &this_1 << std::endl;
    const This_Ptr & longer_this = this_1.get_longer(this_2);

    std::cout << longer_this.show_name() << std::endl;

    
    return EXIT_SUCCESS;
}

