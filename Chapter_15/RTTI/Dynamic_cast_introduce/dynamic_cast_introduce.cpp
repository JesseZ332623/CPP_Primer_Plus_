#include <iostream>

/*
    dynamic_cast<> 运算符是 RTTI 中最常用的组件，
    它不能回答 “指针指向的是哪种类型的对象”，但可以回答 “能否可以安全的将对象的地址赋给特定类型的指针” 这样的问题。

    需要注意的是：dynamic_cast<> 运算符只适用于包含虚函数的类
*/

#define DERIVED_TO_BASIC true
#define BASIC_TO_DERIVED false

class Grand 
{ 
    public:
        Grand() { printf("Create Grand object.\n"); }
        virtual ~Grand() { printf("Destruct Grand object.\n"); } 
};

class Superb : public Grand 
{ 
    public:
        Superb() { printf("Create Superb object.\n"); }
        virtual ~Superb() override { printf("Destruct Superb object.\n"); }
};

class Magnificient : public Superb
{
    public:
        Magnificient() { printf("Cteate Magnificient object.\n"); }
        virtual ~Magnificient() override { printf("Destruct Magnificient object.\n"); }
};

int main(int argc, char const *argv[])
{
    // 创建 Grand 类对象，返回 (Grand *) 类型的指针给 （Grand *） 类型的指针变量 pg
    Grand * pg = new Grand;
    
    // 创建 Superb 类对象（调用 Grand 和 Superb 类的构造函数），返回（Superb *）类型的指针给（Grand *） 类型的指针变量 ps（存在指针的隐式转换 子 -> 父）
    Grand * ps = new Superb;
    
    // 创建 Magnificient 类对象（调用 Grand Superb 和 Magnificient 类的构造函数），返回 （Magnificient *）类型的指针给 Grand *） 类型的指针变量 pm（存在指针的隐式转换 孙 -> 父）
    Grand * pm = new Magnificient;

    /*
        类型转换 #1 是安全的，将（Grand *）类型的指针（指向了 Magnificient 类型的数据） pm 转化为 (Magnificient *) 类型赋值给（Magnificient *）类型的 ptrA

        类型转换 #2 是不安全的，将（Grand *）类型的指针（指向了 Grand 类型的数据）pg 转化为 (Magnificient *) 类型赋值给（Magnificient *）类型的 ptrB，
        这存在不安全的类型转换（父 -> 子）。因此，程序将期望基类对象有派生类的特征，而这通常是不可能的（孙类 Magnificient 内可能有祖类 Grand 没有的数据成员）。

        类型转换 #3 是安全的，将（Grand *）类型的指针（指向了 Magnificient 类型的数据） pm 转化为 (Magnificient *) 类型赋值给（Superb *）类型的 ptrC，
        即将派生对象的地址赋值给基类指针。共有派生（public）确保 Magnificient 类对象同时也是一个 Superb 类对象（直接基类）和 Grand 对象（间接基类）。
    */
    Magnificient * ptrA = (Magnificient *)pm; // #1
    Magnificient * ptrB = (Magnificient *)pg; // #2
    Superb * ptrC = (Magnificient *)pm;       // #3

    std::cout << "Address ptrA = " << ptrA
              << "\tAddress ptrB = " << ptrB
              << "\tAddress ptrC = " << ptrC << '\n';


    /*
        与问题  “指针指向的是哪种类型的对象” 相比，问题 “类型转换是否安全” 更通用，也更有用。

        通常想知道类型的原因在于：知道类型后，就可以知道调用的方法是否安全。要调用方法，类型并不一定要完全匹配，
        而可以是定义了方法的虚拟版本的基本类型。
    */

   /*
        此处演示了 dynamic_cast<Type *>(pt) 运算符的用法，需要注意的是：

            若指向的对象（Type *）的类型为 Type 或者是从 Type 直接或间接派生下来的类型，
            则下面的表达式将指针 pt 转为 Type 类型的指针。

            若不满足上述条件，比如将两个毫不相干的类型进行转换，
            或者出现 父 -> 子 / 孙 的情况就会返回 nullptr  
   */
#if BASIC_TO_DERIVED        // 父 -> 子 / 孙（不允许）
    Superb * __pm = dynamic_cast<Superb *>(pg);
#endif

#if DERIVED_TO_BASIC        // 子 -> 父 / 祖（允许）
    Grand * __pm = dynamic_cast<Grand *>(pm);
#endif

    if (__pm == nullptr) { std::cerr << "Coversion failed! (Grand * -> Superb *)\n"; }
    else 
    { 
        std::cout << "Conversion success! address of __pm = " << __pm << '\n';
    }
   
    delete pg;
    delete ps;
    delete pm;

    ptrA = nullptr;
    ptrB = nullptr;
    ptrC = nullptr;
    
    return EXIT_SUCCESS;
}
