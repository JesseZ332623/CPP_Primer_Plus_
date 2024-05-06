<!-- markdownlint-disable MD033 -->

# CPP_Primer_Plus

## Date: 2024.5.7

# 恭喜 Jesse，学完了此书，你以熟练掌握 C++ 基础，可以开始学习更多进阶的内容了

记录了我学习《C++ Primer Plus》的详细过程，基本上每天都更新。

## 当前学习完第 `18` 章，已经完成全部练习题

--------------------------------------------------------------------------------------------------------------------------------------------

## Date:2023-9-15 类的自动转换和强制转换 （P 334）

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

--------------------------------------------------------------------------------------------------------------------------------------------

## Date:2023.09.16 书本编程题 P345 11.9.7 Complex 类的实现

```C++
/**·
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

--------------------------------------------------------------------------------------------------------------------------------------------

## Date:2023.09.17 章节 12：类的动态内存分配之实现一个简单的 String 类

设计一个字符串类，要求实现如下的字符串基本操作：

1）求字符串的长度

2）字符串的赋值操作，分为：
    1.字符串类 赋值给 字符串类
    2.字符串 赋值给 字符串类

3）单个字符查找，分为：
    1.对只读字符串的查找
    2.对非只读字符串的查找

4）字符串的比较，分为：
    1.比较哪个字符串的 ASCII 值大
    2.比较两个字符串是否相等

5）字符串的输入与输出（重载 << 以及 >> 运算符）

6） 将字符串输出至文件

当然，标准库中的字符串类，远比这个要复杂。。。。。

_String 类的设计如下：

```C++
class _String
{
    private:
        char *str;          /*字符串本体*/
        size_t _length;     /*字符串长度*/

        /*当前字符串类的数量*/
        static int str_count;

        /*用户可以输入的字符串最大长度*/
        static const int CIN_LIMIT = 80;        

    public:
        /*
            _String 类的构建函数，考虑三种情况：
            1.默认构建函数
            2.传入字符串的构建函数
            3.传入字符串类的构建函数

            构建函数们要做以下四件事：
            1.获取字符串长度
            2.使用 new 关键字在堆空间分配内存
            3.将传入的字符串拷贝或者初始化为 '\0'
            4.自增字符串数量
        */
        _String();
        _String(const char *_str);
        _String(_String & str_object);

        /*求字符串长度*/
        const size_t length() { return _length; }

        /*字符串的赋值操作 字符串类 赋值给 字符串类*/
        _String & operator=(const _String & str_object);

        /*字符串的赋值操作 字符串 赋值给 字符串类*/
        _String & operator=(const char *_str);

        /*单个字符查找*/
        char & operator[](int index);
        const char & operator[](int index) const;

        /*字符串的比较*/
        friend bool operator>(const _String & _str_1, const _String & _str_2);
        friend bool operator<(const _String & _str_1, const _String & _str_2);
        friend bool operator==(const _String & _str_1, const _String & _str_2);

        friend ostream & operator<<(ostream & _os, const _String & _str);
        friend ofstream & operator<<(ofstream & _fs, const _String & _str)
        {
            _fs << _str.str;

            return _fs;
        }

        friend istream & operator>>(istream & _is, const _String & _str);

        static const size_t String_Count();

        ~_String();
};
```

类各个函数的实现和一些用例请见：String_Class\sayings.cpp

--------------------------------------------------------------------------------------------------------------------------------------------

## Date:2023.09.24 章节 12：类的动态内存分配之实现一个 Queue(队列) 类

target：设计一个 _Queue 类，要求实现一些队列的基本操作，如下：

1）判断队列是否为空     bool isempty() const;

2）判断队列是否为满     bool isfull() const;

3）入队                bool enqueue(const Item & item);

4）出队                bool dequeue(Item & item);

5）输出目前队列的节点数 int node_count() const;

此外，为了满足两个对象相互复制，以及在没有内存泄漏的情况下删除整个队列，
_Queue 类的构建函数，析构函数，以及运算符重载函数如下：

private:

(1) _Queue(const Queue & q) : max_size(0);

(2) _Queue & operator=(const Queue & q) { return *this; }

public:

_Queue(int size = MAX_SIZE);

~_Queue();

```C++
class _Queue
{
    private:
        enum { MAX_SIZE = 10 };         /*最大节点数的默认值是 10*/
        const int max_size;             /*最大节点数*/
        int items;                      /*当前节点数*/
        
