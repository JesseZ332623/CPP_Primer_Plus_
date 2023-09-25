#include "./cow.h"

#define LINE "---------------------------------\n"

int main(int argc, char const *argv[])
{
    using std::cout;

    Cow cow_1;  /*使用默认构造函数*/
    Cow cow_2("New Cow...", "produce milk", 125.76);
    Cow cow_3(cow_2);

    /*等价于 Cow cow_4 = cow_3.operator=(cow_3);*/
    Cow cow_4 = cow_3;  

    cout << LINE;
    cout << "Cow_1 info: " << '\n';
    cow_1.Show_Cow();

    cout << LINE;
    cout << "Cow_2 info: " << '\n';
    cow_2.Show_Cow();

    cout << LINE;
    cout << "Cow_3 info: " << '\n';
    cow_3.Show_Cow();

    cout << LINE;
    cout << "Cow_4 info: " << '\n';
    cow_4.Show_Cow();

    return EXIT_SUCCESS;
}
