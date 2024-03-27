#include "./include/defs.h"

/**
 * C++ functional 库的存在使得 C++ 支持函数式编程，
 * 同时该库也为一些运算符提供了相应的函数符，如下所示：
 * 
 *        +           plus
 *        -           minus
 *        *           multiplies
 *        /           divides
 *        %           modulus
 *        -           negate（负号）
 *        ==          equal_to
 *        !=          not_equal_to
 *        >           greater
 *        <           less
 *        >=          greater_equal
 *        <=          less_equal
 *        &&          logic_and
 *        ||          logic_or
 *        !           logic_not
*/
#include <functional>
#include <vector>
#include <fstream>


int main(int argc, char const *argv[])
{

#if LINUX
    system("clear");

#elif WINDOWS_X86
    system("cls");
#endif

#if false
    std::vector<int> result = {1, 2, 3, 4, 5};

    /*
        该函数的工作流程很简单：将 result 中的每一个元素 + 114514
        然后发送到标准输出。
    */
    std::transform(
                    result.begin(), result.end(), 
                    std::ostream_iterator<int, char>(std::cout, " "),
                    /**
                     * C++ 新标准似乎摒弃了 bind1st() bind2nd() 之类的库函数，
                     * 而是全部整合在了一个统一的 bind() 函数里面，
                     * 通过 std::placeholders::_1 ~ _29 来确定绑定函数符的参数个数。
                    */
                    std::bind(std::plus<int>(), std::placeholders::_1, 114514)
                  );
#endif
    std::ofstream writeStream("./result.txt", std::ios_base::out);

    std::vector<int> vecA = {1, 2, 3, 4, 5};
    std::vector<int> vecB = {5, 4, 3, 2, 1};

    std::cout << "Vector A: \n";
    showContainerToStream(std::cout, vecA);

    std::cout << "Vector B: \n";
    showContainerToStream(std::cout, vecB);


    std::cout << "Total of A and B = ";
    /*
        把两个长度相同的 vector 中的数据相加并发送到标准输出中。
    */
    std::transform(
                    vecA.begin(), vecA.end(),
                    vecB.begin(), std::ostream_iterator<int, char>(std::cout, " "),
                    std::plus<int>()
                  );
    putchar('\n');

    std::vector<double> vecC = {41235.1346, 213562133.13454, 76563.567456, 786.5462, 2546.34};

    /*
        把 vecC 中的所有元素都 / 114514，
        然后把结果输出到指定的文件流之中，使用定点计数法且保留 4 位小数。
    */
    writeStream.precision(4);
    writeStream << std::fixed;
    std::transform(
                    vecC.begin(),vecC.end(),
                    vecB.begin(), std::ostream_iterator<double, char>(writeStream, " "),
                    std::bind(std::divides<double>(), std::placeholders::_1, 114514)
                  );

    writeStream.close();

    return EXIT_SUCCESS;
}
