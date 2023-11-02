#include "./tp_stack.h"
#include <iostream>

template<typename Type>
Stack<Type>::Stack(int _stack_size) : stack_size(_stack_size), top(0)
{
    items = new Type[_stack_size];
}

template<typename Type>
Stack<Type>::Stack(const Stack & _stack) : stack_size(_stack.stack_size), top(_stack.top)
{
    items = new Type[stack_size];
    for (size_t index = 0; index < top; ++index)
    {
        items[index] = _stack.items[index];
    }
}