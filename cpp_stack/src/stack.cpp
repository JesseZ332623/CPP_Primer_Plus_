#include "include/stack.h"

Stack::Stack()
{
    top = 0;
}

bool Stack::isempty() const
{
    return top == 0;
}

bool Stack::isfull() const
{
    return top == MAX;
}

bool Stack::push(const Item & item)
{
    if (top < MAX)
    {
        items[top++] = item;
        return true;
    }
    else { return false; }
}

bool Stack::pop(Item & item)
{
    if (top > 0)
    {
        item = items[--top];
        return true;
    }
    else { return false; }
}

bool Stack::show_data()
{
    if (top < 0)
    {
        return false;
    }
    else
    {
        for (int index = 0; index < top; ++index)
        {
            std::cout << items[index] << '\t';
        }
    }

    return true;
}

Stack::~Stack() {}