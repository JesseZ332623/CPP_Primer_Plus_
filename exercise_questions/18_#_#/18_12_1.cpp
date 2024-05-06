#include <iomanip>
#include <initializer_list>
#include <algorithm>

#include <MyLib/myLogerDef.h>

template <typename ElementType>
ElementType averageList(std::initializer_list<ElementType> __numList);

int main(int argc, char const *argv[])
{
    using namespace MyLib::MyLoger;

    auto q = averageList({ 15.4, 10.7, 9.0 });
    auto x = averageList<double>({ 'A', 70, 65.33 });

    loger(
        std::cout, NOTIFY, std::setprecision(5),
        "q = averageList({ 15.4, 10.7, 9.0 }) = ", q, '\n',
        "x = averageList<double>({ 'A', 70, 65.33 }) = ", x, '\n',
        "averageList({ 20, 30, 19, 45, 17 }) = ", averageList({ 20, 30, 19, 45, 17 }), '\n'
    );
    
    return EXIT_SUCCESS;
}

template <typename ElementType>
ElementType averageList(std::initializer_list<ElementType> __numList)
{
    ElementType average;
    std::for_each(
                    __numList.begin(), __numList.end(), 
                    [& average](const ElementType & __n) { average += __n; }
                );

    return average / __numList.size();
}
