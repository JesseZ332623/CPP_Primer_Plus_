#include <iostream>
#include <string>

typedef struct employee_job
{
    char name[40];
    double salary;
    int floor;

} Job;

typedef class Data_Class
{
    public:
        std::string name;
    
        Data_Class(std::string name);

        void show();

        ~Data_Class();
} Data;

Data_Class::Data_Class(std::string name)
{
    this->name = name;
}

void Data_Class::show()
{
    std::cout << "name: " << name << std::endl;
}

Data_Class::~Data_Class()
{
    std::cout << "destory classs.....\n";
}

/*能显示基本数据类型的函数模板*/
template <typename Any_Type>
void show_data(Any_Type &data);

/*交换两个数据的函数模板*/
template <typename Type>
void Swap(Type &a, Type &b);

/*交换两个数据的函数模板的第一个重载*/
/*
    template<> - 表示这是一个对模板函数的特化版本。
    void Swap<Job>(Job &job_1, Job &job_2) - 函数名为Swap,参数为两个Job类型的引用。
    特化的类型是Job。
    没有函数体,只是一个声明。
    这段代码意味着:对于Swap这个模板函数,对于Job类型,有一个专门的特化版本,它的参数和返回值与泛型版本相同,但是函数实现(定义)与泛型版本不同。
    在其他地方需要对Job类型专门实现Swap函数。
    调用时,如果传递的是Job类型,会自动调用这个特化版本,而不是泛型版本。
    这样可以对某些特定类型的swap行为进行自定义优化。
    所以这段代码的作用就是声明一个Swap模板的特化版本,用于交换Job类型的两个对象。
*/
template <>
void Swap<Job>(Job &job_1, Job &job_2);
void Show(Job &j);

/*根据上面的类推，可以设计出交换两个Class的函数*/
template <> 
void Swap<Data>(Data &name_1, Data &name_2);

template <typename Any_Type>
void show_data(Any_Type &data)
{
    std::cout << data << std::endl;
}

template <typename Type>
void Swap(Type &a, Type &b)
{
    Type temp;
    temp = a;
    a = b;
    b = temp;
}

template <>
void Swap<Job>(Job &job_1, Job &job_2)
{
    double temp_salary = 0.00F;
    int temp_floor = 0;

    temp_salary = job_1.salary;
    temp_floor = job_1.floor;

    job_1.salary = job_2.salary;
    job_1.floor = job_2.floor;

    job_2.salary = temp_salary;
    job_2.floor = temp_floor;
}

template <> 
void Swap<Data>(Data &name_1, Data &name_2)
{
    std::string temp_str = name_1.name;
    name_1.name = name_2.name;
    name_2.name = temp_str;
}

void Show(Job &j)
{
    using namespace std;

    cout << j.name << ": $" << j.salary << " on floor " << j.floor << endl;
}

int main(void)
{
    Data *name_1 = new Data("Jesse");
    Data *name_2 = new Data("Faker");

    std::cout << "Before Swap" << std::endl;
    name_1->show();
    name_2->show();

    Swap(*name_1, *name_2);
   
    std::cout << "After Swap" << std::endl;
    name_1->show();
    name_2->show();
    
    delete name_1;
    delete name_2;
    return EXIT_SUCCESS;
}
