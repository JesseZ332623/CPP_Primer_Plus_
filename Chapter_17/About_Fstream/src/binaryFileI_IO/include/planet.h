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
static inline void cleanResidualStream(void);

/**
 * @brief 检查输入缓冲区中的流格式是否正确，不正确要忽略此次输入。
 * 
 * @param __in          标准输入流的引用
 * @param __errMessage  若格式错误输出的信息
 * 
 * @return 格式是否正确
*/
static bool checkInputState(std::istream & __in, const char * __errMessage);

static inline void cleanResidualStream(void) { while (std::cin.get() != '\n') { continue; } }

static bool checkInputState(std::istream & __in, const char * __errMessage)
{
    using namespace MyLib::MyLoger;

    if (__in.fail())
    {
        __in.clear();
        __in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        ERROR_LOG(__errMessage);

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
     * @brief 封装对数字类型的输入与检查，用来过滤输入垃圾数据避免造成程序混乱。
     * 
     * @tparam DataType     Planet 结构体数据成员的类型
     * 
     * @param __is          标准输入流的引用
     * @param __member      Planet 结构体的数字类型成员
     * @param __promote     对成员数据的描述，用于提示用户
     * @param __errMessage  若检查到输入流格式错误所报的错误信息
     * 
     * @return non_return
    */
    template <typename DataType>
    void inputAndCheck(
                        std::istream & __is, DataType & __member, 
                        const char * __promote, const char * __errMessage
                    )
    {
        using namespace MyLib::MyLoger;

        while (true)
        {
            NOTIFY_LOG(__promote);
            __is >> __member;

            if (checkInputState(__is, __errMessage)) { return; }
        }
    }

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
        const std::string dataFilePath{"../data/plenat.dat"};

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