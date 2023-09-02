#include "./head_file/scope.h"


void Scope_Class::oil(int texas, std::string str)
{
    using namespace std;
    str += "value";

    cout << "In oil() texas = " << texas << ' ' << "Address: " << &texas << endl;
    
}

template <typename Type>
inline Type Calculate(Type a, Type b)
{
    return a += b;
}

char buffer_01[36];
char buffer_02[500];
int main(int argc, char const *argv[])
{
    system("cls");

    chaff *ptr_1, *ptr_2;
    //int *p3;

    ptr_1 = new chaff;      /*为指针 ptr_1 分配内存 24Bytes*/

    ptr_2 = new (buffer_01) chaff {"_placement new constructing_", 10};      /*从静态存储的字符串 buffer_01 中借34字节的内存分配给 ptr_2*/
    //p3 = new (buffer_02) int[20];       /**/
    
    for (int index = 0; index < 32; ++index)
    {
        std::cout << buffer_01[index];
    }
    
    std::cout.put('\n');
    std::cout << ptr_2->dross << ' ' << ptr_2->slag << '\n';
    

    delete ptr_1;
    delete ptr_2;
    return EXIT_SUCCESS;
}
