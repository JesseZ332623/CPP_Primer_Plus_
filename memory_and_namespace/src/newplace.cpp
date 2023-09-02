#include <iostream>
#include <new>

const int BUFFER_SIZE = 5120;        /*内存块的大小*/
const int N = 15;

char buffer[BUFFER_SIZE] = {"0"};   /*设置内存块*/

int main(int argc, char const *argv[])
{
    using namespace std;

    int index = 0;
    double *ptr_1, *ptr_2;

    cout << "Calling a new placement new:\n";

    ptr_1 = new double[N];                      /*从 堆 (heap) 里面申请 5 * 8 Bytes 的内存*/
    ptr_2 = new (buffer) double[N];             /*从 内存块 buffer 里面 借 40 Bytes 的内存*/

    for (index; index < N; ++index)
    {
        ptr_1[index] = ptr_2[index] = 1000 + 20.0 * index;
    }

    cout << "Memory address:\n" << "In heap: " << ptr_1;
    cout << " In static: " << (void *)buffer << "\n\n";

    index = 0;
    cout << "Memory contence: " << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "\t\tHeap" << "\t\t\t" << "\t\tStatic" << endl;
    for (index; index < N; ++index)
    {
        cout << "Address: " << &ptr_1[index] << '\t' << "value: " << ptr_1[index] << '\t';
        cout << "Address: " << &ptr_2[index] << '\t' << "value: " << ptr_2[index] << endl;
    }

    cout.put('\n');

    delete ptr_1;
    
    return EXIT_SUCCESS;
}
