#include "./my_array.h"



using My_Array::Array;

template <typename Number>
Array<Number>::Array()
{
    _array = new Number[DEFAULT_SIZE];
    _array_size = _array_capacity = DEFAULT_SIZE;
}

template <typename Number>
Array<Number>::Array(size_t _size)
{
    _array = new Number[_size];
    _array_size = _array_capacity = _size;
}

template <typename Number>
Array<Number>::Array(const Number *& _arr, size_t _size)
{
    if (!_arr) { Array::Array(); }

    _array = new Number[_size];
    _array_size = _array_capacity = _size;

    for (size_t index = 0; index < _size; ++index)
    {
        _array[index] = _arr[index];
    }
}

template <typename Number>
void Array<Number>::resize(const size_t _size)
{
    if (_size > _array_capacity)
    {
        Number * new_array = new Number[_size];

        delete[] _array;

        _array_capacity = _size;
        _array = new_array;
    }

    if (!_size) 
    { 
        throw std::invalid_argument("Error argument: (_size < 0).");
    }
    if (_size > MAX_SIZE)
    {
        throw std::invalid_argument("Error argument: (_size > MAX_SIZE).");
    }

    Number *temp_array = new Number[_size];
    size_t copy_size = (_size < _array_size) ? _size : _array_size;

    for (size_t index = 0; index < copy_size; ++index)
    {
        temp_array[index] = _array[index];
    }

    delete[] _array;

    _array = temp_array;
    _array_size = _array_capacity = _size;
}

template <typename Number>
void Array<Number>::push_back(const Number & _value)
{
    
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
