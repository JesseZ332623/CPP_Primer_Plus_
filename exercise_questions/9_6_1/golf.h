#ifndef _GOLF_H_
#define _GOLF_H_

#include "_defs_.h"

const int NAME_LEN = 40;

struct golf
{
    char fullname[NAME_LEN];
    int handicap;
};

/*一个设置 golf 结构体数据的函数 setgolf*/
void set_golf(golf & golf, const char *name, int handicap);

/*
    setgolf 函数的第一个重载 
    只传入 golf 结构体的引用，
    通过 cin 和 cout 来提示用户输入相关数据
*/
void set_golf(golf & golf, int index);

/*修改 golf 结构体内 handicap 的数据*/
void handicap(golf & golf, int hc);

/*展示 golf 结构体的数据*/
void show_golf(const golf & golf, int index);

#endif