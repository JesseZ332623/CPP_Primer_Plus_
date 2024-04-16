#include <iostream>
#include <algorithm>
#include <vector>
#include <valarray>
#include <array>
#include <cmath>

#include <MyLib/myLib.h>

int main(int argc, char const *argv[])
{
    using namespace MyLib::MyLog;
    using namespace MyLib::SimpleContainerOperator;

    std::vector<double> numberList = {9, 16, 25};
	std::vector<double> resultList(numberList.size());

    std::transform(numberList.begin(), numberList.end(), resultList.begin(), [](double __num) { return std::log(__num); });

	log(std::cout, NOTIFY, "Container of resultList: ");
    showContainerToStream(std::cout, resultList);

    return EXIT_SUCCESS;
}
