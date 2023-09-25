/*cow.cpp 实现 Cow 类的方法*/

#include "./cow.h"

Cow::Cow()
{
    std::strcpy(name, "Defualt string....");
    hobby = new char[1];
    hobby[0] = '_';
    hobby[1] = '\0';

    weight = 0.0000;
}

Cow::Cow(const char * nm, const char *ho, double wt)
{
    std::strcpy(name, nm);

    hobby = new char[std::strlen(ho)];
    std::strcpy(hobby, ho);

    weight = wt;
}

Cow::Cow(const Cow & c)
{
    std::strcpy(name, c.name);

    hobby = new char[std::strlen(c.hobby)];
    std::strcpy(hobby, c.hobby);

    weight = c.weight;
}

Cow & Cow::operator=(const Cow & c)
{
    if (this == &c)     /*要防止自我赋值*/
    {
        return *this;
    }

    delete hobby;       /*删除堆空间元素*/

    /*进行深拷贝*/
    std::strcpy(name, c.name);

    hobby = new char[std::strlen(c.hobby)];
    std::strcpy(hobby, c.hobby);

    weight = c.weight;


    return *this;   /*返回调用这个方法的对象的地址*/
}

void Cow::Show_Cow() const
{
    using std::cout;

    cout << "Name: " << name << '\n';
    cout << "Hobby: " << hobby << '\n';
    
    std::cout << std::fixed << std::setprecision(2);
    cout << "Weight: " << weight << "Kg" << '\n';
}

Cow::~Cow()
{
    delete[] hobby;
}