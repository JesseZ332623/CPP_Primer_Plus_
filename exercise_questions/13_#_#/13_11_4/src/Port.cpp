#include "./include/Port.h"

Port::Port(const char *br, const char *sty, int bott)
{
    /*字符串长度不得超过最大值，若超过就只分配最大值*/
    if (std::strlen(br) > BRAND_LENGTH)
    {
        brand = new char [BRAND_LENGTH];
        std::strcpy(brand, "Over Length!");
    }
    else
    {
        brand = new char [std::strlen(br) + 1];
        std::strcpy(brand, br);
    }

    if (std::strlen(sty) <= STYLE_LENGTH)
    {
        std::strcpy(style, sty);
    }
    else
    {
        std::strcpy(style, "Over Length!");
    }
    
    bottles = bott;
}

/*
    经过上一个构建函数严格的边界检查，
    这个拷贝函数可以不再需要检测边界。
*/
Port::Port(const Port & port)
{
    brand = new char [std::strlen(port.brand) + 1];
    
    std::strcpy(brand, port.brand);
   
    std::strcpy(style, port.style);
    
    bottles = port.bottles;
}

Port & Port::operator=(const Port & port)
{
    if (this == &port) { return *this; }

    delete[] brand;

    brand = new char [std::strlen(port.brand) + 1];
    
    std::strcpy(brand, port.brand);
   
    std::strcpy(style, port.style);
    
    bottles = port.bottles;

    return *this;
}

Port & Port::operator+=(int bott)
{
    bottles += bott;

    return *this;
}

Port & Port::operator-=(int bott)
{
    /*显然，我们不希望把 bottles 减成负数*/
    if (bottles > 0 && bottles > bott) { bottles -= bott; }
    else
    {
        cout << "Argument 'bott' over than 'bottles'." << endl;
        cout << "bott = " << bott << ", " << "bottles = " << bottles << endl;
    }

    return *this;
}

void Port::Show() const
{
    cout << "Brand: " << brand << endl;
    cout << "Kind: " << style << endl; 
    cout << "Bottoms: " << bottles << endl;
}

ostream & operator<<(ostream & _os, const Port & port)
{
    _os << port.brand << ", " << port.style << ", " << port.Bottom_Count();

    return _os;
}