#include <stdio.h>
#include <string.h>
#include <limits.h>

typedef unsigned long long int U_LLInt;

struct Data
{
    double data[200];
};

struct Junk
{
    int junk[100];
};

/*
    在 C 语言中，类型的转换过于松散，错误使用会造成未定义行为，看如下代码：

    #1 #2 #3 #4 合法吗？在 C 语言中答案是肯定的，但是有意义吗？没有多大意义。。。。
*/
int main(int argc, char const *argv[])
{
    struct Data dat = {2.5e33, 3.5e-19, 20.2e32};

    char * chPtr = (char *)(&dat);              // #1 convert address to C style string.            Legitimate but meaningless
    char ch = (char)(&dat);                     // #2 convert address to character.                 UnLegitimate but meaningless         
    struct Junk * jPtr = (struct Junk *)(&dat); // #3 convert (Data *) to (Junk *).                 Legitimate but meaningless
    U_LLInt datAddress = (U_LLInt)(&dat);       // #4 convert (Data *) to unsigned long long int    Legal but somewhat meaningful

    printf("%lld\n", datAddress);

    return 0;
}
