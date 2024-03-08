/*
    15_7_1: 下面建立友元的尝试有何错误？
*/
#include <iostream>

#define SUB_QUESTION_A false
#define SUB_QUESTION_B false

#if SUB_QUESTION_A

/*
    .\try_establish_friends.cpp:13:12: error: 'Clasp' does not name a type
   13 |     friend Clasp;
      |            ^~~~~

    错误很显然，Clasp 类的声明在 Snap 类声明之后，编译器无法识别
*/
class Snap
{
    friend Clasp;
};

class Clasp {};

#endif

#if SUB_QUESTION_B

/*
    g++ .\try_establish_friends.cpp -o .\bin\try_establish_friends
    .\try_establish_friends.cpp:32:19: error: 'Muff' has not been declared
    32 |         void snip(Muff &) {  }
       |                   ^~~~
    .\try_establish_friends.cpp:37:17: error: no declaration matches 'void Cuff::snip(Muff&)'
    37 |     friend void Cuff::snip(Muff &);
       |                 ^~~~
    .\try_establish_friends.cpp:32:14: note: candidate is: 'void Cuff::snip(int&)'
    32 |         void snip(Muff &) {  }
       |              ^~~~
    .\try_establish_friends.cpp:29:7: note: 'class Cuff' defined here
    29 | class Cuff
       |       ^~~~

    错误也很明显，在声明 Cuff 时，Muff 还不明确。
*/
class Muff 
{
    friend void Cuff::snip(Muff &);
};

class Cuff 
{
    public:
        void snip(Muff &) {  }
};

#endif

int main(int argc, char const *argv[])
{
    
    return 0;
}
