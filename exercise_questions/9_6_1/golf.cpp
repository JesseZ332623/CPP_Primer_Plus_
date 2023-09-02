#include "golf.h"

/*一个设置 golf 结构体数据的函数 setgolf*/
void set_golf(golf & golf, const char *name, int handicap)
{
    strcpy(golf.fullname, name);
    golf.handicap = handicap;
}

/*
    setgolf 函数的第一个重载 
    只传入 golf 结构体的引用，
    通过 cin 和 cout 来提示用户输入相关数据
*/
void set_golf(golf & golf, int index)
{
    using namespace std;
    cout << '(' << index + 1 << ')' << " Enter the name: ";
    cin >> golf.fullname;
    //cout.put('\n');

    cout << "Enter the handicap: ";
    cin >> golf.handicap;
    cout.put('\n');

}

/*修改 golf 结构体内 handicap 的数据*/
void handicap(golf & golf, int hc)
{
    golf.handicap = hc;
}

/*展示 golf 结构体的数据*/
void show_golf(const golf & golf, int index)
{
    using std::cout, std::endl;

    cout << "The golf contence: " << endl;

    cout << '(' << index + 1 << ')' << ' ';
    cout << "Name: " << golf.fullname << endl;
    cout << "Handicap: " << golf.handicap << endl;
}