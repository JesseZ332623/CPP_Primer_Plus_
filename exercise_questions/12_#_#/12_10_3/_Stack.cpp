#include "./_Stack.h"

_Stack::_Stack(size_t n) : MAX_SIZE(n)
{
    if (n > MAX_SIZE) { n = MAX_SIZE; }

    p_items = new Item[n];
    stack_size = 0;
    top = 0;
}

_Stack::_Stack(const _Stack &st)
{
    if (st.stack_size > 0)  /*判断是不是空栈*/
    {
        p_items = new Item[st.stack_size];

        for (int index = 0; index < st.stack_size; ++index)
        {
            p_items[index] = st.p_items[index];
        }

        stack_size = st.stack_size;
        top = st.top;
    }
    else
    {
        p_items = nullptr;
        stack_size = 0;
        top = 0;
    }
}

bool _Stack::isempty() const
{
    return stack_size == 0;
}

bool _Stack::isfull() const
{
    return stack_size == MAX_SIZE;
}

bool _Stack::push(const Item & item)
{
    if (top < MAX_SIZE)
    {
        p_items[top++] = item;
        ++stack_size;

        return true; 
    }
    else { return false; }
}

bool _Stack::pop(Item & item)
{
    if (top > 0)
    {
        item = p_items[--top];
        --stack_size;

        return true;
    }
    else { return false; }
}

_Stack & _Stack::operator=(const _Stack & st)
{
    if (this == &st) { return *this; }

    /*检测将要复制类的大小是否足够*/
    if (st.stack_size <= stack_size)
    {
        stack_size = st.stack_size;
    }
    else
    {
        delete[] p_items;
        p_items = new Item[st.stack_size];
        stack_size = st.stack_size;
    }

    for (int index = 0; index < st.stack_size; ++index)
    {
        p_items[index] = st.p_items[index];
    }

    top = st.top;

    return *this;
}

ostream & operator<<(ostream & _os, const _Stack & _st)
{
    if (!_os) { return _os; }

    if (_st.top == 0)
    {
        _os << "This is a Empty Stack...\n";

        return _os;
    }

    for (int index = 0; index < _st.top; ++index)
    {
        _os << _st.p_items[index] << '\t';

        if (index % 10 == 0 && index != 0) { _os << '\n'; }
    }

    _os.put('\n');

    return _os;
}

ofstream & _Stack::operator<<(ofstream & _ofs)
{
    if (!_ofs) { return _ofs; }

    if (top == -1)
    {
        _ofs << "This is a Empty Stack...\n";

        return _ofs;
    }

    for (int index = 0; index < top; ++index)
    {
        _ofs << p_items[index];
    }

    _ofs.put('\n');

    return _ofs;
}

_Stack::~_Stack()
{
    delete p_items;
}