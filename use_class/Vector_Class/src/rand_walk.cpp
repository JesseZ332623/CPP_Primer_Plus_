/**
 * rand_walk.cpp 
 * 使用 Vector 类模拟随机漫步（醉鬼问题）
 * @author Jesse_EC
 * @date 2023.09.13
*/
/*
    随机漫步情景如下：
        将一个人领导灯柱上，这个人以灯柱为原点开始走动，
        但每一步的方向都是随机的。
    举例：一个人从灯柱出发，每步的步长约 2 m ，来到距离灯柱 50 m 的距离需要多少步？
    程序需要返回：
        1）步数
        2）这个人目前的坐标（直角坐标 和 极坐标两种表达模式）
*/

#include "include/vect.h"
#include <cstdlib>
#include <ctime>
#include <windows.system.h>

int main(int argc, char const *argv[])
{
    using namespace std;
    using VECTOR::Vector;

    system("cls");

    srand(time(0));                 /*随机数函数的初始化*/

    /*
        step 矢量类 记录行走者每一步的行走情况。
        每一次循环都会重设一个方向。
    */
    Vector step;                                    
    Vector result(0.00, 0.00, Vector::RECT);        /*result 矢量类 记录行走者的前进情况*/

    double direction = 0.00;                        /*方向数据，单位是度*/
    double target = 0.00;                           /*原点距离目标的长度*/
    double d_step = 0.00;                           /*行走者的步长*/

    unsigned long int steps = 0;                    /*行走者走过的步数*/
    
    cout << "Enter target distance (q to quit and target > 0): ";      /*输入离目标的距离 如：50 m*/
    while (cin >> target)
    {
        if (target < 0)
        {
            cout << "target value must > 0 \n";
            break;
        }
        
        cout << "Enter step length: ";                  /*输入每一步的长度 如：2 m*/
        if (!(cin >> d_step))
        {
            break;
        }
        /*
            只要行走着还没行走到用户输入的距离，
            循环体内执行的是行走者每一步要发生的事件。
        */
        while (result.magval() < target)                
        {
            direction = rand() % 360;                   /*生成一个 0 - 359 的随机数，并赋值给 direction*/
            /*
                将 步长（d_step） 和 方向（direction）数据传入 reset 方法中，
                以重设 step 对象， step 对象用直角坐标的格式表示数据。
            */
            step.reset(d_step, direction, Vector::POL); 

            result = result + step;         /*将生成的新矢量 与 行走者当前的矢量进行累加 （没有重载 += 运算符）*/
            steps++;                        /*行走者走过的步数 + 1*/
        }

        /*
            循环结束，输出结果，其格式为：
                After <steps> steps, the subject has the following location:
                [x, y] = (x, y) or [m, a] = (m, a)
                Average outward distance per step = result.magval() / <steps>
               （每一步的平均向外距离）
        */
        cout << "After " << steps << " steps, the subject "
                                     "has the following location:\n";
        cout << result;
        result.mode_set(Vector::POL);
        cout << result << endl;
        cout << "Average outward distance per step = "
             << result.magval() / steps << " degrees." << endl;
        steps = 0;
        result.reset(0.00, 0.00, Vector::RECT);
        cout << "Enter target distance (q to quit): ";                            
    }
    cout << "Bye!\n";
    cin.clear();
    while (cin.get() != '\n')
    {
        continue;
    }

    return EXIT_SUCCESS;
}
