/**
 * 上面讲了多参数的模板类，先来来讲一下类的显式实例化（或者叫特化 explicit specialization）
 * 
 * 显示实例化 是指特点类型（用于替换模板中的泛型）的定义。
 * 有些时候，可能需要在为特殊类型实例化时，对模板进行修改，使其行为不同。
 * 
 * 例如，假设已经为用于排序后数组的类（元素在加入时被排序）定义了一个模板：
 * 
 *                  template<typename Type, size_t _size>
 *                  class Sorted_Array {....};
 * 
 * 此外，这个类会设计一些比较函数（重载 '==' '>' '<' 等符号）对数值进行比较，
 * Type 对于数字（如 int, long int, double 等数字类型），这管用，哪怕 Type 是一个对象，只要定义了相应的符号重载，也管用。
 * 
 * 但是对于 C 风格字符串（const char *）类型，
 * 单纯的替换类型可能会造成一些未知的错误，所以需要对 C 风格的字符串类型做一个显式实例化，如下所示：
 * 
 *                  template<>
 *                  class Sorted_Array<const char *,  size_t _size> {......};
 * 
 * 当具体化模板和通用模板都与实例化请求匹配时，编译器讲使用具体化版本。
*/

#ifndef _EXPLICIT_SP_H_
#define _EXPLICIT_SP_H_

#include <iostream>
#include <algorithm>
#include <initializer_list>

template<typename _Array_Type, size_t _s>
class Sorted_Array
{
    public:
        using ostream = std::ostream;

        typedef _Array_Type* iterator;
        //typedef const _Array_Type* const_iterator;

    private:
        _Array_Type array[_s];

        size_t total() const;

    public:
        Sorted_Array(_Array_Type * _arr);

        Sorted_Array(const Sorted_Array & _sorted_array);

        Sorted_Array(const std::initializer_list<_Array_Type> _init_ls);

        iterator begin() { return array; }

        iterator end() { return array + _s - 1; }

        Sorted_Array & operator=(const Sorted_Array & _sort_arr);

        Sorted_Array & operator=(_Array_Type * _arr);

        Sorted_Array & operator=(const std::initializer_list<_Array_Type> _init_ls);

        bool operator==(const Sorted_Array & _sort_arr);

        bool operator>(const Sorted_Array & _sort_arr);

        bool operator<(const Sorted_Array & _sort_arr);

        _Array_Type operator[](size_t index) const;

        _Array_Type & operator[](size_t index);

        friend ostream & operator<<(ostream & _os, Sorted_Array & _sort_arr) { for (auto & _val : _sort_arr.array) { std::cout << _val << ' '; }  return _os; }

        ~Sorted_Array() {}
};

template<typename _Array_Type, size_t _s>
size_t Sorted_Array<_Array_Type, _s>::total() const
{
    size_t total = 0;
    for (auto & _value : array)
    {
        total += _value;
    }

    return total;
}

template<typename _Array_Type, size_t _s>
Sorted_Array<_Array_Type, _s>::Sorted_Array(_Array_Type * _arr)
{
    std::sort(_arr, _arr + _s, [](_Array_Type a, _Array_Type b){ return a < b; });

    std::copy(_arr, _arr + _s, array);
}

template<typename _Array_Type, size_t _s>
Sorted_Array<_Array_Type, _s>::Sorted_Array(const Sorted_Array & _sorted_array)
{
    std::copy(_sorted_array.array, _sorted_array.array + _s, array);
}

template<typename _Array_Type, size_t _s>
Sorted_Array<_Array_Type, _s>::Sorted_Array(const std::initializer_list<_Array_Type> _init_ls)
{
     std::copy(_init_ls.begin(), _init_ls.end(), array);
}

template<typename _Array_Type, size_t _s>
Sorted_Array<_Array_Type, _s> & Sorted_Array<_Array_Type, _s>::operator=(const Sorted_Array & _sort_arr)
{
    if (this == &_sort_arr) { return *this; }

    std::copy(_sort_arr.array, _sort_arr.array + _s, array);

    return *this;
}

template<typename _Array_Type, size_t _s>
Sorted_Array<_Array_Type, _s> & Sorted_Array<_Array_Type, _s>::operator=(_Array_Type * _arr)
{
    if (!_arr) { std::cerr << "NULL Array...." << std::endl; std::exit(EXIT_FAILURE); }

    std::copy(_arr, _arr + _s, array);

    return *this;
}

template<typename _Array_Type, size_t _s>
Sorted_Array<_Array_Type, _s> & Sorted_Array<_Array_Type, _s>::operator=(const std::initializer_list<_Array_Type> _init_ls)
{
    std::copy(_init_ls.begin(), _init_ls.end(), array);

    return *this;
}

template<typename _Array_Type, size_t _s>
bool Sorted_Array<_Array_Type, _s>::operator==(const Sorted_Array & _sort_arr)
{
    for (size_t index = 0; index < _s; ++index)
    {
        if (array[index] != _sort_arr.array[index]) { return false; }
    }

    return true;
}

template<typename _Array_Type, size_t _s>
bool Sorted_Array<_Array_Type, _s>::operator>(const Sorted_Array & _sort_arr)
{
    return total(array) > total(_sort_arr.array);
}

template<typename _Array_Type, size_t _s>
bool Sorted_Array<_Array_Type, _s>::operator<(const Sorted_Array & _sort_arr)
{
    return total(array) < total(_sort_arr.array);
}

template<typename _Array_Type, size_t _s>
_Array_Type Sorted_Array<_Array_Type, _s>::operator[](size_t index) const
{
    if (index >= _s) { std::cerr << "Out of range...." << std::endl; std::exit(EXIT_FAILURE); }

    return array[index];
}

template<typename _Array_Type, size_t _s>
_Array_Type & Sorted_Array<_Array_Type, _s>::operator[](size_t index)
{
    if (index >= _s) { std::cerr << "Out of range...." << std::endl; std::exit(EXIT_FAILURE); }

    return array[index];
}

#endif