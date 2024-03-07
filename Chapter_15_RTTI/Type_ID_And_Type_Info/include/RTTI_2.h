#ifndef _RTTI_1_H_
#define _RTTI_1_H_

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <iomanip>

/*为 typeid 运算符的功能实现以及 bad_typeid 异常类所在*/
#include <typeinfo>

using std::cout, std::cerr;

class Grand
{
    private:
        int hold;

    public:
        Grand(int __hold = 0) : hold(__hold) {}

        virtual void Speak() const { cout << "I am a Grand Calass.\n"; }
        virtual int getHold() const { return hold; }

        virtual ~Grand() {}
};

class Superb : public Grand
{
    public:
        Superb(int __hold = 0) : Grand(__hold) {}

        virtual void Speak() const override { cout << "I am a Superb Calass.\n"; }
        virtual void Say() const 
        {
            cout << "I hold the super value of " << getHold() << "!\n";
        }
};

class Magnificent : public Superb
{
    private:
        char ch;

    public:
        Magnificent(int __hold = 0, char __ch = 'A') : Superb(__hold), ch(__ch) {}

        void Speek() const { cout << "I am a Magnificent Calass.\n"; }
        void Say() const
        {
            cout << "I hold the super value of " << getHold() << " and hold a character: " << ch << " !\n";
        }
};

/**
 * @brief 通过随机数模拟用户选择创建哪一种类型的对象
 * 
 * @return 将创建的对象全部都转换为（Grand *）类型后返回（子 / 孙 -> 父）
*/
Grand * getOne();

Grand * getOne()
{
    Grand * ptr = nullptr;

    switch (std::rand() % 3)
    {
        case 0:
            ptr = new Grand(std::rand() % 100);
            break;

        case 1:
            ptr = new Superb(std::rand() % 100);
            break;

        case 2:
            ptr = new Magnificent(std::rand() % 100, 'A' + std::rand() % 26);
            break;

        default:
            break;
    }

    return ptr;
}

typedef struct __TypeInfo
{
    private:
        std::string typeName;
        std::size_t typeHashCode;

    public:
        __TypeInfo(void) : typeName("Emplty"), typeHashCode(0) {}

        __TypeInfo(std::string __tpName, std::size_t __hashCode) : typeHashCode(__hashCode)
        {
            for (const char __ch : __tpName)
            {
                if (isdigit(__ch)) { continue; }

                this->typeName.push_back(__ch);
            }
        }

        friend std::ostream & operator << (std::ostream & __os, __TypeInfo & __typeInfo)
        {
            __os << std::right << "Type = [" << __typeInfo.typeName << "]\n" << std::setw(26)
                 << "HashCode = {" << __typeInfo.typeHashCode << "}";

            return __os;
        }

} TypeInfo;

#endif // _RTTI_1_H_