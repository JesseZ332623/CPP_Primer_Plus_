# CPP_Primer_Plus_

Date: 2023-08-20

自己的C++练习 .

Date: 2023-09-07

提交至github，结果把另外一个分支提交上去了，折腾了一下算是搞定了。。。。

Date:2023-9-15
    类的自动转换和强制转换 （P 334）：

(1) 类的自动转换

假设有一个类，他的声明如下：

```C++
class Stonewt
{
    private:
        enum { LBS_PER_STN = 14 };      /* 1 英石 = 14 磅 */

        int stone;
        double pds_left;
        double pounds;
            
    public:
        Stonewt();
        Stonewt(double lbs);
        Stonewt(int stn, double lbs);
                
        void show_lbs() const;
        void show_stn() const;

        ~Stonewt() {};
};
```

一般情况下，是这样初始化这个类的：

```C++
Stonewt stonewt(53.750); 
```

或

```C++  
Stonewt stonewt(10 ,53.750);
 ```

当然，也有一个特殊的方法：

```C++
Stonewt stonewt = 100.00;
```  

等价于

```C++
Stonewt stonewt = Stonewt(100.00);
```

stonewt 是一个 object，100.00 是一个 double 类型，stonewt 内有三个构造函数，会将这个  double 类型强制转换成一个 Stonewt 值，
然后与内部的构造函数匹配，看看是否有正确的参数列表。

(2) 类的强制转换：

那么，这样的表达式合法吗？

```C++
Stonewt stonewt(53.750); 
double object_data = stonewt;
```

答案是合法的，但是需要在类声明里面添加如下的转换函数声明：

```C++
class Stonewt
{
    private:
        enum { LBS_PER_STN = 14 };      /* 1 英石 = 14 磅 */

        int stone;
        double pds_left;
        double pounds;
            
    public:
        Stonewt();
        Stonewt(double lbs);
        Stonewt(int stn, double lbs);
                
        void show_lbs() const;
        void show_stn() const;

         /*conversion function*/
        operator int() const;       /*对 int 类型的强制转换*/
        operator double() const;    /*对 double 类型的强制转换*/

        ~Stonewt() {};
};
```

conversion function 的实现如下：

```C++
Stonewt::operator int() const
{
    return int(pounds + 0.5);       /*这里 +0.5 是为了四舍五入*/
}

Stonewt::operator double() const
{
     return pounds;
}
```

有了这些函数，就可以进行强制转换，例子如下

```C++
Stonewt _stont_t(10, 25.58);

/*转换成 int 类型*/
std::cout << int(_stone_t) << "pounds. \n";     /*值为 165*/

/*转换成 double 类型*/
std::cout << stone_t << "pounds. \n";           /*值为 165.58*/
```

tips:使用此类函数时，务必要避免二义性。

显示的强制转换 （explicit 关键字）
在 类声明成员转换函数时，在函数前面加上 explicit 关键字，就可以显示的进行转换，如下：

```C++
class Stonewt
{
    private:
        enum { LBS_PER_STN = 14 };      /* 1 英石 = 14 磅 */

        int stone;
        double pds_left;
        double pounds;
            
    public:
        Stonewt();
        Stonewt(double lbs);
        Stonewt(int stn, double lbs);
                
        void show_lbs() const;
        void show_stn() const;

        /*conversion function*/
        explicit operator int() const;       /*对 int 类型的强制转换*/
        explicit operator double() const;    /*对 double 类型的强制转换*/

        ~Stonewt() {};
};
```

这样以来，像 double pounds = stone_wt; 这样的隐式转换就不能生效了，
必须使用 double pounds = double(stone_wt); 这样的语句显式的转换数据，避免了一些不必要的麻烦。

Date:2023.09.16 书本编程题 P345 11.9.7 Complex 类的实现

```C++
/**
 * 书本编程题 P345 11.9.7
 * 完成复数 Complex 类的设计，要完成如下操作：
 * （1）基本的运算 （假设有两个复数 a = (A,Bi) b = (C, Di)）：
 *      +   a + b = (A + C, Bi + Ci)
 *      -   a - b = (A - C, Bi - Ci)
 *      *   a * b = ((A * C - B * D), (A * D + Bi * C)i)
 *      *   x * a = (x * A, x * Bi) [其中 x 为实数]
 *      ~      ~a = (A, -Bi)
 * 
 *  (2) 重载 << 和 >> 符号 完成复数值的输入与输出
 *      
 *      << friend std::ostream & operator<<(std::ostream & _os, Complex & comp);
 *      >> friend std::istream & operator>>(std::istream & _enter, Complex & comp);
*/

//类声明如下：
class Complex
{
    private:
        double real_number;
        double imaginary_number;
        
    public:
        Complex();
        Complex(double real_number, double imaginary_number);

        void set_real(double real_num) { real_number = real_num; }
        void set_imaginary(long double imag_num) { imaginary_number = imag_num; }

        Complex operator+(Complex & comp_2) const;

        Complex operator-(Complex & comp_2) const;

        Complex operator*(Complex & comp_2) const;

        Complex operator*(double x) const;

        friend Complex operator*(double x, Complex & comp)
        {
            return Complex(x * comp.real_number, x * comp.imaginary_number);
        }

        Complex operator~() const;

        friend std::ostream & operator<<(std::ostream & _os, Complex & comp)
        {
            _os << '(' << comp.real_number << ", " << comp.imaginary_number << "i)";

            return _os;
        }

        friend std::istream & operator>>(std::istream & _enter, Complex & comp)
        {
            double real_number;
            double imaginary_number;   

            std::cout << "Real Number: ";
            _enter >> real_number;

            std::cout << "Imaginary Numbe: ";
            _enter >> imaginary_number;

            comp.set_real(real_number);
            comp.set_imaginary(imaginary_number);

            return _enter;
        }

        ~Complex() {}
    };
```

具体的实现和用例 见 exercise_questions\11_9_7

Date:2023.09.17 章节 12：类的动态内存分配
