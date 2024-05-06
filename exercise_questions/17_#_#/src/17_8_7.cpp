#include <MyLib/myLib.h>

#include <vector>
#include <string>
#include <fstream>

using namespace MyLib::MyLoger;
using namespace MyLib::SimpleContainerOperator;

int main(int argc, char const *argv[])
{
    system("cls");

    std::vector<std::string> voster, vister;
    std::string tempStr;

    NOTIFY_LOG("Enter the string (Empty line to quit):\n");

    while (std::getline(std::cin, tempStr) && !tempStr.empty())
    {
        voster.push_back(tempStr);
    }

    NOTIFY_LOG("Here is your input: \n");

    printSplitLine(45, '-');

    showContainerToStream(std::cout, voster, 5); puts("");

    printSplitLine(45, '-');

try
{
    std::ofstream outStream(
                                "../data/17_8_7/strings.dat", 
                                std::ios_base::out | std::ios_base::binary | std::ios_base::trunc
                            );

    if (!outStream.is_open()) { std::runtime_error("Couldn't Open File: ../data/17_8_7/strings.dat\n"); }

    std::for_each(
                    voster.begin(), voster.end(), 
                    [& outStream](const std::string & __str) 
                    {
                        std::size_t stringLen = __str.size();
                        const char * originStr = __str.c_str();

                        outStream.write(reinterpret_cast<char *>(&stringLen), sizeof(std::size_t));
                        outStream.write(originStr, stringLen);
                    }
                );

    CORRECT_LOG("OK! Write to the ../data/17_8_7/strings.dat\n");

    outStream.close();

    std::ifstream inStream(
                            "../data/17_8_7/strings.dat", 
                            std::ios_base::in | std::ios_base::binary
                        );
    if (!inStream.is_open()) { std::runtime_error("Couldn't Open File: ../data/17_8_7/strings.dat\n"); }

    while (true)
    {
        if (inStream.peek() == EOF) { break; }
        std::size_t stringLen = 0ULL;

        inStream.read(reinterpret_cast<char *>(&stringLen), sizeof(std::size_t));

        char * tempFileStr = new char[stringLen + 1];

        inStream.read(tempFileStr, stringLen);

        tempFileStr[stringLen] = '\0';

        vister.push_back(std::string(tempFileStr));

        delete[] tempFileStr;
    }
    
    printSplitLine(45, '-');

    showContainerToStream(std::cout, vister, 5); puts("");

    printSplitLine(45, '-');

    inStream.close();
}
catch (const std::exception & __exp) { ERROR_LOG(__exp.what()); }

    return EXIT_SUCCESS;
}
