/**
 * _String_Clsss
 * @author Jesse_EC
 * @date 2023.09.21
*/
#ifndef __STRING_H_
#define __STRING_H_

#include <iostream>
#include <fstream>

using std::ostream, std::istream;
using std::ofstream;

/*
    设计一个字符串类，要求实现如下的字符串基本操作：
    1）求字符串的长度

    2）字符串的赋值操作，分为：
        1.字符串类 赋值给 字符串类
        2.字符串 赋值给 字符串类

    3）单个字符查找，分为：
        1.对只读字符串的查找
        2.对非只读字符串的查找

    4）字符串的比较，分为：
        1.比较哪个字符串的 ASCII 值大
        2.比较两个字符串是否相等

    5）字符串的输入与输出（重载 << 以及 >> 运算符)

    6) 将字符串输出至文件

    当然，标准库中的字符串类，远比这个要复杂。。。。。
*/

class _String
{
    private:
        char *str;          /*字符串本体*/
        size_t _length;     /*字符串长度*/

        /*当前字符串类的数量*/
        static int str_count;

        /*用户可以输入的字符串最大长度*/
        static const int CIN_LIMIT = 80;        

    public:
        /*
            _String 类的构建函数，考虑三种情况：
            1.默认构建函数
            2.传入字符串的构建函数
            3.传入字符串类的构建函数

            构建函数们要做以下四件事：
            1.获取字符串长度
            2.使用 new 关键字在堆空间分配内存
            3.将传入的字符串拷贝或者初始化为 '\0'
            4.自增字符串数量
        */
        _String();
        _String(const char *_str);
        _String(_String & str_object);

        /*求字符串长度*/
        const size_t length() { return _length; }

        /*字符串的赋值操作 字符串类 赋值给 字符串类*/
        _String & operator=(const _String & str_object);

        /*字符串的赋值操作 字符串 赋值给 字符串类*/
        _String & operator=(const char *_str);

        /*单个字符查找*/
        char & operator[](int index);
        const char & operator[](int index) const;

        /*字符串的比较*/
        friend bool operator>(const _String & _str_1, const _String & _str_2);
        friend bool operator<(const _String & _str_1, const _String & _str_2);
        friend bool operator==(const _String & _str_1, const _String & _str_2);

        friend ostream & operator<<(ostream & _os, const _String & _str);
        friend ofstream & operator<<(ofstream & _fs, const _String & _str)
        {
            _fs << _str.str;

            return _fs;
        }

        friend istream & operator>>(istream & _is, const _String & _str);

        static const size_t String_Count();

        ~_String();
};

#endif