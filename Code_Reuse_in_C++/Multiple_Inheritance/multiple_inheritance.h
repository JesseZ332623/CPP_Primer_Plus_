#ifndef _MULTIPLE_INHERITANCE_H_
#define _MULTIPLE_INHERITANCE_H_

/**
 * 本小节学习多重继承，首先做一些基本工作：
 * 定义一个抽象基类 Worker
 * 公共派生出 Waiter 类 和 Singer 类
*/

/**
 * 但是若我们想创建一个新类 SingingWaiter，公共继承自 Waiter 和 Singer，就会发生 “菱形继承” 问题。
 * 由于 Waiter 和 Singer 类中都有其基类 Worker 的副本，因此 SingingWaiter 类将包含两个 Worker 组件，
 * 如果将 SingingWaiter 类对象的地址赋值给 基类 Worker 的指针，这会出现二义性。
 * 
 *      SingingWaiter ed;
 *      Worker *pv = &ed;   二义性，不知道该调用哪个基类
 * 
 * 为了解决此问题，需要引入一个新的特性，虚基类 (virtual basic class)，
 * 它使得从多个类派生出的对象只继承一个基类对象，
 * 此时 Waiter类 和 Singer类 的声明应该如下 (virtual 和 public 关键字的声明顺序无关紧要)：
 *      
 *      class Waiter : virtual public Worker { ... };
 *      class Singer : virtual public Worker { ... };
 * 
 * 此时，子类 Waiter 和 Singer 共享一个 Worker 基类，而不是引入各自的 Woker 对象副本。
 * 而 SingingWaiter 对象 也只包含了一个 Worker 对象，因此可以使用多态，SingingWaiter 的声明如下
 * 
 *      class SingingWaiter : public Waiter, public Singer { ... };
 * 
 * 这样就解决了有多少个 Worker 的问题。
*/

/**
 * 修改了类构造函数的规则后，多重继承还得考虑到类方法的继承问题。
 * 假设要在 SingingWaiter 中重写 show() 方法，并试图使用 SingWaiter 对象调用继承的 show() 方法
 * 
 *       SingingWaiter new_waiter("Elise Hawks", 2005, 6 , soprano);
 *       new_waiter.show();     二义性，不知道该调用哪个父类的 show 方法
 * 
 * 要解决这个问题，需要使用模块化的方式，
 * 即提供三个只显示 Worker 组件，Waiter 组件 和 Singer 组件的方法，可以这么做：
 *       class Worker
 *       {
 *            ....
 *            protected:
 *                  virtual void data() const;
 *                  virtual void get();
 *            ....
 *       };
 * 
 *       class Waiter : virtual public Worker
 *       {
 *           ....
 *            protected:
 *                  void data() const;
 *                  void get();
 *            ....
 *       }; 
 * 
 *       class Singer : virtual public Worker
 *       {
 *            ....
 *            protected:
 *                  void data() const;
 *                  void get();
 *            ....  
 *       };
 * 
 *       class SingingWaiter : public Waiter, public Singer
 *       {
 *              ....
 *            protected:
 *                  void data() const;
 *                  void get();
 *            ....                
 *       };
 * 
 * 采用这种方式，对象仍然能使用 show() 方法，
 * 而 data() 方法只能在内部可用，作为协助公有接口的辅助方法。
 * 
 * 由此就解决了 “哪个方法” 的问题。
*/

#include <string>

/*定义一个抽象基类 Worker*/
class Worker
{
    private:
        /*工人全名*/
        std::string full_name;

        /*工人 ID*/
        long int ID;

    protected:
        virtual void data() const;
        virtual void get();
    
    public:
        Worker() : full_name("No One"), ID(0L) {}
        Worker(const std::string & _f_name, const long int _ID) : full_name(_f_name), ID(_ID) {}

        virtual void show() const = 0;
        virtual void set() = 0 ;

        /*纯虚析构函数*/
        virtual ~Worker() = 0;
};

/*公共派生出 Waiter 类*/
class Waiter : virtual public Worker
{
    private:
        /*服务员派头等级*/
        int panache;

    protected:
        void data() const;
        void get();

    public:
        Waiter() : Worker(), panache(0) {}
        Waiter(std::string _f_name, long int _ID, int _pana = 0) : Worker(_f_name, _ID), panache(_pana) {}
        Waiter(const Worker & _w, int _pana) : Worker(_w), panache(_pana) {}

        void set();
        void show() const;
};

/*公共派生出 Singer 类*/
class Singer : virtual public Worker
{
    protected:
        enum {other, alto, contralto, soprano, bass, baritone, tenor};
        enum {V_types = 7};
        void data() const;
        void get();

    private:
        static std::string pv[V_types];
        int voice;

    public:
        Singer() : Worker(), voice(other) {}
        Singer(std::string _f_name, long int _ID, int _voice = other) : Worker(_f_name, _ID), voice(_voice) {}
        Singer(const Worker & _worker, int _voice = other) : Worker(_worker), voice(_voice) {}

        void set();
        void show() const;       
};

/*多重继承类 SingingWaiter*/
class SingingWaiter : public Waiter, public Singer
{
    protected:
        void data() const;
        void get();

    public:
        SingingWaiter() {}

        SingingWaiter(const std::string & _f_name, long int _ID, int _pana = 0, int _voice = other)
                    : Worker(_f_name, _ID), Waiter(_f_name, _ID, _pana), Singer(_f_name, _ID, _voice) {}

        SingingWaiter(const Worker & _w, int _pana = 0, int _voice = other) 
                    : Worker(_w), Waiter(_w, _pana){}

        SingingWaiter(const Waiter & _waiter, int _voice = other) : Worker(_waiter), Waiter(_waiter), Singer(_waiter, _voice) {}

        SingingWaiter(const Singer & _singer, int _pana = 0) : Worker(_singer), Waiter(_singer, _pana), Singer(_singer) {}
                    

        void set();
        void show() const;

};

#endif