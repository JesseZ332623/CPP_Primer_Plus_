#include <algorithm>
#include <random>
#include <vector>
#include <random>
#include <MyLib/myLib.h>

using namespace MyLib::MyLoger;
using namespace MyLib::SimpleContainerOperator;
using MyLib::MyDelay::delay;

/**
 * @brief 将 vector 容器内按给定的范围升序填入。
 * 
 * @param __boundNumList 需要填入数据的 vector 容器
 * @param __maxValue     填入数字的最大值，最后容器内就是 1 ~ __maxValue 的数列
 * 
 * @return non-return
*/
void getBoundValue(std::vector<int> & __boundNumList, int __maxValue);

/**
 * @brief 获取指定范围内指定长度的彩票中奖代码。
 *        比如 `getLottoWinnerCode(51, 6)` 就意味在 `1 ~ 51` 的范围内生成一条 `6` 位的彩票代码。
 *        当然，实现方法非常简单，先准备一个由 `1 ~ __maxValue` 组成的 `vector` 数列，再使用
 *        `std::shuffle()` 打乱这个数列，取数列的第一位填入中奖代码，
 *        执行 `__codeLength` 次后返回最终的中奖号码。
 * 
 * 
 * @param __maxValue    彩票中奖号码中每一位数字的范围
 * @param __codeLength  中奖号码长度
 * 
 * @return 最后生成的中奖号码
*/
std::vector<int> getLottoWinnerCode(int __maxValue, int __codeLength);
 
int main(int argc, char const *argv[])
{
    std::clock_t startTime = 0L;
    double costTime = 0.0;

    while (true)
    {
        loger(std::cout, NOTIFY, "Current time is: [", getCurrentTime(), "]\n");
        loger(std::cout, NOTIFY, "And today's lotto winner code is:\n");

        startTime = std::clock();

        /*从 51 个数中随机挑选 16 个数作为中奖代码*/
        std::vector<int> winnerLottoCode = getLottoWinnerCode(15000000, 16);

        costTime = (double)(std::clock() - startTime) / CLOCKS_PER_SEC;

        showContainerToStream(std::cout, winnerLottoCode, 16);
        loger(std::cout, CORRECT, costTime, " ms.\n");

        delay(1000);
        system("cls");
    }
    
    DONE

    return EXIT_SUCCESS;
}

void getBoundValue(std::vector<int> & __boundNumList, int __maxValue)
{
    //__boundNumList.resize(__maxValue);

    for (int number = 1; number <= __maxValue; ++number)
    {
        __boundNumList[number - 1] = number;
    }
}

std::vector<int> getLottoWinnerCode(int __maxValue, int __codeLength)
{
    /*使用高质量的随机数生成器*/
    std::mt19937 randomDevice(std::random_device{}());

    /*一条由 1 ~ __maxValue 组成的 vector 数列*/
    std::vector<int> boundNumList(__maxValue);

    /*最终的中奖代码*/
    std::vector<int> winnerCode(__codeLength);

    getBoundValue(boundNumList, __maxValue);

    for (int randomTimes = 0; randomTimes < __codeLength; ++randomTimes)
    {
        std::shuffle(boundNumList.begin(), boundNumList.end(), randomDevice);

        winnerCode[randomTimes] = boundNumList[0];
    }

    return winnerCode;
}
