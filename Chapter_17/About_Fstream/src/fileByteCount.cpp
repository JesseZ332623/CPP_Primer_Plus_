#include <fstream>
#include <cstring>
#include <MyLib/myLogerDef.h>
#include <MyLib/myDelay.h>

/**
 * 程序目标，从 argv 中读取文件路径列表，
 * 逐个统计每一个文件的字节数，然后报告。（文件最后是文本文件）
*/

using namespace MyLib::MyLoger;
using MyLib::MyDelay::delay;

/**
 * @brief 检查程序输入参数，如果用户没有输入参数则需要告知使用方法。
 * 
 * @param __argumentCount 参数数目
 * @param __programName   程序名
 * 
 * @return non-return
*/
inline void checkArgument(const int __argumentCount, const char * __programName);

/**
 * @brief 计算单个文件的字节数并返回。
 * 
 * @param __readStream  输入文件流对象的引用
 * @param __filePath    文件路径
 * 
 * @return 文件字节数
*/
std::size_t getFileBytesCount(std::ifstream & __readStream, const char * __filePath);

/**
 * @param 计算 __argumentValue 指向的参数列表中，最长参数的长度，作为下划线的长度。
 * 
 * @param __argumentCount   参数数目
 * @param __argumentValue   参数列表
 * 
 * @return 最长参数的长度 + 5
*/
std::size_t getMaxSplitLength(const int __argumentCount, char const * __argumentValue[]);

int main(int argc, char const *argv[])
{
    system("cls");
    checkArgument(argc, argv[0]);

    std::ifstream readStream;
    std::size_t oneFileBytesCount = 0ULL;
    std::size_t totalBytesCount = 0ULL;
    std::size_t maxSplitLength = getMaxSplitLength(argc, argv);

    printSplitLine(maxSplitLength, '-');
    for (int fileNumber = 1; fileNumber < argc; ++fileNumber)
    {
        oneFileBytesCount = getFileBytesCount(readStream, argv[fileNumber]);

        if (!oneFileBytesCount) { continue; }

        totalBytesCount += oneFileBytesCount;

        loger(
                std::cout, CORRECT, 
                "File list [", fileNumber, "]\n"
        );
        loger(
                std::cout, NOTIFY, 
                "Path: ", argv[fileNumber], 
                "\nBytes count = ", oneFileBytesCount, " Bytes.\n"
            );
    }

    printSplitLine(maxSplitLength, '-');
    loger(
            std::cout, CORRECT, 
            "File list count = ", argc - 1, '\n',
            "Total files bytes count = ", totalBytesCount, " Bytes.\n"
        );

    DONE
    return EXIT_SUCCESS;
}

void checkArgument(const int __argumentCount, const char * __programName)
{
    if (__argumentCount == 1)
    {
        loger(std::cerr, ERROR, "Usage: ", __programName, " filename[s].\n");

        DONE
        std::exit(EXIT_SUCCESS);
    }
}

std::size_t getFileBytesCount(std::ifstream & __readStream, const char * __filePath)
{
    __readStream.open(__filePath);

    if (!__readStream.is_open())
    {
        loger(std::cerr, ERROR, "Couldn't open ", __filePath, '\n');
        __readStream.clear();
        return 0;
    }

    std::size_t fileBytesCount = 0ULL;
    char ch;

    while (__readStream.get(ch)) { ++fileBytesCount; }

    __readStream.clear();
    __readStream.close();

    return fileBytesCount;
}

std::size_t getMaxSplitLength(const int __argumentCount, char const * __argumentValue[])
{
    if (!__argumentValue) { return 0; }

    if (__argumentCount == 2) { return std::strlen(__argumentValue[1]) + 5; }

    std::size_t maxLength = 0;
    for (int argcount = 1; argcount < __argumentCount; ++argcount)
    {
        std::size_t argLength = std::strlen(__argumentValue[argcount]);
        if (maxLength < argLength) 
        { 
            maxLength = argLength; 
        }
    }

    return maxLength + 5;
}