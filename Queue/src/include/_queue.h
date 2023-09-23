/**
 * queue.h
 * @author Jesse_EC
 * @date 2023.09.23
*/

/*
    target：设计一个 _Queue 类，要求实现一些队列的基本操作，如下：
    1）判断队列是否为空     bool isempty() const;
    2）判断队列是否为满     bool isfull() const;
    3）入队                bool enqueue(const Item & item);
    4）出队                bool dequeue(Item & item);
    5）输出目前队列的节点数 int node_count() const;

    此外，为了满足两个对象相互复制，以及在没有内存泄漏的情况下删除整个队列，
    _Queue 类的构建函数，析构函数，以及运算符重载函数如下：

    private:
    _Queue(const _Queue & q) : max_size(0);
    _Queue & operator=(const Queue & q) { return *this; }

    public:
    _Queue(int size = MAX_SIZE);
    ~_Queue();
*/

#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "./customer.h"

typedef Customer Item;

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

#endif