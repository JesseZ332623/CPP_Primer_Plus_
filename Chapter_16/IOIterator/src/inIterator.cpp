#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <ctime>

#define IS_FILE_OPEN(fStream, filePath) \
                    if (!fStream.is_open()) \
                    { std::cerr << "Open " << filePath << " Failed...\n"; }

/*使用 std::getline() 去读取文件*/
#define USE_STD_GETLINE true

/*使用 std::istream_iterator 去读取文件*/
#define USE_STD_ISTREAM_ITERATOR false

/**
 * @brief 自制延时函数，用于代替 windows 库中的 Sleep()
 * 
 * @param __millisSeconds 延时时间（毫秒）
 * 
 * @return non-return
*/
void delayMilliseconds(long int __millisSeconds);

void delayMilliseconds(long int __millisSeconds)
{
    /*获取开始时间戳*/
    std::time_t startTime = std::clock();

    while (std::clock() < (startTime + __millisSeconds)) { }
}

int main(int argc, char const *argv[])
{
    system("cls");
    const char filePath[] = "./textFile.txt";
    std::ifstream readFStream(filePath, std::ios_base::in);

    IS_FILE_OPEN(readFStream, filePath);

    std::string tempLineString; 
    std::vector<std::string> fileLineVec;
    std::size_t fileBytes = 0L;

#if USE_STD_GETLINE
    while (std::getline(readFStream, tempLineString, '.'))
    {
        if (*tempLineString.begin() == ' ') { tempLineString.erase(tempLineString.begin()); }

        tempLineString.push_back('.');

        fileBytes += tempLineString.size();

        fileLineVec.push_back(tempLineString);
    }

    std::cout << "File path: " << filePath << '\n';
    std::cout << "File size = " << fileBytes + 1 << " Bytes." << '\n';
    std::for_each(fileLineVec.begin(), fileLineVec.end(), 
                      [](const std::string & __str) 
                      { 
                            for (const char __ch : __str) { std::cout << __ch; delayMilliseconds(15); }
                      }
                      );
#endif // USE_STD_GETLINE

#if USE_STD_ISTREAM_ITERATOR
    std::copy(std::istream_iterator<char, char>(readFStream), std::istream_iterator<char, char>(), tempLineString.begin());

    std::cout << tempLineString << '\n';
#endif // USE_STD_ISTREAM_ITERATOR

    readFStream.close();
    return EXIT_SUCCESS;
}
