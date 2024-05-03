/**
 * 程序目标：打开两个文件（./data/17_8_4_in_1.txt 和 ./data/17_8_4_in_1.txt）进行输入，
 * 打开一个文本文件（./data/17_8_4_result.txt）将前面两个输入的文件对应行的字符串拼接起来。
 * 
 * 若一个文件比另一个短，则将较长的文件中余下的几行直接复制到输出文件中。举例如下：
 * 
 * ./data/17_8_4_in_1.txt：
 * 1 eggs kitee donuts
 * 2 ballons hammers
 * 3 stones
 * 
 * ./data/17_8_4_in_2.txt
 * 1 zero lassitude
 * 2 finance drama
 * 
 * ./data/17_8_4_result.txt
 * 1 eggs kitee donuts zero lassitude
 * 2 ballons hammers finance drama
 * 3 stones
*/

#include <MyLib/myLogerDef.h>
#include <MyLib/myDelay.h>

#include <fstream>
#include <vector>
#include <algorithm>

using namespace MyLib::MyLoger;

static std::vector<std::string> inputStringArray;

typedef struct __FilePath
{
    std::vector<std::string> inFilePath;
    std::string resultFilePath;

    int callTimes;

} FilePath;

void dataInput(std::fstream & __fs, FilePath & __path);
void meargeAndWrite(std::fstream & __fs, FilePath & __path);
void showInputArr(std::vector<std::string> & __inputStrArr, const std::string & __path);

int main(int argc, char const *argv[])
{
    system("cls");

    std::fstream FIOStream;
    FilePath filePath = {{"./data/17_8_4_in_1.txt", "./data/17_8_4_in_2.txt"}, "./data/17_8_4_result.txt", 0};

    dataInput(FIOStream, filePath);
    dataInput(FIOStream, filePath);
    //filePath.callTimes = 0;

    meargeAndWrite(FIOStream, filePath);
    
    DONE

    return EXIT_SUCCESS;
}

void dataInput(std::fstream & __fs, FilePath & __path)
{
    try
    {
        /*
            打开指定文件进行输入，每次打开文件都会清空内容。
        */
        __fs.open(__path.inFilePath[__path.callTimes], std::ios_base::out | std::ios_base::trunc);

        if (!__fs.is_open()) 
        { 
            throw std::runtime_error("Countn't open " + __path.inFilePath[__path.callTimes] + '\n'); 
        }

        std::string tempString;
        std::size_t FLineCount = 1ULL;
        
        showInputArr(inputStringArray, __path.inFilePath[__path.callTimes]);
        NOTIFY_LOG
        (
            "Enter some words to " + __path.inFilePath[__path.callTimes] + \
            " (Line " + std::to_string(FLineCount) + " Press <quit> to end):\n"
        );
        while (std::getline(std::cin, tempString))
        {
            if (tempString == "quit") { break; }
            
            tempString.push_back('\n');

            __fs << tempString;
            inputStringArray.push_back(tempString);

            system("cls");
            showInputArr(inputStringArray, __path.inFilePath[__path.callTimes]);
             NOTIFY_LOG
            (
                "Enter some words to " + __path.inFilePath[__path.callTimes] + \
                " (Line " + std::to_string(FLineCount) + " Press <quit> to end):\n"
            );
        }

        __fs.clear();
        __fs.close();
        inputStringArray.clear();
    }
    catch (const std::exception & __excpt) { ERROR_LOG(__excpt.what()); }

    ++__path.callTimes;

    system("cls");
}

void meargeAndWrite(std::fstream & __fs, FilePath & __path)
{
    try
    {
        std::ifstream FInA(__path.inFilePath[0], std::ios_base::in);
        std::ifstream FInB(__path.inFilePath[1], std::ios_base::in);
        std::string tempStringA, tempStringB;
        /*
            打开指定文件进行输入，每次打开文件都会清空内容。
        */
        __fs.open(__path.resultFilePath, std::ios_base::out | std::ios_base::trunc);

        if (!__fs || !FInA || !FInB) 
        { 
            throw std::runtime_error("Countn't open " + __path.inFilePath[__path.callTimes] + '\n'); 
        }

        while (FInA.good() && FInB.good())
        {
            std::getline(FInA, tempStringA); 
            std::getline(FInB, tempStringB);

            tempStringA = (tempStringA + ' ' + tempStringB + '\n');

            inputStringArray.push_back(tempStringA);
            __fs << tempStringA;
        }

        while (FInA.good()) { std::getline(FInA, tempStringA); __fs << tempStringA << '\n'; }

        while (FInB.good()) { std::getline(FInB, tempStringB); __fs << tempStringB << '\n'; }

        showInputArr(inputStringArray, __path.resultFilePath);

        FInB.close();
        FInA.close();
        __fs.close();
    }
    catch (const std::exception & __excpt) { ERROR_LOG(__excpt.what()); }
}

void showInputArr(std::vector<std::string> & __inputStrArr, const std::string & __path)
{
    using MyLib::MyDelay::delay;

    printSplitLine(45, '-');
    NOTIFY_LOG("File path = [" + __path + "]\n");
    printSplitLine(45, '-');

    for (std::size_t index = 0; index < __inputStrArr.size(); ++index)
    {
        std::cout << index + 1 << '\t' << __inputStrArr.at(index);
        delay(35);
    }

    printSplitLine(45, '-');
}