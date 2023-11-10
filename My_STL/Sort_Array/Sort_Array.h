/**
 * Sort_Array.h
 * @author JesseZ332623
 * @date 2023.11.10
*/
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
 * 当具体化模板和通用模板都与实例化请求匹配时，编译器将使用具体化版本。
*/

#ifndef _SORT_ARRAY_H_
#define _SORT_ARRAY_H_

#include <iostream>
#include <algorithm>
#include <initializer_list>
#include <cstring>

/**
 * 首先先实现一个 Sorted_Array 模板类，
 * 主要是处理数字类型（如 int, long int, double 等），对传入的数据都会进行排序。
*/
template<typename _Array_Type, size_t _s>
class Sorted_Array
{
    public:
        using ostream = std::ostream;

        /*封装了指针的伪迭代器*/
        /*将 _Array_Type 的指针类型定义为 iterator*/
        typedef _Array_Type* iterator;

        /*将 const _Array_Type 的指针类型定义为 const_iterator*/
        typedef const _Array_Type* const_iterator;

        /*将 _Array_Type 的引用类型定义为 reference*/
        //typedef _Array_Type & reference;

        /*将 const _Array_Type 的引用类型定义为 const_reference*/
        //typedef const _Array_Type & const_reference;

    private:
        /*一个申请在栈上的固定长度数组*/
        _Array_Type array[_s];


        /**
         *  返回数组所有元素的和。
         * 
         *  @return Total of element
        */
        size_t total() const;

        /**
         * 返回数组的容量，一般在创建对象的时候就已经确定，所以直接返回 _s 即可。
         * 
         * @return Size of array
        */
        size_t size() const { return _s; } 

        /**
         * 初始化数组，将数组的每一个元素都先设为 0
        */
        void init_array() { std::memset(array, 0, size() * sizeof(_Array_Type)); }

        /**
         * 封装了 std::sort() 对 array 的全部元素进行正序排序。
        */
        void sort() { std::sort(array, array + size(), [](_Array_Type a, _Array_Type b){ return a < b; }); }

    public:
        /**
         * 默认构造函数，其任务很简单，根据具体的类型和大小，分配数组。
        */
        Sorted_Array();
        /**
         * 传入一个 _Array_Type 类型数组的参数构造函数，传入的数组会按正序排序后再存放在类中。
         * 
         * @param _arr  A pointer of array's first element
        */
        Sorted_Array(_Array_Type * _arr);

        /**
         * 传入另一个对象的拷贝构造函数。
         * 
         * @param _sorted_array A const reference of Sorted_Array's object
        */
        Sorted_Array(const Sorted_Array & _sorted_array);

        /**
         * 传入一个初始化列表的参数构造函数。
         * 
         * @param _init_ls A copy of std::initializer_list<_Array_Type> 's object，example {12341, 24, 365, 86}
        */
        Sorted_Array(const std::initializer_list<_Array_Type> _init_ls);

        /**
         * 一个封装了指针的伪迭代器，返回数组第一个元素的地址。
         * 
         * @return array A pointer of array's first element
        */
        iterator begin() { return array; }

        /**
         * 一个封装了指针的伪迭代器，返回数组最后一个元素的地址。
         * 
         * @return array A pointer of array's end element
        */
        iterator end() { return array + size() - 1; }

/*数组都是经过排序的，而且要时刻保持有序，因此交换没有意义。。。。*/
#if false 
        /**
         * 使用迭代器交换数组内两个元素的值.
         * 
         * @param iter_a iterator of array
         * @param iter_b iterator of array
        */
        void swap(iterator iter_a, iterator iter_b)
        {
            iterator temp_iter = iter_a;
            iter_a = iter_b;
            iter_b = temp_iter;
        }
#endif

        /**
         * 重载了 = 运算符的深拷贝函数，传入一个 Sorted_Array 类型的引用。
         * 
         * @param _sort_arr A const reference of Sorted_Array's object
         * 
         * @return Reference of Sorted_Array
        */
        Sorted_Array & operator=(const Sorted_Array & _sort_arr);

        /**
         * 重载了 = 运算符的深拷贝函数，传入一个 _Array_Type 类型的数组。
         * 
         * @param _arr  A pointer of array's first element
         * 
         * @return Reference of Sorted_Array
        */
        Sorted_Array & operator=(_Array_Type * _arr);

        /**
         * 重载了 = 运算符的深拷贝函数，传入一个初始化列表。
         * 
         * @param _init_ls A velue of std::initializer_list<_Array_Type> 's object，example {12341, 24, 365, 86}
         * 
         * @return Reference of Sorted_Array
        */
        Sorted_Array & operator=(std::initializer_list<_Array_Type> _init_ls);

        /**
         * 重载了 == 运算符的比较函数，用于判断两个 Sorted_Array 类中的数组是否完全相等。
         * 
         * @param _sort_arr A const reference of Sorted_Array's object
         * 
         * @return A boolean type, Determine if it is completely equal
        */
        virtual bool operator==(const Sorted_Array & _sort_arr) const;

        /**
         * 重载了 > 运算符的比较函数，用于判断哪个类内部数组之和大
         * 
         * @param _sort_arr A const reference of Sorted_Array's object
         * 
         * @return A boolean type, Compare the total array element in object a and b
        */
        virtual bool operator>(const Sorted_Array & _sort_arr) const;

        /**
         * 重载了 < 运算符的比较函数，用于判断哪个类内部数组之和大
         * 
         * @param _sort_arr A const reference of Sorted_Array's object
         * 
         * @return A boolean type, Compare the total array element in object a and b
        */
        virtual bool operator<(const Sorted_Array & _sort_arr) const;

