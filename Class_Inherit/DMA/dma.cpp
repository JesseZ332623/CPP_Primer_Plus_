#include "./dma.h"

/*基类 Base_DMA的实现，使用动态分配内存*/

Base_DMA::Base_DMA(const char *_lab, int _rate)
{
    label = new char[std::strlen(_lab) + 1];

    std::strcpy(label, _lab);
    rating = _rate;
}

Base_DMA::Base_DMA(const Base_DMA & _b_dma)
{
    label = new char[std::strlen(_b_dma.label) + 1];

    std::strcpy(label, _b_dma.label);
    rating = _b_dma.rating;
}

Base_DMA::Base_DMA(Base_DMA && _b_dma) 
{
    char *temp = _b_dma.label;
    label = temp;
    _b_dma.label = nullptr;

    rating = _b_dma.rating;
    _b_dma.rating = 0;
}

Base_DMA & Base_DMA::operator=(const Base_DMA & _b_dma)
{
    if (this == &_b_dma) { return *this; }
    
    delete[] label;
    label = new char[std::strlen(_b_dma.label) + 1];
    std::strcpy(label, _b_dma.label);
    rating = _b_dma.rating;

    return *this;
}

std::ostream & operator<<(std::ostream & _os, const Base_DMA & _b_dma)
{
    _os << "Base DMA: " << std::endl;
    _os << "Label: " << _b_dma.label << std::endl;
    _os << "Rating: " << _b_dma.rating << std::endl;

    return _os;
}

Base_DMA::~Base_DMA()
{
    delete[] label;
}

/*
    派生类 Lack_DMA 没有使用动态分配内存。
    因此无需 重载基类构建函数
    使用隐式的构建函数 和 隐式的复制操作符  
*/
Lack_DMA::Lack_DMA(const char *_lab, int _rate, 
                   const char *_color) : Base_DMA(_lab, _rate)
{
    std::strncpy(color, _color, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}

Lack_DMA::Lack_DMA(const Base_DMA & _b_dma, const char *_color) : Base_DMA(_b_dma)
{
    std::strncpy(color, _color, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}

Lack_DMA::Lack_DMA(const Lack_DMA & _l_dma) : Base_DMA(_l_dma)
{
    strncpy(color, _l_dma.color, COL_LEN);
    color[COL_LEN - 1] = '\0';
}

Lack_DMA::Lack_DMA(Lack_DMA && _l_dma) : Base_DMA(std::move(_l_dma)) {}

std::ostream & operator<<(std::ostream & _os, const Lack_DMA & _l_dma)
{
    _os << (const Base_DMA &)_l_dma;
    _os << "Lack DMA: " << std::endl;
    _os << "Color string: " << _l_dma.color << std::endl;

    return _os;
}

/*
    派生类 Has_DMA 使用动态内存分配，
    因此需要析构函数
*/
Has_DMA::Has_DMA(const char * _lab, int _rate, const char *_sty) : Base_DMA(_lab, _rate)
{
    style = new char[std::strlen(_sty) + 1];

    std::strcpy(style, _sty);
}

Has_DMA::Has_DMA(const Base_DMA & _b_dma, const char *_sty) : Base_DMA(_b_dma)
{
    style = new char[std::strlen(_sty) + 1];

    std::strcpy(style, _sty);
}

Has_DMA::Has_DMA(const Has_DMA & _h_dma) : Base_DMA(_h_dma)
{
    style = new char[std::strlen(_h_dma.style) + 1];

    std::strcpy(style, _h_dma.style);
}

Has_DMA::Has_DMA(Has_DMA && _h_dma) : Base_DMA(std::move(_h_dma))
{
    style = new char[std::strlen(_h_dma.style) + 1];

    std::strcpy(style, _h_dma.style);

    std::strcpy(_h_dma.style, "none");
}

Has_DMA & Has_DMA::operator=(const Has_DMA & _h_dma)
{
    if (this == & _h_dma) { return *this; }

    Base_DMA::operator=(_h_dma);

    delete[] style;

    style = new char[std::strlen(_h_dma.style) + 1];
    std::strcpy(style, _h_dma.style);

    return *this;
}

Has_DMA::~Has_DMA()
{
    delete[] style;
}

std::ostream & operator<<(std::ostream & _os, const Has_DMA & _h_dma)
{
    _os << (const Base_DMA &)_h_dma;
    _os << "Has DMA: " << std::endl;
    _os << "Style: " << _h_dma.style << std::endl;

    return _os;
}
