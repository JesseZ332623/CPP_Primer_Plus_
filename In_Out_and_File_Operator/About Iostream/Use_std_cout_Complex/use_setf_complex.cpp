#include <iostream>
#include <cmath>

void setf_ver_1();
void setf_ver_2();

/*
    std::ios_base::setf() 有两个版本，先探究第一个版本，函数原型如下：

            fmtflags setf(fmtflags __fmtfl);

    其中，fmtflags 是 _Ios_Fmtflags 的 typedef，
    而 _Ios_Fmtflags 则是一个用于修改各个标志位的枚举类型（也可能是 STL bitset 容器，这个取决于实现），
    接下来举例几个常用的标志位：

    ios_base::boolalpha     将 bool 类型的输出改为 true(1) 和 false(0)
    ios_base::showbase      对于输出，使用基数前缀（0，0x）
    ios_base::showpoint     显示末尾的小数点（默认为 6 位，包括小数点前的整数）     
    ios_base::uppercase     对于 16 进制输出，使用大写字母；对于对数，E 也会大写
    ios_base::showpos       在正数前面加上 + 符号（仅仅针对 10 进制，这个也取决于实现）
    ios_base::scientific    使用科学计数法
    ios_base::fixed         使用定点计数法
    ios_base::left / right  使用 左/右 对齐
    ios_base::internal      符号或基数前缀左对齐，值右对齐

    需要注意的是，使用 setf 的修改会一直生效，所以可以使用下面两种方式还原：
    
    1.  使用 unsetf 还原单个标志位，传入的参数 和 setf 一样。
    2.  使用 ios::copyfmt 方法备份原格式，使用 setf 做出修改后 可以再次调用 copyfmt 方法进行还原。
*/
void setf_ver_1()
{
    using std::cout, std::endl, std::ios_base;

    /*使用 copyfmt 保存最初的格式*/
    std::ios format_back(nullptr);
    format_back.copyfmt(std::cout);

    
    int temperature = 21;
    cout.setf(ios_base::showpos);                                       // 在正数前面加上 + 符号
    cout << "Today's weather temperature: " << temperature << " digrees." << endl;

    cout << "For our programming friends, That's: ";
    cout << std::hex << temperature << " or ";                          // 使用 16 进制，默认

    cout.setf(ios_base::uppercase | ios_base::showbase);                // 可以使用 | 运算符（ios_base 已重载）同时打开多个标志位
    cout << temperature << endl;

    double distance = 384403.90;
    cout.setf(ios_base::scientific);                                    // 使用科学计数法
    cout.unsetf(ios_base::showpos | ios_base::uppercase);               // 关闭 正号显示 和 大写显示
    cout << "The average distance between the earth and the moon is: "  << distance << endl;

    cout.setf(ios_base::boolalpha);                                     // 显示 bool 类型值为 true 或 false
    std::cout << true << ' ' << false << endl;

    cout.setf(ios_base::internal | ios_base::showbase);                 // 符号或基数前缀左对齐，值右对齐，并再次打开基数前缀大写
    cout.width(12);                                                     // 设置字段宽为 12
    cout << std::hex << 33512344;                                       // 输出为 "0x   1ff5b98"

    /*最后在 cout 下调用这个方法，传入 ios 类的对象还原最初的格式标志*/
    std::cout.copyfmt(format_back);
}

/*
    接下来探究 std::ios_base::setf() 的第二个版本，函数原型如下：

        fmtflags setf(fmtflags __fmtfl, fmtflags __mask);

    参数 __fmtfl 和前面一样，而参数 __mask 则表示要清除参数 __fmtfl 中的那些位，规则如下：

    __fmtfl 中在 __mask 中为1的位会被设置。
    __fmtfl 中在 __mask 中为0的位会被清除。
    __fmtfl 中在 __mask 中未涉及的位将保持不变。

    此外，ios_base 为 __mask 提供了以下 3 个 参数：

    ios_base::basefiled
    ios_base::floatfiled
    ios_base::adjustfiled
*/
void setf_ver_2()
{
    using std::cout, std::endl, std::ios_base;
    
}

int main(int argc, char const *argv[])
{
    setf_ver_1();

    return EXIT_SUCCESS;
}
