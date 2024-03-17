#include <iostream>
#include <cstring>

int main(int argc, char const *argv[])
{
    using std::cout, std::cin, std::string;

    string emptyString;             // 空字符串，执行默认构造函数
    string smallString = "bit";     // 短小字符串
    string lagerString = "Elephants are a girl's best friend.";     // 较长的字符串

    cout << "-----------------------------\n";
    cout << "std::string::size\n";
    cout << "-----------------------------\n";
    cout << "emptyString.size() = " << emptyString.size() << '\n'           // 字符串的长度
         << "smallString.size() = " << smallString.size() << '\n'
         << "lagerString.size() = " << lagerString.size() << '\n';
    cout << "-----------------------------\n";
    cout << "std::string::capacity\n";
    cout << "-----------------------------\n";
    cout << "emptyString.capacity() = " << emptyString.capacity() << '\n'   // 字符串的容量，默认容量是 15 个字节
         << "smallString.capacity() = " << smallString.capacity() << '\n'
         << "lagerString.capacity() = " << lagerString.capacity() << '\n';

    emptyString.reserve(50);        // reserve 可以重设指定字符串的大小
    cout << "After reserve(50), emptyString.capacity() = " << emptyString.capacity() << '\n';

    return EXIT_SUCCESS;
}
