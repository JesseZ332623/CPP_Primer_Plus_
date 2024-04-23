#include <iostream>
#include <cstring>
#include <cstdlib>
/*
    std::cout 的用法很简单，但这一个程序主要练习 std::cout 的 put() 和 write() 成员方法，
    以及探究 std::cout 拼接输出的特性。
*/

void use_put()
{
    //std::cout.put() 成员方法用于显示单个字符，基本用法如下：
    std::cout.put('A');     /*在标准输出中输出 A*/
    std::cout.put(65);      /*哪怕使用数字，也会被转换成对应的字符*/


    std::cout.put('A').put('B').put('C');   /*由于 put() 返回 std::ostream & 类型，因此可以拼接输出*/
}

void use_write()
{

    /*
        std::cout.write() 成员方法用于在标准输出中显示字符串，它有两个参数：
        1. const char * __s     要显示的字符串的地址
        2. std::streamsize __n  要显示的字符串长度
    */

   //std::cout.write("123", 2);       /*在标准输出中显示 "12"*/

    const char * state1 = "Florida";

    std::cout << "Increasing Loop Index: \n";
    for (int index = 0; index < std::strlen(state1); ++index)
    {
        std::cout.write(state1, index);
        std::cout.put('\n');
    }
    for (int index = 0; ; ++index)
    {
        /*由于 write() 方法也返回 std::ostream & 类型，因此也可以拼接输出*/
        std::cout.write(state1, index) << std::endl;
        //std::cout.put('\n');

        if (index >= std::strlen(state1)) { index = 0; }
    }       
    
}

void concatenate_out_put()
{
    /*
        接下来探讨一下 std::cout 拼接输出的过程，下面有一个例子：
    */
    std::string name = "Jesse";
    int age = 21;

    /*
        这条 cout 语句输出什么我们再清楚不过，
        但这条 cout 语句的工作流程是什么和多人却知之甚少。
        它的流程如下：

        1. 将 字符串 "My name is: " 发送给输出缓冲区 此时的语句为：std::cout << name << " and I'm " << age << " years old." << std::endl;

        2. 将 std::string 类型的对象 name (std::cout 已重载) 发送给输出缓冲区，此时语句为：std::cout << " and I'm " << age << " years old." << std::endl;

        3. 将 字符串 " and I'm " 发送给输出缓冲区 此时的语句为：std::cout << age << " years old." << std::endl;

        4. 将 int 类型数据 21 转换成文本形式表达的字符流然后发送到输出缓冲区 此时的语句为：std::cout << " years old." << std::endl;

        5. 将 字符串 " years old." 发送给输出缓冲区 此时的语句为：std::cout << std::endl;

        6. 最后 将 std::endl（换行并调用 flush() 刷新缓冲区） 发送给输出缓冲区，这条语句全部执行完毕。

        在标准输出的上的内容是：
        My name is: Jesse and I'm 21 years old.
    */
    std::cout << "My name is: " << name << " and I'm " << age << " years old." << std::endl;
}

int main(int argc, char const *argv[])
{
    concatenate_out_put();
    return EXIT_SUCCESS;
}
