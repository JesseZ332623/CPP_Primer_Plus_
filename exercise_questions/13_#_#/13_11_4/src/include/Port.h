#ifndef _PORT_H_
#define _PORT_H_

#include <iostream>
#include <cstring>

using std::ostream, std::cout, std::endl;

/*字符串 brand 允许的最大长度*/
const int BRAND_LENGTH = 15;

/*字符串 style 允许的最大长度*/
const int STYLE_LENGTH = 21;

/*品牌的种类数*/
const int BRAND_TYPES = 4;

/*品牌种类列表*/
const char BRAND_LIST[BRAND_TYPES][BRAND_LENGTH] = 
{   
    "i.e.", "tawny", "ruby", "vintage"
};

class Port
{
    private:
        char *brand;
        char style[STYLE_LENGTH];
        int bottles;

    public:
        Port(const char *br = "none", const char *sty = "none", int bott = 0);
        Port(const Port & port);

        Port & operator=(const Port & port);

        /*重载 += 符号对葡萄酒箱的瓶数进行加减*/
        Port & operator+=(int bott);
        Port & operator-=(int bott);

        const int Bottom_Count() const { return bottles; } 

        virtual void Show() const;

        friend ostream & operator<<(ostream & _os, const Port & port);

        virtual ~Port() { delete[] brand; }
};

#endif