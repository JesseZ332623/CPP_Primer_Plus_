#include "./include/_queue.h"

_Queue::_Queue(int size) : max_size(size) 
{
    front = rear = nullptr;
    items = 0;
}

bool _Queue::isempty() const
{
    return items == 0;
}

bool _Queue::isfull() const
{
    return items == max_size;
}

/*入队操作*/
bool _Queue::enqueue(const Item & item)
{
    if (isfull())       /*判断队列是否以满*/
    {
        return false;
    }

    /*创建一个新的节点，并返回地址给 add*/
    Node *add = new Node;

    /*初始化 add 所指向的节点*/
    add->item = item;
    add->next = nullptr;

    ++items;    /*节点数量 +1*/

    /*判断队列头指针是否指向 空指针*/
    if (front == nullptr)
    {
        front = add;    /*如果是，这个新创建的节点就是队列头*/
    } 
    else 
    {
        rear->next = add;   /*如果不是，就给他塞到队尾去*/
    }

    rear = add; /*将新创建的节点插入队尾*/
    
    return false;
}

bool _Queue::dequeue(Item & item)
{
    if (isempty())      /*判断是否为空节点*/
    {
        return false;
    }

    /*将 头节点数据拷贝给用户传入的引用 item*/
    item = front->item;

    /*新建一个节点 temp，把当前头节点赋值给它*/
    Node *temp = front;

    /*头节点向后偏移一节点*/
    front = front->next;

    /*删除原头节点*/
    delete temp;

    /*删除节点后判断队列是否为空*/
    if (items == 0)
    {
        rear = nullptr;     /*如果是的话，尾节点就指向空*/
    }

    return true;
}

/*返回当前队列节点的数量*/
int _Queue::node_count() const
{
    return items;
}

/*析构函数用于删除整个队列的数据*/
_Queue::~_Queue()
{
    Node *temp;

    while (front != nullptr)
    {
        temp = front;
        front = front->next;
        delete temp;
    } 
}