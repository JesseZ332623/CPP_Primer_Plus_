#ifndef _TP_STACK_H_
#define _TP_STACK_H_

typedef unsigned long long int size_t;

template<typename Type>
class Stack
{
    private:
        enum { DEFUALT_SIZE = 10 };     /*默认栈大小*/

        size_t stack_size;              /*当前栈大小*/

        size_t top;                     /*当前顶栈下标*/

        Type *items;                    /*栈指针，指向了一个栈*/

    public:
        /*
            默认构造函数，使用 explicit 防止隐式转换。
        */
        explicit Stack(int _stack_size = DEFUALT_SIZE);
        Stack(const Stack & _stack);

        bool isempty() const { return top == 0; }

        bool isfull() const { return stack_size == top; }

        bool push(const Type & _item);

        bool pop(Type & _item);

        Stack & operator=(const Stack & _stack);

        ~Stack() { delete[] items; }
};


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

template<typename Type>
bool Stack<Type>::push(const Type & _item)
{
    if (top < stack_size)
    {
        items[top++] = _item;

        return true;
    }
    else { return false; }
}

template<typename Type>
bool Stack<Type>::pop(Type & _item)
{
    if (top > 0)
    {
        _item = items[--top];

        return true;
    }
    else { return false; }
}

template<typename Type>
Stack<Type> & Stack<Type>::operator=(const Stack<Type> & _stack)
{
    if (this == &_stack) { return *this; }

    stack_size = _stack.stack_size;
    top = _stack.top;

    delete[] items;

    items = new Type[stack_size];

    for (size_t index = 0; index < top; ++index)
    {
        items[index] = _stack.items[index];
    }

    return *this;
}

#endif  //_TP_STACK_H_