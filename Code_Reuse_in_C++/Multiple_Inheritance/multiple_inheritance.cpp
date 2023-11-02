#include "./multiple_inheritance.h"
#include <iostream>

using std::cout, std::cin, std::endl;

/*
    must implement virtual destructor,even if pure.
    必须实现虚拟析构函数，即使是纯析构函数。
*/
Worker::~Worker() {}

void Worker::data() const
{
    cout << "Name: " << full_name << endl;
    cout << "Employee ID: " << ID << endl;
}

void Worker::get()
{
    getline(cin, full_name);
    cout << "Enter worker's ID: ";
    cin >> ID;

    while (cin.get() != '\n') { continue; }
}

#if false
void Worker::set()
{
    cout << "Enter worker's name: ";
    std::getline(cin, full_name);

    cout << "Enter worker ID: ";
    cin >> ID;

    while (cin.get() != '\n') { continue; }
}

void Worker::show() const
{
    cout << "Name: " << full_name << endl;
    cout << "ID: " << ID << endl;
}
#endif

void Waiter::set()
{
    cout << "Enter waiter's name: ";
    Worker::get();
    get();
}

void Waiter::show() const
{
    cout << "Category: Waiter " << endl;
    Worker::data();

    data();
}

void Waiter::data() const
{
    cout << "Waiter Panache Rating: " << panache << endl;
}

void Waiter::get()
{
    cout << "Enter waiter's panache rating: ";
    cin >> panache;

    while (cin.get() != '\n') { continue; }
}

std::string Singer::pv[] = {"other", "alto", "contralto", "soprano", "bass", "baritone", "tenor"};

void Singer::set()
{
    cout << "Enter singer's name: ";
    Worker::get();
    get();
}

void Singer::show() const
{
    cout << "Category: Singer " << endl;
    Worker::data();
    data();
}

void Singer::data() const
{
    cout << "Vocal range: " << pv[voice] << endl;
}

void Singer::get()
{
    cout << "Enter number of singer's vocal range: \n";
    int index = 0;

    for (index; index < V_types; ++index)
    {
        cout << index << ": " << pv[index] << " ";
        if (index % 4 == 3) { cout << endl; }
    }
    if (index % 4 != 0) { cout << endl; }

    cin >> voice;

    while (cin.get() != '\n') { continue; }
}

void SingingWaiter::data() const
{
    Singer::data();
    Waiter::data();
}

void SingingWaiter::get()
{
    Waiter::get();
    Singer::get();
}

void SingingWaiter::set()
{
    cout << "Enter singing waiter's name: ";
    Worker::get();
    get();
}

void SingingWaiter::show() const
{
    cout << "Catagory: singing waiter" << endl;
    Worker::data();
    data();
}