#include "./place_new.h"

int main(int argc, char const *argv[])
{
    /*从堆空间申请 512 字节的内存，返回地址给 buffer*/
    byte *buffer = new byte[BUFFER];

    Place_New *pc_1, *pc_2;

    /*
        在 buffer 所指向的内存块中分配 16 字节的内存给 Place_New 类，
        并 返回地址给 pc_1

        在堆空间里面分配 16 字节给 Place_New 类，
        并返回地址给 pc_2
    */
    pc_1 = new(buffer) Place_New;
    pc_2 = new Place_New("Place New 02", 2);

    /*
        输出 buffer 所指向的内存块的首地址，
        以及 Place_New 类型指针 pc_1 指向的地址，
        他们的结果是相同的。
    */
    cout << "------------------------------------------\n";
    cout << "Memory bolock address:\n" 
         << "Buffer: " << (void *)buffer 
         << " Heap: " << pc_1 << "\n\n";

    /*输出这两个类的地址和数据*/   
    cout << "Memory contence: \n";
    cout << pc_1 << ": ";
    pc_1->show();
    cout << pc_2 << ": ";
    pc_2->show();
    cout << "------------------------------------------\n";


    Place_New *pc_3, *pc_4;

    /*
        在 buffer 所指向的内存块中分配 16 字节的内存给 Place_New 类，
        并 返回地址给 pc_3 （此时 pc_2 所指向的数据被覆盖）

        在堆空间里面分配 16 字节给 Place_New 类，
        并返回地址给 pc_4
    */
    //pc_3 = new(buffer) Place_New("Bad Idea", 6);
    /*为了防止数据被覆盖，应该偏移指针，如下：*/
    pc_3 = new(buffer + sizeof(Place_New)) Place_New("Good", 6);
    pc_4 = new Place_New("Heap 2", 10);

    cout << "------------------------------------------\n";

    /*输出这两个类的地址和数据*/
    cout << "Memory contence: \n";
    cout << pc_3 << ": ";
    pc_3->show();
    cout << pc_4 << ": ";
    pc_4->show();

    /*
        注意：pc_1 和 pc_3 是通过定位 new 运算符存放在 buffer 指向的内存地址中。
        因此，千万不能使用 delete 去释放，这会导致运行阶段错误。
        正确的做法是：使用 delete[] 释放 buffer 所指向的内存，
        pc_1 和 pc_3 可以通过显示的调用析构函数去释放。
    */
    cout << "------------------------------------------\n";

    pc_1->~Place_New();
    pc_3->~Place_New();

    delete pc_2;
    delete pc_4;
    delete[] buffer;

    cout << "Done.... \n";
    
    return EXIT_SUCCESS;
}
