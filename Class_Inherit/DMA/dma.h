#ifndef _DMA_H_
#define _DMA_H_

#include <iostream>
#include <cstring>

/*基类 Base_DMA，使用动态分配内存*/
class Base_DMA
{
    private:
        char *label;
        int rating;

    public:
        /*参数化构建函数*/
        Base_DMA(const char *_lab = "NULL", int _rate = 0);

        /*深拷贝构建函数*/
        Base_DMA(const Base_DMA & _b_dma);

        /*移动构造函数*/
        Base_DMA(Base_DMA && _b_dma);

        /*重载 = 赋值操作符 的拷贝函数*/
        Base_DMA & operator=(const Base_DMA & _b_dma);

        /*友元 输出类信息*/
        friend std::ostream & operator<<(std::ostream & _os, const Base_DMA & _b_dma);

        /*虚构建函数*/
        virtual ~Base_DMA();
};

/*
    派生类 Lack_DMA 没有使用动态分配内存。
    因此无需 重载基类构建函数
    使用隐式的构建函数 和 隐式的复制操作符  
*/
class Lack_DMA : public Base_DMA
{
    private:
        enum { COL_LEN = 40 };
        char color[COL_LEN];

    public:
        Lack_DMA(const char *_lab = "NULL", int _rate = 0, const char *_color = "Black");
        Lack_DMA(const Base_DMA & _b_dma, const char *_color = "Black");
        Lack_DMA(const Lack_DMA & _l_dma);
        Lack_DMA(Lack_DMA && _l_dma);

        friend std::ostream & operator<<(std::ostream & _os, const Lack_DMA & _l_dma);
};

/*
    派生类 Has_DMA 使用动态内存分配，
    因此需要构建函数
*/
class Has_DMA : public Base_DMA
{
    private:
        char *style;

    public:
        Has_DMA(const char * _lab = "NULL", int _rate = 0, const char *_sty = "none");
        Has_DMA(const Base_DMA & _b_dma, const char *_sty = "none");
        Has_DMA(const Has_DMA & _h_dma);
        Has_DMA(Has_DMA && _h_dma);

        Has_DMA & operator=(const Has_DMA & _h_dma);

        friend std::ostream & operator<<(std::ostream & _os, const Has_DMA & _h_dma);

        ~Has_DMA();
};

#endif