#include "./include/my_array.h"

int main(int argc, char const *argv[])
{
    using std::cout, std::endl;
    using MY_STL::Array;
    
    /*一个拥有 10 个元素，且每个元素都是 size_t 类型的 Array 模板类对象 total*/
    Array<size_t, 10> total;

    /*一个拥有 10 个元素，且每个元素都是 double 类型的 Array 模板类对象 average*/
    Array<double, 10> average;

    /*
        一个拥有 10 个元素，且每个元素都是一个拥有 5 个元素，
        且每个元素都是 int 类型的模板类对象的模板类对象 array
    */
    Array<Array<int, 5>, 10> array;

    int i, j;

    for (i = 0; i < 10; ++i)
    {
        total[i] = 0;
        for (j = 0; j < 5; ++j)
        {
            array[i][j] = (i + 1) * (j + 1);
            total[i] = array[i][j];
        }

        average[i] = (double)total[i] / 5;
    }

    for (i = 0; i < 10; ++i)
    {
        for (j = 0; j < 5; ++j)
        {
            cout.width(2);
            cout << array[i][j] << ' ';
        }
        cout << ": total = ";
        cout.width(3);
        cout.precision(2);
        cout << total[i] << ", average = " << average[i] << endl;
    }

    cout << "Done....\n";


    return EXIT_SUCCESS;
}