        struct Node { Item item; struct Node *next; };      /*一个队列节点的构成*/
        Node *front;        /*队列头节点指针*/
        Node *rear;         /*队列尾节点指针*/

        _Queue(const _Queue & q) : max_size(0) {}           /*用于拷贝的构建函数和符号重载*/
        _Queue & operator=(const _Queue & q) { return *this; }

    public:
        _Queue(int size = MAX_SIZE);

        bool isempty() const;   /*检查队列的状态 （空/满）*/
        bool isfull() const;

        bool enqueue(const Item & item);    /*入队*/
        bool dequeue(Item & item);          /*出队*/

        int node_count() const;             /*返回当前队列节点的数量*/

        ~_Queue();      /*析构函数用于删除整个队列的数据*/
};
```

_Queue 类 的实现以及用例请见目录  .\Queue\

--------------------------------------------------------------------------------------------------------------------------------------------

## Date:2023.9.28 练习 12_10_2： 一个升级版的 _String 类

对原有的 _String 类（./String_Class）进行升级，增加了如下功能：

1）重载 + 运算符，用于合并字符串

2）提供一个 string_low() 函数，将字符串所有字母函数转换成小写

3）提供一个 string_upper() 函数，将字符串所有字母函数转换成大写

4）提供一个 appear_times() 函数，传入一个字符，返回这个字符在字符串中出现的次数

目前升级后的 _String 类如下所示：

```C++
class _String
{
    private:
        char *str;          /*字符串本体*/
        size_t _length;     /*字符串长度*/

        /*当前字符串类的数量*/
        static int str_count;

        /*用户可以输入的字符串最大长度*/
        static const int CIN_LIMIT = 80;        

    public:
        /*
            _String 类的构建函数，考虑三种情况：
            1.默认构建函数
            2.传入字符串的构建函数
            3.传入字符串类的构建函数

            构建函数们要做以下四件事：
            1.获取字符串长度
            2.使用 new 关键字在堆空间分配内存
            3.将传入的字符串拷贝或者初始化为 '\0'
            4.自增字符串数量
        */
        _String();
        _String(const char *_str);
        _String(_String & str_object);
        
        /*将字符串全部转换成小写*/
        void string_low();

        /*将字符串全部转换成大写*/
        void string_upper();

        const size_t appear_times(const char _ch) const; 

        /*求字符串长度*/
        //void set_length(size_t len) { _length = len; }
        const size_t length() { return _length; }

        /*字符串的赋值操作 字符串类 赋值给 字符串类*/
        _String & operator=(const _String & str_object);

        /*字符串的赋值操作 字符串 赋值给 字符串类*/
        _String & operator=(const char *_str);

        /*单个字符查找*/
        char & operator[](int index);
        const char & operator[](int index) const;

        /*合并字符串*/
        _String operator+(const _String & _str) const;
        _String operator+(const char * c_str) const;

        friend _String operator+(const char *c_str, const _String _str);

        /*字符串的比较*/
        friend bool operator>(const _String & _str_1, const _String & _str_2);
        friend bool operator<(const _String & _str_1, const _String & _str_2);
        friend bool operator==(const _String & _str_1, const _String & _str_2);

        

        friend ostream & operator<<(ostream & _os, const _String & _str);
        friend ofstream & operator<<(ofstream & _fs, const _String & _str)
        {
            _fs << _str.str;

            return _fs;
        }

        friend istream & operator>>(istream & _is, const _String & _str);

        static const size_t String_Count();

