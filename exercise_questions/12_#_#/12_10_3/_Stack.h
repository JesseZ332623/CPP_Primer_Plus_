/**
 * _Stack.h
 * @date 2023.09.28
 * @author by Jesse_EC
*/

/*
    重新编写 _Stack 类，这个类使用动态分配的数组来保存栈元素。
    并为这个类编写测试用例。
*/

#ifndef __STACK_H_
#define __STACK_H_

#include <iostream>
#include <fstream>

typedef unsigned long int Item;
using std::cout, std::ostream, std::ofstream;

class _Stack
{
    private:
        enum { MAX_SIZE = 10 }; /*一个栈默认的最大元素数*/
        Item *p_items;                  /*指向了一个栈的指针*/
        int stack_size;                 /*当前栈的元素数*/
        int top;                        /*栈顶元素的索引值*/

    public:
        _Stack(size_t n = MAX_SIZE);           /*构造函数 0： 创建栈并设置最大元素数*/
        _Stack(const _Stack & st);          /*构造函数 1： 用于类与类之间的拷贝*/

        bool isempty() const;
        bool isfull() const;

        bool push(const Item & item);       /*往栈中添加数据*/

        bool pop(Item & item);              /*从栈顶弹出数据*/

        _Stack & operator=(const _Stack & st);

        /*将数据输出值一个文本文件*/
        ofstream & operator<<(ofstream & _ofs);

        /*将数据输出至终端*/
        friend ostream & operator<<(ostream & _os, const _Stack & _st);

        

        ~_Stack();
};


#endif