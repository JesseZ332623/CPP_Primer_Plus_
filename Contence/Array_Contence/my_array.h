#ifndef _MY_ARRAY_H_
#define _MY_ARRAY_H_

#include <iostream>
#include <stdexcept>

namespace My_Array
{
    const size_t MAX_SIZE = 16 * 1024;
    const size_t DEFAULT_SIZE = 12;

    template <typename Number>
    class Array
    {
        private:
            /*指向数组的指针*/
            Number *_array;

            /*数组大小*/
            size_t _array_size;

            /*数组容量*/
            size_t _array_capacity;

        public:
            /*默认构造函数*/
            Array();

            /*构造函数 01：设置数组的大小*/
            Array(size_t _size);

            /*构造函数 02：传入数组和大小*/
            Array (const Number *& _arr, size_t _size);

            /*返回数组大小*/
            size_t size() const { return _array_size; }

            /*返回数组容量*/
            size_t capacity() const { return _array_capacity; }

            /*重设数组大小*/
            void resize(const size_t _size);

            /*从末尾插入数据*/
            void push_back(const Number & _value);

            /*从末尾删除数据*/
            void pop_back();

            /*从 index 下标处插入元素*/
            void insert(const Number & _value, size_t _index);

            /*从 index 下标处擦除元素*/
            void eraser(const Number & _value, size_t _index);

            /*访问数组元素*/
            Number & operator[](size_t _index);

            /*访问数组元素*/
            const Number & operator[](size_t _index) const;

            /*数组的赋值*/
            Array<Number> & operator=(const Array<Number> & _array);

            ~Array() { delete[] _array; };
            
    };
};


#endif
