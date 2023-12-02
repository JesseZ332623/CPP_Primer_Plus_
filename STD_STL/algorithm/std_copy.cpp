#include <iostream>
#include <bits/stl_algo.h>
#include <vector>

/*
    标准库算法 std::copy() 顾名思义，就是将一个容器的数据拷贝到另一个容器，用法如下：

    std::copy(src_container.iterator_a, src_container.iterator_a, dest_container.iterator);

    前面两个参数确定的源迭代器的范围，后面的参数代表目标迭代器。

    其次，std::copy 需要容器满足以下条件：

    1. 支持 push_back 或者 insert 等向容器添加元素的操作

    2. 元素类型可以拷贝和赋值

    所以，支持该算法的 STL 容器有：

        std::vector
        std::deque
        std::list
        std::array
        std::forward_list
        std::basic_string

    不支持该算法的 STL 容器有：

        std::set
        std::multiset
        std::map
        std::multimap
*/

void C_ARRAY_TO_STD_VECTOR()
{
    int _array_src[10] = {12, 13, 2, 347, 48, 95746, 3, 1234526, 246, 215};

    std::vector<int> _vector_dest(sizeof(_array_src) / sizeof(int));

    printf("data in _array_src :\n");
    for (auto & index : _array_src) { printf("%d ", index); } putchar('\n');

    std::copy(_array_src, _array_src + 10, _vector_dest.begin());

    printf("data in _array_dest:\n"); 
    for (auto & index : _vector_dest) { printf("%d ", index); } putchar('\n');
}


int main(int argc, char const *argv[])
{
    C_ARRAY_TO_STD_VECTOR();
    
    return EXIT_SUCCESS;
}
