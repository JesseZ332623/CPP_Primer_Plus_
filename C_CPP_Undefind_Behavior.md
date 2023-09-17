# C_CPP_Undefind_Behavior

未定义行为(Undefind Behavior)：是指 C/C++ 标准中没有定义的行为，程序执行未定义行为的结果完全不可预测。

下面将详细列举 C/C++ 中常见的未定义行为，一些个人难以理解的会作 [_number] 标记并做详细的解释。

C 常见的未定义行为：

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
    (1) 修改 const 对象

    (2) 违反类的访问规则（直接用指针偏移去访问类的私有成员）

    (3) 引用删除后的对象

    (4) 类型名冲突

    (5) 读取未定义的位域

    (6) 重入非重入的函数

    (7) 引用未初始化的变量 (int a; int &b = a;)

    (8) 虚函数表类型错误

    (9) 使用无效的虚函数指针

    (10) 多线程数据竞争

    (11) 违法 one defination rule

    (12) 异常规范不匹配

以前较难理解的条目明天再详解。。。。。

--------------------------------------------------------------------------------------------------------------------------------------------
