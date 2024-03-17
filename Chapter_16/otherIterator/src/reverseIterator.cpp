#include "./include/mySleep.h"
#include "./include/myLogDef.h"

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

int main(int argc, char const *argv[])
{
    std::vector<int> numList = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

    std::cout << CORRECT;
    /*
        容器的 rbegin() 和 rend() 成员方法返回容器末尾后一个元素 和 第一个元素的迭代器（reverse_iterator 类型）
        有了这两个方法，我们就能向标准输出流倒序发送容器内容
    */
    std::copy(numList.rbegin(), numList.rend(), std::ostream_iterator<int, char>(std::cout, " ")); puts("");
    std::for_each(numList.rbegin(), numList.rend(), [](const int n) { std::cout << n << ' '; delayMilliseconds(50); });
    std::cout << ORIGINAL << '\n';

    /*
        当然也可以显式的声明 reverse_iterator，
        不过在有 for_each 的情况下不建议这样做。
    */
    std::cout << WARNING;
    for (std::reverse_iterator reIter = numList.rbegin(); reIter < numList.rend(); ++reIter)
    {
        std::cout << *reIter << ' ';
        delayMilliseconds(50);
    }
    std::cout << ORIGINAL;

    return EXIT_SUCCESS;
}
