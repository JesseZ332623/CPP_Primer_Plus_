#include <string>
#include <fstream>
#include <MyLib/myLogerDef.h>
#include <MyLib/myDelay.h>

using namespace MyLib::MyLoger;

void readTextFile(std::string & __filePath);

int main(int argc, char const *argv[])
{
    system("cls");

    std::string fileName;

    NOTIFY_LOG("Enter name of new file: \n");
    std::getline(std::cin, fileName);

    /**
     * 打开指定文件 fileName，第二个参数指定打开模式，
     * 默认为 std::ios_base::out
    */
    std::ofstream writeStream(fileName);
    double secretNumber = 0.0;

    /**
     * 往标准输出发送字符串
    */
    loger(std::cout, CORRECT, "For your eyes only!\n");


    NOTIFY_LOG("Enter your secret number: "); 
    std::cin >> secretNumber;

    /**
     * 往输出文件流发送字符串,
     * 由于是往文本文件输出，secretNumber 会被转化成字符串然后发送
    */
    writeStream.precision(15);
    writeStream << "Your secret number: " << secretNumber << '\n';

    writeStream.close();

    readTextFile(fileName);

    DONE

    return EXIT_SUCCESS;
}

void readTextFile(std::string & __filePath)
{
    char ch;
    std::ifstream readStream(__filePath);

    loger(std::cout, NOTIFY, "OK! Here a contents of [", __filePath, "]\n");

    printSplitLine(35, '-');

    while (readStream.get(ch))
    {
        std::cout << ch; 
        MyLib::MyDelay::delay(45);
    }

    printSplitLine(35, '-');

    std::cout << std::endl;

    readStream.close();
}
