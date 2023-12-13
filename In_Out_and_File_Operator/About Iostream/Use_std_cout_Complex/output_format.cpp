#include <iostream>

void intenger_format();
void adjust_output_width();
void fill_field();
void show_point();

/*
    在使用 std::cout 输出整数时，可以使用 std::ios_base 中的
    std::hex std::dec std::oct 成员函数来控制输出一个数字的不同进制。
*/
void intenger_format()
{
/*
    使用 std::hex(std::cout); 
    会将 cout 的计数系统格式状态设置为 16 进制。
*/
#if false
    std::hex(std::cout);
    std::cout << 31 << ' ' << 6 << ' ' << 90 << '\n';
#endif

/*
    由于 hex dec 等是函数，因此有一种更常规的用法：
    根据拼接输出的原理，可以使用插入运算符 << 来达到和上面相同的效果。
*/
    std::cout << std::hex << 12 << ' ' << 7653 << ' ' << 3265245 << '\n';       // 16 进制
    std::cout << std::dec << 12 << ' ' << 7653 << ' ' << 3265245 << '\n';       // 10 进制
    std::cout << std::oct << 12 << ' ' << 7653 << ' ' << 3265245 << '\n';       //  8 进制
}

/*
    使用 std::cout.width() 成员函数将长度不同的数字放到宽度相同的字段中，它有 2 个版本：

    1. int width()                          无参，返回当前的字段宽度设置
    2. int width(std::streamsize __wide)    将字段宽度设置为 i 个空格并返回当前设置值

    需要注意的是，width 只会影响接下来显示的一个项目，显示完毕后就会恢复默认值。
    此外，C++ 永远不会截短数据，若试图在宽度为 2 的字段中打印一个 7 位值，C++ 将增宽字段（视内容重于形势）
*/
void adjust_output_width()
{
#if false
    std::cout << '$';
    std::cout.width(8);     // 设置下一次显示的字段长度为 8

    /*
        12.524 占了 6 字节，根据规则，这 6 个字符会被放在 8 个字段的最右边（右对齐）
        最终的输出为 "  12.524  1000000"

    */
    std::cout << 12.524 << ' ' << 1000000 << '\n';
#endif

    using std::cout;

    int _width = cout.width(30);
    cout << "Default field width = " << _width << ":\n";

    cout.width(5);
    cout << "N" << ':';

    cout.width(8);
    cout << "N * N" << ":\n";

    for (long int index = 1; index <= 100; index *= 10)
    {
        cout.width(5);
        cout << index << ':';
        cout.width(8);
        cout << index * index << ":\n";
    }

}

/*
    默认情况下，std::cout 使用 Space 来填充字段未被使用的部分，
    可以使用 std::cout.fill() 来改变填充的字符，和 width 相同，它也有 2 个版本：

    1. char fill();             无参，返回当前默认的填充字符
    2. char fill(char __ch);    改变当前的填充字符（一直有效）
*/
void fill_field()
{
#if false
    std::cout << '$';
    std::cout.width(8);
    std::cout.fill('*');
    std::cout << 12.05 << '\n';
#endif
    using std::cout;

    /*使用 '*' 来填充字段未被使用的部分*/
    cout.fill('*');
    const char * _staff[2] = {"Waldo Whipsnade", "Wilmarie Wooper"};
    long int _bonus[2] = {900, 1350};

    for (int index = 0; index < 2; ++index)
    {
        cout << _staff[index] << ": $";

        /*接下来一次输出的数字要以使用长度为 7 的字段且右对齐，未被使用的部分用 '*' 填充*/
        cout.width(7);
        cout << _bonus[index] << '\n';
    }
}

/*
    为了提升小数点显示的精度和美观，
    可以采用 ios_base 类提供的 setf 成员函数，并配合 showpoint 等标志位来控制小数的输出样式。
    showpoint 等标志位是在 ios_base 类中的静态常量，需要通过作用域运算符（::）来访问。

    setf 成员方法的用法比较复杂，本函数只演示 showpoint 的用法。
*/
void show_point()
{
    float price_1 = 20.40;
    float price_2 = 1.9 + 8.0 / 9.0;

    /*
        显示小数点，默认为 6 位（包括整数但不包括小数点），如：
        2.5         显示为     2.50000
        564.77      显示为     564.770
        1179.45     显示为     1179.45
        816924.01   显示为     816924.      （只显示 6 位，多出的被截）
    */
    std::cout.setf(std::ios_base::showpoint);
    std::cout << "\"Furry Friends\" is $" << price_1 << "!\n";
    std::cout << "\"Fiery Fiends\" is $" << price_2 << "!\n";

    /*用于控制显示的位数*/
    std::cout.precision(2);
    
    std::cout << "\"Furry Friends\" is $" << price_1 << "!\n";      // 20.40 被显示为 20.
    std::cout << "\"Fiery Fiends\" is $" << price_2 << "!\n";       // 2.78889 被显示为 2.8
}

int main(int argc, char const *argv[])
{
    show_point();

    return EXIT_SUCCESS;
}
