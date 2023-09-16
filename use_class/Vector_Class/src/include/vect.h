/**
 * vect.h @author Jesse_EC 
 * @date 2023.09.08
*/
/*
    Target: 实现一个矢量类，
    用户可以使用这个类来计算矢量，实现：
    1）两个 Vector 类的加减 vec_a +/- vec_b
    2）求一个矢量的负值     (x, y) -> (-x, -y) 
    3）将一个矢量延长 n 倍    vac_a * n

    在此之前先说明几个公式：
    1) 通过直角坐标求矢量长度L：L = √x² + y²
    2）通过直角坐标求矢量度数D：D = atan(y / x) * 180 / π 或 45 / atan(1)
    3) 通过极坐标求直角坐标 x 的值：x = L * cos(D)
    4) 通过极坐标求直角坐标 y 的值：x = L * sin(D)
*/

#ifndef _VECT_H_
#define _VECT_H_

#include <iostream>

namespace VECTOR
{
    class Vector
    {
        public:
            /*
            表示矢量可以用两种方式:
                1）向 53.1 度行进 50 个单位
                2）向 X 轴 行进 30 单位，再向 Y 轴行进40单位

                因此，可以声明一个枚举类型的变量 Mode，来对这两种表达模式进行切换。
                1) RECT 极坐标 2) POL 直角坐标 
            */
            enum Mode {RECT, POL};      
        private:
            Mode mode;

            double mag;     /*表达方式 1）*/
            double ang;
            double x;       /*表达方式 2）*/
            double y;

            /* 一些私有方法，用于设置类私有数据的值。*/
           void set_mag();
           void set_ang();
           void set_x();
           void set_y();

        public:
            /*Vector 类的构建函数，有两个重载*/
            Vector();

            /**
                Vector类函数的第一个重载：
            *   @param n1 矢量的第一个参数
            *   @param n2 矢量的第二个参数
            *   @param from 表达模式，默认为 RECT
            */
            Vector(double n1, double n2, Mode form = RECT);

            /**
             *  用于重设矢量的值以及模式，参数和构建函数一样
             *  @param n1 矢量的第一个参数
            *   @param n2 矢量的第二个参数
            *   @param from 表达模式，默认为 RECT
            */
            void reset(double n1, double n2, Mode form = RECT);

            /*
                用于返回各个私有数据的值
            */
            double xval() const { return x; }
            double yval() const { return y; }
            double magval() const { return mag; }
            double angval() const { return ang; }
            
            /**
                用于模式的切换
            *   @param _mode 枚举类型，有 RECT 和 POL 两个成员
            */
            void mode_set(Mode _mode);

            /*
                对符号进行重载，
                用户可以使用 + - * 三个运算符对 Vector 类对象进行操作
            */

           /**
            *   对两个矢量对象相加。Eg. vec_c = vac_a + vec_b
            *   @param vec A reference of class Vector
            *   @param const Implicitly calling an object
            *   @return class Vector object 
           */
            Vector operator+(const Vector & vec) const;

            /**
            *   对两个矢量对象相减。Eg. vac_a - vec_b = vec_c
            *   @param vec A reference of class Vector
            *   @param const Implicitly calling an object
            *   @return class Vector object 
           */
            Vector operator-(const Vector & vec) const;

            /**
            *   对两个矢量对象相减（重载 1） 用于表示一个矢量的负值 Eg. (10, 11) -> (-10, -11)。
            *   @param const Implicitly calling an object
            *   @return class Vector object 
           */
            Vector operator-() const;

            /**
            *   将一个矢量延长 n 倍（重载 * 运算符）
            *   @param n 延长的倍数 n 
            *   @param const Implicitly calling an object
            *   @return class Vector object 
            */
            Vector operator*(double n) const;

            /**
            *   将一个矢量延长 n 倍（重载 * 运算符，但是友元函数）
            *   @param n 延长的倍数 n 
            *   @param const Implicitly calling an object
            *   @return class Vector object 
            */
            friend Vector operator*(double n, const Vector & vec);

            /**
            *   重载 << 运算符来显示类 Vector 的值。 Eg. std::cout << vec << std::endl;
            *   @param os 流式输出对象，一般是 std::cout
            *   @param vec Vector类对象
            */
            friend std::ostream & operator<<(std::ostream & os, Vector & vec);
            
            /**
            *   用于模式的切换
            *   @param vec Vector 类对象的引用
            *   @param _mode 枚举类型，有 RECT 和 POL 两个成员
            */
            friend void mode_set(Vector & vec, Mode _mode);

            /*
                一个转换函数，
                将 Vector 类对象转换成 double 类型的值，表示矢量的长度。
            */
            explicit operator double() const { return magval(); }

            ~Vector() {}
    };
};

#endif