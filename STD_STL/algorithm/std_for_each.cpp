#include <vector>
#include <cstdio>
#include <string>
#include <bits\stl_algo.h>
#include <cstring>

/*
    STL 中的 for_each() 用于遍历一个容器，以避免显式的调用迭代器，函数的常规用法如下：

    std::for_each(contanier.begin(), contanier.end(), lamba or function_ptr);

    只要一个容器中定义了 begin 和 end，那都可以用此方法遍历。
*/

template <typename _Type>
class A
{
    private:
        std::vector<_Type> _data;
        std::string _disc;

    public:
        A(std::vector<_Type> _d, std::string _s) : _data(_d), _disc(_s) {}

        auto begin() const { return _data.begin(); }

        auto end() const { return _data.end(); }

        ~A() {}
};

/*
    如果使用的是相对原始的 C 风格指针，
    就需要自己重载运算符去满足 std::for_each。

    必须需要重载的运算符有：
    1. * 解引用运算符，使迭代器返回当前指针所指向的数据

    2. ++ 自增运算符，使迭代器移动到下一个位置

    3. != 不等于判断运算符，判断是否到达了迭代器尾部 (begin() != end())

    如果想让容器更加通用，那就需要重载以下运算符：

    [] + - -- == -> ->* 等

    所以说手搓一个迭代器太复杂，这里就不造轮子了，
    其实可以使用 STL 中提供的 std::iterator 为自定义容器创建迭代器。
*/
template <typename _B_Type>
class B
{       
    private:
        _B_Type * _data;
        size_t _size;

    public:
        struct iterator
        {
            _B_Type * _ptr;

            _B_Type & operator*() const { return *_ptr; }

            _B_Type & operator[](size_t _index) 
            { 
                if (_index >= _size) { throw "out of range!\n"; }

                return *(_ptr + _index); 
            }

            iterator & operator+(size_t _index) 
            {
                if (_index >= _size) { throw "out of range!\n"; }

                _ptr += _index;

                return *this;
            }

            iterator & operator++() { ++_ptr;  return *this; } 
            iterator & operator--() { --_ptr; return *this; }

            bool operator!=(const iterator & _other) const { return _ptr != _other._ptr; } 

            bool operator==(const iterator & _other) const { return _ptr == _other._ptr; }
        };

    public:
        B(_B_Type * _d, size_t _s) : _data(new _B_Type[_s]), _size(_s) { std::copy(_d, _d + _s, _data); }

        iterator begin() { return {_data}; }

        iterator end() { return {_data + _size}; }

        ~B() { delete[] _data; }
};

void show_A(int _element) { printf("%d\t", _element); }

/*显然，使用 STL 自己提供的迭代器是没问题的。*/
void TEST_A()
{
    A<int> _a({11, 12, 1456, 35}, "Data 01.");

    std::for_each(_a.begin(), _a.end(), [](int _element) { printf("%d\t", _element); });

    printf("\n");

    std::for_each(_a.begin(), _a.end(), show_A);

    printf("\n");
}

void TEST_B()
{
#define _SHOW_B_ show_A

    int _array[] = {43, 246, 35, 436746, 993};
    
    B<int> _b(_array, 5);
    

    std::for_each(_b.begin(), _b.end(), _SHOW_B_);

    printf("\n");
}

int main(int argc, char const *argv[])
{
    TEST_A();

    TEST_B();

    return 0;
}
