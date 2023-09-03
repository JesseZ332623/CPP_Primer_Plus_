#ifndef _STACK_H_
#define _STACK_H_

#include "stack_defs.h"

typedef unsigned long Item;

class Stack
{
    private:
        enum {MAX = 10};
        Item items[MAX];
        int top;

    public:
        Stack();

        bool isempty() const;

        bool isfull() const;

        bool push(const Item & item);

        bool pop(Item & item);

        bool show_data();

        int show_stack_top() const { return top; }

        ~Stack();
};
#endif