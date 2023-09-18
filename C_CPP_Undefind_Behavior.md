# C_CPP_Undefind_Behavior #

未定义行为(Undefind Behavior)：是指 C/C++ 标准中没有定义的行为，程序执行未定义行为的结果完全不可预测。

下面将详细列举 C/C++ 中常见的未定义行为，一些个人难以理解的会作 [_number] 标记并做详细的解释。

--------------------------------------------------------------------------------------------------------------------------------------------

C 常见的未定义行为：

===================================

(1) 访问数组越界

[2] 访问空指针，或悬空指针。

(3) 访问未初始化的变量。

[4] 修改字符串的字面量。（或者叫只读内存区域）  

[5] 返回局部变量的地址。

(6) 类型转换，如 double->int 导致的截断。

(7) 除数为 0 （如 7 / 0 会触发未定义行为，但是现代的编译器都会发现这个问题。 warning: division by zero）

(8) 调用未实现的函数 （和 (7) 一样，现代编译器也会捕获这个问题。 undefined reference to 'function_name'）

[9] 对同一变量进行两次赋值的序列点 （啥玩意？）。

--------------------------------------------------------------------------------------------------------------------------------------------

[2] 访问空指针，或悬空指针。

```C

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int *ptr = (int *)malloc(10 * sizeof(int));

    free(ptr);          /*此时，这个指针以及被释放， ptr 为悬空指针*/

    *ptr = 1000;        /*如果继续访问该指针，会触发未定义行为，导致程序奔溃*/

    return 0;
}
```

所以需要这样修改：

```C
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int *ptr = (int *)malloc(10 * sizeof(int));

    free(ptr);          /*此时，这个指针以及被释放， ptr 为悬空指针*/

    *ptr = NULL;        /*将已经被释放的指针的值设置为 NULL*/

    return 0;
}
```

--------------------------------------------------------------------------------------------------------------------------------------------

[4] 修改字符串的字面量。（或者叫只读内存区域）  

```C
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char str[10] = "hello";     /*此时字符串 hello 是保存在只读空间的，不可修改。*/

    str[0] = 'H';               /*强行修改该字符串会触发未定义行为，结果不可预测*/

    return 0;
}
```

所以需要这样做：

```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char str[5] = "hello";     /*此时字符串 hello 是保存在只读空间的，不可修改。*/
    char _str[5];

    strcpy(_str, str);          /*将字符串拷贝到新字符串*/

    _str[0] = 'H';              /*然后再进行修改*/

    /*当然使用 const 关键字也是可以的。*/
    const char str[5] = "hello";
}
```

--------------------------------------------------------------------------------------------------------------------------------------------

[5] 返回局部变量的地址。

```C
#include <stdio.h>
#include <stdlib.h>

int *function();

int *function()
{
    int number = 10;           /*在栈空间声明了临时变量 作用域为这个函数*/

    return &number;             /*返回这个变量的地址，但是这个变量已经被销毁。。。。*/
}

int main(int argc, char const *argv[])
{
    int *ptr = function();

    printf("%d", *ptr);         /*如果强行访问这个地址，结果是不可预测的。*/

    return 0;
}
```

所以需要这样修改：

```C
#include <stdio.h>
#include <stdlib.h>

int *global_ptr = NULL;

int *function();

int *function()
{
    global_ptr = (int *)malloc(sizeof(int));    /*在使用 malloc 函数堆空间里面申请内存*/
    static number = 0;                          /*或者使用 static 关键字，改变变量的存储方式和作用域*/

    *global_ptr = 0;

    return global_ptr;             /*返回这个指针变量*/
}

int main(int argc, char const *argv[])
{
    int *ptr = function();

    printf("%d", *ptr);         /*此时访问这个地址，结果是 0*/

    free(global_ptr);

    return 0;
}
```

--------------------------------------------------------------------------------------------------------------------------------------------

C++ 常见的未定义行为：

======================================

(1) 修改 const 对象

(2) 违反类的访问规则（直接用指针偏移去访问类的私有成员）

[3] 引用删除后的对象

(4) 类型名冲突

(5) 读取未定义的位域

[6] 重入非重入的函数

(7) 引用未初始化的变量 (int a; int &b = a;)

(8) 虚函数表类型错误

(9) 使用无效的虚函数指针

(10) 多线程数据竞争

(11) 违反 one defination rule

(12) 异常规范不匹配

以前较难理解的条目明天再详解。。。。。

--------------------------------------------------------------------------------------------------------------------------------------------

[3] 引用删除后的对象

首先了解一下引用和指针的几个区别：

(1) 引用必须在初始化时绑定到一个对象,之后不能修改为指向另一个对象。指针可以在任何时候指向不同的对象。

(2) 引用在语法上更像对象本身,可以直接访问对象成员。指针需要解引用才能访问所指对象。

(3) 引用不能为空(nullptr)，指针可以为空。

```C++
/*test.h*/
/*篇幅需要，大部分成员方法的实现都是内联的。*/
#include <iostream>
class My_Class
{
    private:
        int value;

    public:
        My_Class()  { value = 0; }
        My_Class(int _val) { value = _val; }

        void show_value() {
            std::cout << value << std::endl;
        }

        ~My_Class() {}
};

/*Test.cpp*/
#include "./test.h"

My_Class & function(int _val);      /*一个返回 My_Class 类引用的函数*/

My_Class & function(int _val)
{
    My_Class my_class(_val);

    return my_class;            /*返回 my_class的引用，但此时这个对象已经被销毁。。。。*/
}
    
int main(int argc, char const *argv[])
{
    My_Class &class_ref = function(11);     /*声明一个 My_Class 类型的引用，接受函数 function 的返回值*/

    std::cout << class_ref.show_value();    /*但由于那个对象已经被销毁，如果强行访问，结果不可预测。*/
}
```

当然修改的方式也很简单，使用 static 关键字改变存储方式和作用域，或者使用 new 操作符在堆(heap)中申请内存即可。

--------------------------------------------------------------------------------------------------------------------------------------------

[6] 重入非重入的函数

重入函数 (Reentrant function)，是指可以同时被调用多次的函数，比如线程安全函数就是重入的。

非重入函数 (Non-Reentrant function)，是指不能同时被多次调用，需要单线程串行执行。

调用一个非重入函数的同时，再次调用他本身，就会产生未定义行为。
