#ifndef __PLANET_H_
#define __PLANET_H_

#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include <limits>

#include <MyLib\myLogerDef.h>
#include <MyLib\myDelay.h>

/**
 * @brief 用于忽略输入流缓冲区中换行符前的剩余数据。
*/
static inline void cleanResidualStream(void) { while (std::cin.get() != '\n') { continue; } }

static inline bool checkInputState(std::istream & __in)
{
    using namespace MyLib::MyLoger;

    if (__in.fail())
    {
        __in.clear();
        __in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        ERROR_LOG("Invalid input! Please only enter number!\n");

        MyLib::MyDelay::delay(1000);

        return false;
    }

    return true;
}

/**
 * @brief 记录某一行星相关信息的结构体
*/
typedef struct __Planet
{
    char name[20];                  // 行星名
    double population {0.0};        // 所在族群
    double g {0.0};                 // 重力加速度

    /**
     * @brief 用户从键盘输入行星信息并存入该结构体。
    */
    bool getPlanetData(void);

    /**
     * @brief 数据说明
    */
    void dataDesc(void);

    /**
     * @brief 清除整个结构体的数据。 
    */
    void clearData(void) { std::memset(this, 0, sizeof(__Planet)); }

    /**
     * @brief 重载 << 运算符往标准输出发送整个 Planet 结构体的信息。
    */
    friend std::ostream & operator<<(std::ostream & __os, const __Planet & __pl);
} Planet;

class PlanetInfo_Operator
{
    private:
        const std::string dataFilePath = "./plenat.dat";

        std::ifstream readStream;
        std::ofstream writeStream;
        Planet planet;

    public:
        /**
         * @brief 读取文件内容，在程序开始运行时显示文件内的数据
        */
        void readPlanetData(void);

        /**
         * @brief 往文件末尾添加数据
        */
        void addNewPlanetData(void);

        /**
         * @brief 读取整个文件的内容
        */
        void showRevisedPlanetData(void);
};

#endif // __PLANET_H_