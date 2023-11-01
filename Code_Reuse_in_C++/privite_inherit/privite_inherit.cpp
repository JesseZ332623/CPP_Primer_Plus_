/**
 * @author JesseZ332623 @date 2023.10.24         
 * @file studentc.h 
 * @JesseZ332623
 * 
 * 设计一个 student 类，主要是学习包含成员对象类的使用。
*/
/*
    和包含对象成员的类不同，私有继承的类在初始化列表上不能使用对象名，而应该使用类名去初始化，例如
    Student () : std::string("Null Body"), Array_DB() {}
*/

#ifndef _STUDENTC_H_
#define _STUDENTC_H_

#include <iostream>
#include <string>

/*
    valarray 是一个模板类，用于处理数值，或有类似数值特性的数据非常好用。
    本项目会使用这个类提供的 5 个 方法：

    1）operator[]() 可以访问类数据的各各元素
    2）size()       返回包含的元素个数
    3）sum()        返回所有元素的和
    4）max          返回最大值
    5）min          返回最小值

    valarray 模板类的几个构建函数用法如下：

    1）valarray<type> _arr;          创建一个空数组
    2）valarray<type> _arr(8);       创建一个类型为 type，且有 8 个元素的数组
    3）valarray<type> _arr(10, 8);   创建一个类型为 type，且有 8 个元素的数组，每个元素都设为 10
    4）valarray<type> _arr(_dat, 8); 创建一个类型为 type，且有 8 个元素的数组,并将数组 _dat 的前 8 个数据拷贝
*/
#include <valarray>

class Student : private std::string, private std::valarray<double>
{
    private:
        /*将 std::valarray<double> 类定义一个别名 Array_DB*/
        typedef std::valarray<double> Array_DB;

        /*可以使用 using 定义访问权限*/
        using std::valarray<double>::sum;
        using std::valarray<double>::size;

        /*输出成绩数组*/
        std::ostream & array_output(std::ostream & _os) const;

    public:
        Student() : std::string("Null Student"), Array_DB() {}

        /**
         * 使用 explicit 关键字，可以避免隐式转换而出现不必要的错误。
         * 举个例子：假设创建了这么一个类
         * 
         *          Student doh("Homer", 10);
         * 
         * 而有个粗心的程序员编写了这么一条语句：
         * 
         *          doh = 5;
         * 
         * 在没有 explicit 关闭隐式转换的情况下，这条语句就将 (int)5 转换成一个临时的 Student 类并调用了如下构建函数：
         * 
         *          doh = Student(5);
         * 
         * 这将重设 doh 对象的数据，name 会被设为 "Null Student" 而 score 会被设为一个空数组，
         * 这对程序来说是毁灭性的。。。。。    
        */
        explicit Student(const std::string & _str) : std::string(_str), Array_DB() {}
        explicit Student(int n) : std::string("Null Student"), Array_DB(n) {}

        Student(const std::string & _str, int n) : std::string(_str), Array_DB(n) {}
        Student(const std::string & _str, const Array_DB & _arr) : std::string(_str), Array_DB(_arr) {}
        Student(const char *_str, const double *_arr, int n) : std::string(_str), Array_DB(_arr, n) {}

        double Average() const;
        const std::string Name() const;

        double & operator[](int _index);
        double operator[](int _index) const;

        friend std::istream & operator>>(std::istream & _is, Student & _stu);
        friend std::istream & getline(std::istream & _is, Student & _stu);
        friend std::ostream & operator<<(std::ostream & _os, Student & _stu);

        ~Student() {}
};

#endif

double Student::Average() const
{
    return sum() / size();
}

std::ostream & operator<<(std::ostream & _os, Student & _stu)
{
    /*
        和包含对象成员的类不同，
        私有继承的类需要将类显式的转换成相应的数据结构，才能正常工作。
    */
    _os << (const std::string &)_stu << std::endl;

    return _os;
}

