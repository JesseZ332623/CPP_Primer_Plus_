#include "./my_array.h"

using My_Array::Array;

#if true

/*默认构造函数*/
Array::Array()
{
    _array = new int[DEFAULT_SIZE];
    _array_size = _array_capacity = DEFAULT_SIZE;
}

/*构造函数 01：设置数组的大小*/
Array::Array(size_t _size)
{
    _array = new int[_size];
    _array_size = _array_capacity = _size;
}

/*构造函数 02：传入数组和大小*/
Array::Array(const int * _arr, size_t _size)
{
    if (!_arr) { Array(); }

    _array = new int[_size];
    _array_size = _array_capacity = _size;

    for (size_t index = 0; index < _size; ++index)
    {
        _array[index] = _arr[index];
    }
}

/*重设数组大小*/
bool Array::resize(const size_t _size)
{
#if false
    if (_size > _array_capacity)
    {
        int * new_array = new int[_size];

        delete[] _array;

        _array_capacity = _size;
        _array = new_array;
    }
#endif

    if (!_size) 
    { 
        throw std::invalid_argument("Error argument: (_size < 0).");
        return false;
    }
    if (_size > MAX_SIZE)
    {
        throw std::invalid_argument("Error argument: (_size > MAX_SIZE).");
        return false;
    }

    int *temp_array = new int[_size];
    size_t copy_size = (_size < _array_size) ? _size : _array_size;

    for (size_t index = 0; index < copy_size; ++index)
    {
        temp_array[index] = _array[index];
    }

    delete[] _array;

    _array = temp_array;

    delete[] temp_array;

    _array_size = _array_capacity = _size;

    return true;
}

bool Array::push_back(const int & _value)
{
    if (_array_size == _array_capacity)
    {
        if(!resize(_array_capacity += (_array_capacity * 0.5))) { return false; }
    }
    _array[size() - 1] = _value;

    ++_array_size;

    return true;
}

int Array::pop_back()
{
    if (empty()) { throw std::out_of_range("empty array......"); }
    
    int last_value = _array[size() - 1];

    _array[size() - 1] = _array[size() - 2];

    --_array_size;

    return last_value;
}

int & Array::operator[](size_t index)
{
    return _array[index];
}

const int & Array::operator[](size_t index) const
{
    return _array[index];
}

Array & Array::operator=(const Array & _array)
{
    if (this == &_array)  { return *this; }

    resize(_array._array_capacity);

    _array_size = _array._array_size;
    _array_capacity = _array._array_capacity;

    return *this;
}

#endif