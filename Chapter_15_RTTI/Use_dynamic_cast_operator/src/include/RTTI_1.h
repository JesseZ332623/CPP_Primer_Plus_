#ifndef _RTTI_1_H_
#define _RTTI_1_H_

#include <iostream>
#include <stdlib.h>
#include <ctime>

using std::cout;

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
 * @return 将创建的对象全部都转换为（Grand *）类型后返回（子 -> 父）
*/
Grand * getOne();

#endif // _RTTI_1_H_