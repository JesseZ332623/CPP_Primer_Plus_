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

const int MIN_PER_HOUR = 60;

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

#if true
int main(int argc, char const *argv[])
{
    using std::cout, std::cin, std::endl, std::ios_base;

    std::srand(time(0));

    /*自动银行柜员机*/
    cout << "Case Study: Bank of Heather Automatic teller" << std::endl;

    /*用户输入最大队列数*/
    cout << "Enter maximum size of Queue: ";
    int queue_size = 0;
    cin >> queue_size;

    _Queue line(queue_size);   /*创建 queue_size 个节点的队列*/

    /*输入要模拟的小时数：*/
    cout << "Enter the number of simulation hours: ";
    int hours = 0;
    cin >> hours;
    
    /*计算出一个周期所需要的时间 （单位：分钟）*/
    long int cycle_limit = MIN_PER_HOUR * hours;

    /*输入每小时的平均客户数：*/
    cout << "Enter the average number of customers per hour: ";
    double per_hour = 0.0000;
    cin >> per_hour;

    /*计算平均到达时间：*/
    double min_per_cust = MIN_PER_HOUR / per_hour;

    Item temp;          /*一个新的客户类*/
    long int turn_aways = 0; /*排队等候*/
    long int customers = 0; /*客户数*/
    long int served = 0;    /*受到服务的客户数*/
    long int sum_line = 0;  /*累计的 线长*/
    long int wait_time = 0; /*等候的时间*/
    long int line_wait = 0; /*在线上累计的时间*/

    for (int cycle = 0; cycle < cycle_limit; ++cycle)
    {
        if (new_customer(min_per_cust))
        {
            if (line.isfull())
            {
                ++turn_aways;
            }
            else
            {
                ++customers;
                temp.set(cycle);
                line.enqueue(temp);
            }
        }
        if (wait_time <= 0 && !line.isempty())
        {
            line.dequeue(temp);
            wait_time = temp.p_time();
            line_wait += cycle - temp.when();
            ++served;
        }
        if (wait_time > 0)
        {
            --wait_time;
        }
        sum_line += line.node_count();
    }

    if (customers > 0)
    {
        cout << "customer accepted: " << customers << endl;
        cout << "customers served: " << served << endl;
        cout << "turnaways: " << turn_aways << endl;
        cout << "Average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double)sum_line / cycle_limit << endl;
        cout << "average wait time: " << (double)line_wait / served << " minutes\n";
    }
    else
    {
        cout << "No customers! \n";
    }

    cout << "Done...";

    return EXIT_SUCCESS;
}
#endif