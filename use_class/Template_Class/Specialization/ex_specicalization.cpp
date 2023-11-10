/**
 * 上面讲了多参数的模板类，先来来讲一下类的显式实例化（或者叫特化 explicit specialization）
 * 
 * 显示实例化 是指特点类型（用于替换模板中的泛型）的定义。
 * 有些时候，可能需要在为特殊类型实例化时，对模板进行修改，使其行为不同。
 * 
 * 当具体化模板和通用模板都与实例化请求匹配时，编译器将使用具体化版本。
*/

#include <iostream>
#include <cstring>

/*模板类*/
template<typename Data_Type>
class EX_Specialization
{
    private:
        Data_Type dat;

    public:
        EX_Specialization() : dat(0) {}
        EX_Specialization(Data_Type _dat) : dat(_dat) {}
        void show() const { std::cout << dat << '\n'; }

        ~EX_Specialization() {}
};

/*全特化，处理 C 风格的字符串*/
template<>
class EX_Specialization<char *>
{
    private:
        char * _str;
        enum  { DEFAULT_SIZE = 12};

    public:
        EX_Specialization() : _str(new char[DEFAULT_SIZE]) {}
        EX_Specialization(const char * _s) : _str(new char[std::strlen(_s)]) { std::strcpy(_str, _s); }

        void show() { printf("%s\n", _str); }

        ~EX_Specialization() { delete[] _str; } 
};

int main(int argc, char const *argv[])
{
    
    EX_Specialization<double> ex_01(12.1345);
    EX_Specialization<char *> ex_02("全特化，处理 C 风格的字符串");

    ex_01.show();
    ex_02.show();

    return EXIT_SUCCESS;
}