        /**
         * 重载了 [] 下标访问运算符的函数，可以使用对象名 + [下标]直接访问内部数组的元素值。
         * 
         * @param index array index
         * 
         * @return A copy of array[index]
        */
        _Array_Type operator[](size_t index) const;


        /**
         * 重载了 [] 下标访问运算符的函数，可以使用对象名 + [下标]直接访问内部数组的元素值。
         * 但该函数有别于上一个函数，它返回数组索引值的引用，也就说可以有另外一个引用值与其绑定，
         * 便可以直接修改内部数组的元素值，因此如下表达式：
         *              
         *          object_a[0] = object_b[1];
         *          object_a[0] += object_b[1];
         *          object_a[0] = 10;
         *          object_a[0] += 10;
         * 
         * 都是合法的，都可以成功修改内部数组的元素值。
         * 
         * 当然，修改了数组的值，可能会让数组再次变的无序，所以需要重新排序数组，
         * 排序的工作可以放在输出之前再做。
         * 
         * @param index array index 
         * 
         * @return A reference of array[index]
        */
        _Array_Type & operator[](size_t index);

        /**
         * 重载了 << 运算符的运算函数，在输出之前先将数组排序，这是一种暂时的妥协。
         * 
         * @param _os Reference of std::ostream
         * @param _sort_arr Reference of Sorted_Array's object
         * 
         * @return Reference of std::ostream
        */
        friend ostream & operator<<(ostream & _os, Sorted_Array & _sort_arr) 
        { 
            _sort_arr.sort();
            for (auto & _val : _sort_arr.array) { std::cout << _val << ' '; }  
            
            return _os; 
        }

        /*
            析构函数，由于所有操作都在栈上完成，
            并没有涉及堆空间，所以析构函数无事可做。
        */
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
Sorted_Array<_Array_Type, _s>::Sorted_Array() 
{
    init_array();
}

template<typename _Array_Type, size_t _s>
Sorted_Array<_Array_Type, _s>::Sorted_Array(_Array_Type * _arr)
{
    if (!_arr) { std::cerr << "NULL Array...." << std::endl; std::exit(EXIT_FAILURE); }

    init_array();

    std::copy(_arr, _arr + size(), array);

    sort();
}

template<typename _Array_Type, size_t _s>
Sorted_Array<_Array_Type, _s>::Sorted_Array(const Sorted_Array & _sorted_array)
{
    init_array();
    std::copy(_sorted_array.array, _sorted_array.array + size(), array);
}

template<typename _Array_Type, size_t _s>
Sorted_Array<_Array_Type, _s>::Sorted_Array(const std::initializer_list<_Array_Type> _init_ls)
{
    init_array();
    std::copy(_init_ls.begin(), _init_ls.end(), array);

    sort();
}

template<typename _Array_Type, size_t _s>
Sorted_Array<_Array_Type, _s> & Sorted_Array<_Array_Type, _s>::operator=(const Sorted_Array & _sort_arr)
{
    if (this == &_sort_arr) { return *this; }

    init_array();
    std::copy(_sort_arr.array, _sort_arr.array + size(), array);

    return *this;
}

template<typename _Array_Type, size_t _s>
Sorted_Array<_Array_Type, _s> & Sorted_Array<_Array_Type, _s>::operator=(_Array_Type * _arr)
{
    if (!_arr) { std::cerr << "NULL Array...." << std::endl; std::exit(EXIT_FAILURE); }

    init_array();
    std::copy(_arr, _arr + size(), array);

    return *this;
}

template<typename _Array_Type, size_t _s>
Sorted_Array<_Array_Type, _s> & Sorted_Array<_Array_Type, _s>::operator=(const std::initializer_list<_Array_Type> _init_ls)
{
    init_array();
    std::copy(_init_ls.begin(), _init_ls.end(), array);

    return *this;
}

template<typename _Array_Type, size_t _s>
bool Sorted_Array<_Array_Type, _s>::operator==(const Sorted_Array & _sort_arr) const
{
    for (size_t index = 0; index < size(); ++index)
    {
        if (array[index] != _sort_arr.array[index]) { return false; }
    }

    return true;
}

template<typename _Array_Type, size_t _s>
bool Sorted_Array<_Array_Type, _s>::operator>(const Sorted_Array & _sort_arr) const
{
    return (total(array) > total(_sort_arr.array));
}

template<typename _Array_Type, size_t _s>
bool Sorted_Array<_Array_Type, _s>::operator<(const Sorted_Array & _sort_arr) const
{
    return (total(array) < total(_sort_arr.array));
}

template<typename _Array_Type, size_t _s>
_Array_Type Sorted_Array<_Array_Type, _s>::operator[](size_t index) const
{
    if (index >= size()) 
    { 
        std::cerr << "Out of range" << "(Index " << index << " > " << size() << ')' << std::endl; 
        std::exit(EXIT_FAILURE); 
    }

    return array[index];
}

template<typename _Array_Type, size_t _s>
_Array_Type & Sorted_Array<_Array_Type, _s>::operator[](size_t index)
{
    if (index >= size()) 
    { 
        std::cerr << "Out of range" << "(Index " << index << " > " << size() << ')' << std::endl; 
        std::exit(EXIT_FAILURE); 
    }

    return array[index];
}

/**
 * 为了能处理 const char * 类型的数据，我们需要给几个模板类方法做显示实例化，
 * 需要显示实例化的方法有：
 * 
 *      bool operator==(const Sorted_Array & _sort_arr) const;
 * 
 *      bool operator>(const Sorted_Array & _sort_arr) const;
 * 
 *      bool operator<(const Sorted_Array & _sort_arr) const;
 *      
 * 
 *      他们需要调用 std::strcmp() 函数来完成字符串的比较。
*/

#endif //_SORT_ARRAY_H_