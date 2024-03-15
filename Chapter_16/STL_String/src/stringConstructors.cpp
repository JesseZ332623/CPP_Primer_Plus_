#include <iostream>
#include <string>

/**
 * C++ STL 中的 string 其实是 basic_string 模板类 char 具体化的 typedef，
 * 它的构建构建函数有如下 9 个：
 * 
 * 1. string(const char * __s)                      使用 C 风格字符串构建 string 类
 * 
 * 2. string(size_type __n, char __c)               创建一个包含 __n 个元素的 string 对象，每一个元素都是字符 __c
 * 
 * 3. string(const string & __str)                  拷贝构造函数，将 string 对象初始化为另一个 string 对象 __str
 * 
 * 4. string(void)                                  默认构造函数，创建一个长度为 0 的 string 对象
 * 
 * 5. string(const char * __s, size_type __n)       将 C 风格字符串 __s 中的前 __n 个字符交给 string 类去构建（哪怕超过了 __s 的长度）
 * 
 * 6. template <typename Iter> 
 *    string(Iter __begin, Iter __end)              将 string 对象初始化为区间 [__begin, __end) 迭代器内的字符（一般是从另一个 string 对象 或 C 风格字符串拷贝）
 * 
 * 7. string(const string & __str, 
 *           size_type __pos, size_type __n = npos) 将 string 对象初始化为对象 __str 中，从 __pos 开始到结尾的字符，或从 __pos 开始到  __n 的字符
 * 
 * 8. string(string && __str) noexcept              移动构造函数（C++ 11 新增）将 __str 中的数据搬到 string 对象中
 * 
 * 9. string(initializer_list<char> __li)           从初始化列表拷贝（C++ 11 新增）                      
 * 
*/
using std::string;
using std::cout;

int main(int argc, char const *argv[])
{
    string one("Lottery Winner!");                  // #1
    string two(20, '$');                            // #2
    string three(one);                              // #3
    string four;                                    // #4
    four = (two + three);                           // operator+()，#3
    one += " Opps!";                                // operator+=()
    char alls[] = {"All's well that ends well."};
    string five(alls, alls + sizeof(alls));         // #6
    string six(alls + 5, sizeof(alls) - 5);         // #5
    string seven(&five[2], &five[10]);              // operator[]()，#6
    string eight(four, 2, 8);                       // #7

    //string nine = std::move(one);                 // #8

    string ten = {"ABCDEFGHIJKLMN"};                // #9

    cout << one << '\n' << two << '\n' << three << '\n' << four << '\n' << five << '\n';
    cout << six << '\n' << seven << '\n' << eight << '\n' << ten << '\n';

    return EXIT_SUCCESS;
}
