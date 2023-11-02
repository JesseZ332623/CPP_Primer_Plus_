#ifndef _TP_STACKz_H_
#define _TP_STACKz_H_

typedef unsigned long long int size_t;

template<typename Type>
class Stack
{
    private:
        enum { DEFUALT_SIZE = 10 };     /*默认栈大小*/

        size_t stack_size;              /*当前栈大小*/

        size_t top;                     /*当前顶栈下表*/

        Type *items;                    /*栈指针，指向了一个栈*/

    public:
        /*
            默认构造函数，使用 explicit 防止隐式转换。
        */
        explicit Stack(int _stack_size = DEFUALT_SIZE);
        Stack(const Stack & _stack);

        bool isempty() const { return stack_size == 0; }

        bool isfull() const { return stack_size == top; }

        bool push(const Type _item);

        bool pop(Type _item);

        Stack & operator=(const Stack & _stack);

        ~Stack() { delete[] items; }
};

#endif