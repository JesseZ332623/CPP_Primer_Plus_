#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <windows.system.h>

#define IS_FILE_OPEN(fStream, filePath) \
                    if (!fStream.is_open()) \
                    { std::cerr << "Open " << filePath << " Failed...\n"; }

#define USE_STD_GETLINE true
#define USE_STD_ISTREAM_ITERATOR false

int main(int argc, char const *argv[])
{
    system("cls");
    std::ifstream readFStream("./textFile.txt", std::ios_base::in);

    IS_FILE_OPEN(readFStream, "./textFile.txt");

    std::string tempLineString; 
    std::vector<std::string> fileLineVec;

#if USE_STD_GETLINE
    while (std::getline(readFStream, tempLineString, '.'))
    {
        if (*tempLineString.begin() == ' ') { tempLineString.erase(tempLineString.begin()); }

        tempLineString.push_back('.');

        fileLineVec.push_back(tempLineString);
    }
    std::for_each(fileLineVec.begin(), fileLineVec.end(), 
                      [](const std::string & __str) 
                      { 
                            for (const char __ch : __str) { std::cout << __ch; Sleep(1.5); }
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
