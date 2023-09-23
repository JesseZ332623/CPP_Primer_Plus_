/**
    Bank.cpp
*   @author Jesse_EC
*   @date 2023.09.23
*/

/*
    使用 _Queue 类 和 Customer 类来设计一个 客户使用 ATM 机的模拟程序。

    程序的运行流程如下：
    1）判断是否来了新的客户。
    如果来了，且此时队列未满，则把它加入到新队列中，否则拒绝客户入队。

    2）如果没有客户在进行交易，则选取队列的第一个客户。
    确定客户的已等候时间，并将 wait_time 计数器设置为新客户所需的处理时间。

    3)若客户正在处理中，则将 wait_time 计数器 -1

    4）记录各种数据，如：
        1.获得服务的客户数目
        2.被拒绝的客户数目
        3.排队等候的累计时间
        4.累计的队列长度
*/

#include "./src/include/_queue.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.system.h>

/*
    用来确认在循环期间，是否有客户到来。
    函数工作原理如下：
        RAND_MAX 是 rand() 函数可以生成的随机数最大值，
        假设客户到达的平均间隔时间为 6 分钟，
        则 std::rand() * x / RAND_MAX < 1 表达式的值会在 0 ~ 6 之间。
*/
bool new_customer(double x);

bool new_customer(double x)
{
    return (std::rand() * x / RAND_MAX < 1);
}


int main(int argc, char const *argv[])
{
    int true_count = 0;
    int false_count = 0;
    int times = 0;

    while (true)
    {
        //system("cls");
        if (new_customer(6.00))
        {
            ++true_count;
            std::cout << "min: " << times << ": " << true_count << std::endl;
        }
        else 
        {
            ++false_count;
            std::cout << "min: " << times << ": " << false_count << std::endl;
        }

        //Sleep(1000);
        ++times;
    }

    return EXIT_SUCCESS;
}