        ~_String();
};
```

对于这个类的测试用例请见目录 exercise_questions\12_#_#\12_10_2\_String_2\pel2_2.cpp

--------------------------------------------------------------------------------------------------------------------------------------------

## Date 2023.10.2 类继承 (Class_Inheritance)

在研究类继承之前，先明确一下一个类访问成员的三大权限，如下表格所示：

|访问权限|描述|
|-------|----|
|Public |成员可以被任何外部代码访问|
|Protected|介于 公有/私有之间，可以被派生类访问，但不能被外部访问|
|Privite|成员只能被类自己访问|

当然，派生类访问基类也是有权限的，如下表格所示（Base 基类  Derives 派生类）：

|代码示例|权限|描述|
|-------|----|----|
|class Derives : public Base|公有继承|基类中的 Public 和 Protected 访问权限的成员在派生类中的<br>访问权限不变，依旧是 Public 和 Protected|
|class Derives : protecte Base|受保护的继承|基类中的 Public 访问权限的成员在派生类中变为 Protected|
|class Derives : protecte Base|私有继承|基类中的 Public 和 Protected 访问权限的成员在派生类中的<br>访问权限都变为 Privite|

### 设计一个简单的父子类

```C++
/*
    Pontoon 银行要求我开发两个类：
        1）Brass_Account类 用于表示基本支票账户
            账户信息：
            1.客户姓名
            2.账号
            3.当前的余额

            可执行的操作：
            1.创建账户
            2.存款
            3.取款
            4.显示账户信息

        2）Brass_Plus类，继承自 Brass_Account类 用于 Plus 用户的支票账户，提供 <透支保护特性>
            账户信息：
            1.透支上限
            2.透支贷款利率
            3.当前透支总额

            可执行的操作（无需新增操作，但有两种操作的实现不同）：
            1.对于取款操作，必须考虑透支保护
            2.显示操作必须显示 Brass_Plus类的其他信息
            
        透支保护特性:
        1.若用户签出一张超过他存款的支票，但超出的数额不是很大（默认 $500 以内，有些客户限额不同），
        银行将支付这张支票，但对超出的部分收取额外的费用（利率默认是 11.125%，有些客户利率不同），并追加罚款。

        2.银行可以修改客户的利率和透支限额

        3.账户记录客户所欠的金额（透支数额 + 利息），用户不得通过常规存款或从其他账户转帐的方式偿付，
        必须用现金交给银行的工作人员，如有必要，之间上门催债，还清欠款后，欠款金额归零。
*/
/*类声明如下：*/

class Brass_Account
{
    private:
        string full_name;       /*客户姓名*/
        string account_no;      /*客户账号*/
        double balence;         /*余额*/

    public:
        /*初始化用户信息*/
        Brass_Account(const string & fn  = "Null_Body", const string acc = "Null_NO", double bal = 0.0000);

        /*存钱*/
        void Deposit(double amt);

        /*返回余额*/
        const double Balence() const;

        /*取钱*/
        virtual void With_Draw(double amt);
        /*显示账户信息*/
        virtual void View_Account() const;
        virtual ~Brass_Account() {};
};

class Brass_Plus : public Brass_Account
{
    private:
        double max_loan;    /*最大透支额度*/
        double rate;        /*透支贷款利率*/
        double owns_bank;   /*当前透支额度*/

    public:
        /*初始化用户信息，欠款额度，利率等数据*/
        Brass_Plus(const string & fn = "Null_Body", const string acc = "Null_NO", 
                    double bal = 0.0000, double ml = 500.00, double rate = 0.11125);
        Brass_Plus(const Brass_Account & ba, double ml = 500.00, double rate = 0.11125);

        /*重设最大透支额度*/
        void Reset_Max(double m) { max_loan = m; }

        /*重设透支贷款利率*/
        void Reset_Rate(double r) { rate = r; }

        /*重设欠款*/
        void Rest_Owes() { owns_bank = 0; }
        
        /*取钱*/
        virtual void With_Draw(double amt);

        /*显示账户信息*/
        virtual void View_Account() const;

        virtual ~Brass_Plus() { }       
};
```

类成员方法的实现和测试用例见 `Class_Inherit/Brass_Account/` 路径

--------------------------------------------------------------------------------------------------------------------------------------------

Latest update: 2024.05.07

--------------------------------------------------------------------------------------------------------------------------------------------
Licence

[MIT LICENCE](https://opensource.org/license/mit/)
