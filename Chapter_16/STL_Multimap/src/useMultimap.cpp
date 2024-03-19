#include "./include/useMultimapDefs.h"
#include "./multimap.cpp"

#include <iterator>

using std::string;

using CityPair = std::pair<const int, string>;
using CityInfoMap = std::multimap<int, string>;

int main(int argc, char const *argv[])
{
    using std::cout, std::cerr;

    system("cls");

    CityInfoMap cityInfoMap;

    readConvertAndInsert("./cityInfo.txt", cityInfoMap);

    auto dataFormat = [](void) 
    { 
        cout << "City Code" << '\t' << "City Name" << '\n'; 
        printSplitLine(30, '-'); 
    };

    showMultimap(cityInfoMap, dataFormat);

    /*
        std::multimap 的 count() 成员方法通过传入键值来搜索多重映射表中该键所对应值的数目。
    */
    cout << CORRECT;
    cout << "Number of Cities with area code 415: " << cityInfoMap.count(415) << '\n';
    cout << "Number of Cities with area code 510: " << cityInfoMap.count(510) << '\n';
    cout << "Number of Cities with area code 415: " << cityInfoMap.count(718) << '\n';
    cout << ORIGINAL;

    printSplitLine(30, '-');

    /*
        构建一个存储两个 multimap 的迭代器的一个 pair，
        两个迭代器划定的范围是：键值 大于 415 小于 718 的区间，为：

        510             Oakland
        510             Berkeley
    */
    std::pair<CityInfoMap::iterator, CityInfoMap::iterator> range(cityInfoMap.upper_bound(415), cityInfoMap.lower_bound(718));

    /*
        由于 std::pair 类没有迭代器的概念，
        所以只能使用原始的 for 循环
    */
    cout << "Data with key values between 415 and 718: \n";
    dataFormat();
    for (auto it = range.first; it != range.second; ++it)
    {
        cout << it->first << "\t\t" << it->second << '\n';
    }
    printSplitLine(30, '-');


    /*
        std::multimap 还有一个 equal_range 成员方法，
        通过传入键值在多重映射表中搜索该键所对应的几个值，
        并返回一个由两个 std::multimap::iterator 所构成的 pair
    */
    std::pair<CityInfoMap::iterator, CityInfoMap::iterator> equalRange = cityInfoMap.equal_range(415);
    cout << "Data with key values equal 415: \n";
    dataFormat();
    for (auto it = equalRange.first; it != equalRange.second; ++it)
    {
        cout << it->first << "\t\t" << it->second << '\n';
    }
    printSplitLine(30, '-');

    return EXIT_SUCCESS;
}
