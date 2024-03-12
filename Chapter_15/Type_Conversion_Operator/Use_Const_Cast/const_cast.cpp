#include <iostream>

using std::cout, std::endl;

/*
    const_cast 用于只有一种用途的类型转换，即改变值为 const 或 volatile，语法和 dynamic_cast 一样：

        const_cast<type-name>(expression)

    若类型的其他方面也被修改，则上述转换也将出错。即除了 const 和 volatile 特征（有 / 无）可以不同外，
    type-name 和 expression 的类型必须相同。
*/

/**
 * @brief 通过 const_cast 运算符将 __pt 转为非 const 的指针，然后再加上 __n
 * 
 * @param __pt 传入的 const int * 类型指针
 * @param __n 要相加的数字
 * 
 * @return non-return
*/
void change(const int * __pt, int __n);

void change(const int * __pt, int __n)
{
    int * noConst = const_cast<int *>(__pt);

    (* noConst) += __n;
}

/*
    程序的输出为：

        pop_1 = 228283 pop_2 = 2000
        pop_1 = 142797 pop_2 = 2000

    可以看出：pop_2 的值未被修改，原因很简单：
    指针 noConst 通过 const_cast 删除了 __pt 的 const 特征，
    但是此时 __pt 所对应的值是 const 的，因此调用函数：

        change(&pop_2, 114514);    

    中的
    
        (* noConst) += __n;
    
    语句就无效了。
    
*/
int main(int argc, char const *argv[])
{
    int pop_1 = 28283;
    const int pop_2 = 2000;

    cout << "pop_1 = " << pop_1 << " pop_2 = " << pop_2 << endl;

    change(&pop_1, 114514);
    change(&pop_2, 114514);

    cout << "pop_1 = " << pop_1 << " pop_2 = " << pop_2 << endl;

    return EXIT_SUCCESS;
}
