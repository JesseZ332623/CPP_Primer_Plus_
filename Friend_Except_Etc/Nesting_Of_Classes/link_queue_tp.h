#ifndef _LINK_QUEUE_TP_H_
#define _LINK_QUEUE_TP_H_

/**
 * 使用模板类和嵌套类实现一个链队列的 Container
 * 
 * 往常定义一个顺序队列都会在内部写一个结构体或者单单一个变量，
 * 但这次链式队列的实现需要考虑嵌套类的使用，队列节点 class Node 的声明如下：
 * 
 * template <typename Item>
 * class Link_Queue
 * {
 * privite:
 * ...
 *      class Node
 *      {
 *          public:
 *              Item item;
 *              Node * next;
 *              
 *              Node(const Item & _item) : item(_item), next(nullptr) {}
 *      };
 * ...
 * 
 * public:
 * .... 
 * };
 * 
 * 可以看到，声明在类私有部分的嵌套类，枚举，结构体这样的复合类型在类外部不可以使用，
 * 因为 Node 类是 Link_Queue 类内部实现的一项特性，对于外部是不可见的。
*/

typedef unsigned long long int size_t;

/*链式队列*/
template <typename Item>
class Link_Queue
{
    private:
        enum { QUEUE_SIZE = 15 }; /*默认队列长度为 15 个节点*/

        /*节点类的实现，由于声明在私有部分，因此只有 Link_Queue 才可以访问它*/
        class Node
        {
           public:
               Item item;       /*节点数据*/
               Node * next;     /*指向下一个节点的指针*/
               
               /*Node 类的构造函数*/
               Node(const Item & _item) : item(_item), next(nullptr) {}
        };

        Node * front;   /*指向第一个节点的指针*/
        Node * rear;    /*指向最后一个节点的指针*/

        const size_t max_item;      /*队列的最大节点数*/
        size_t items;               /*当前队列的节点数*/

        /*拷贝构建函数*/
        Link_Queue(const Link_Queue & _link_queue) : max_item(0) {}

        /*重载 = 的拷贝函数*/
        Link_Queue & operator=(const Link_Queue & _link_queue) { return *this; }

    public:
        /*构建函数，传入队列的大小*/
        Link_Queue(size_t _m_size = QUEUE_SIZE);

        /*检查队列是否为空*/
        bool isempty() { return items == 0; }

        /*检查队列是否以满*/
        bool isfull() { return items == max_item; }

        /*返回当前队列节点数*/
        size_t count() const { return items; }

        /*从队列末尾插入节点*/
        bool enqueue(const Item & _item);

        /*从前面删除节点*/
        bool dequeue(Item & _item);

#if false

        friend std::ostream & operator<<(std::ostream & _os, Link_Queue & _q)
        {
            Link_Queue<Item>::Node * _temp;

            while (_q.front != nullptr)
            {
                _temp = _q.front;

                _os << _temp->item << '\t';

                _q.front = _q.front->next;
            }

            return _os;
        }

#endif
        
        /*析构函数，销毁每一个队列节点*/
        ~Link_Queue();
};



template <typename Item>
Link_Queue<Item>::Link_Queue(size_t _m_size) : max_item(_m_size)
{
    front = rear = nullptr;
    items = 0;
}

template <typename Item>
bool Link_Queue<Item>::enqueue(const Item & _item)
{
    /*如果队列已满则插入失败*/
    if (isfull()) { return false; }

    /*创建新节点*/
    Node *new_node = new Node(_item);
    
    /*
        若是空队列，则之间将 front 和 rear 指针指向新创建的节点即可。
        此时队列长这样：

        front -> new_node <- rear
    */
    if (front == nullptr) { front = new_node; }

    /*
        如果不是空队列，则将指针 rear 的下一个节点 (rear->next) 指向新创建的节点
        此时队列长这样：

        *front -> node -> node -> ... -> node(original *rear) -> *(rear->next)new_node(current *rear)
    */
    else { rear->next = new_node; }
    
    rear = new_node;

    /*节点数 + 1*/
    items++;

    return true;
}

template<typename Item>
bool Link_Queue<Item>::dequeue(Item & _item)
{
    /*如果是空队列，则删除失败*/
    if (front == nullptr) { return false; }

    /*先保存要删除节点的值*/
    _item = front->item;

    /*创建中间节点保存要删除节点的值*/
    Node *temp = front;

    /*指向下一个节点*/
    front = front->next;

    /*删除节点*/
    delete temp;

    /*节点数 - 1*/
    items--;

    if (isempty()) { rear = nullptr; }

    return true;
}

template <typename Item>
Link_Queue<Item>::~Link_Queue()
{
    Node *temp;

    while (front != nullptr)
    {
        temp = front;        /*保存上一个节点的地址*/
        front = front->next; /*指向下一个节点*/
        delete temp;         /*删除上一个节点*/
    }
}
#endif
