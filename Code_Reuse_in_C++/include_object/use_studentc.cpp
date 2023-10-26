#include "studentc.h"

using std::cout, std::cin, std::endl;

/*学生数量*/
const int PUPILS = 3;

/*课程数量*/
const int QUIZZES = 5;

void Set(Student & _stu, int n);

void Set(Student & _stu, int n)
{
    /*输入学生姓名*/
    cout << "Please enter the student's name: ";
    getline(cin, _stu);

    /*循环输入学生的成绩*/
    cout << "Please enter " << n << " quiz scores:\n";

    for (int index = 0; index < n; ++index)
    {
        cin >> _stu[index];
    }
    /*使用 循环去除 换行符*/
    while (cin.get() != '\n') { continue; }
}

int main(int argc, char const *argv[])
{
#if true
    /*声明一个对象数组 ada*/
    Student ada[PUPILS] = 
    {
        Student(QUIZZES), Student(QUIZZES), Student(QUIZZES)
    };

    int index = 0;

    /*循环输入学生信息*/
    for (index = 0; index < PUPILS; ++index)
    {
        Set(ada[index], QUIZZES);
    }

    /*输出结果*/
    cout << "\nResults: ";
    for (index = 0; index < PUPILS; ++index)
    {
        cout  << endl << ada[index];
        cout << "Average: " << ada[index].Average() << endl;
    }

#endif

    return EXIT_SUCCESS;
}