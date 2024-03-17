#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <fstream>
#include <memory>

template <typename outputDataType, typename outputCharType>
std::unique_ptr<std::ostream_iterator<outputDataType, outputCharType>> makeOstreamIterator(std::ostream & __os, const char * __splitNote);

template <typename outputDataType, typename outputCharType>
std::unique_ptr<std::ostream_iterator<outputDataType, outputCharType>> makeOstreamIterator(std::ostream & __os, const char * __splitNote)
{
    return std::make_unique<std::ostream_iterator<outputDataType, outputCharType>>(__os, __splitNote);
}

int main(int argc, char const *argv[])
{
    std::string descString = "1234567890";
    std::string reverseDescString(descString);
    std::reverse(reverseDescString.begin(), reverseDescString.end());

    std::vector<std::string> stringVec = {descString, reverseDescString};
    std::ofstream textFileStream("./textFile.txt", std::ios_base::out);

    auto vectorInput = makeOstreamIterator<std::string, char>(textFileStream, "\n");

    std::copy(stringVec.begin(), stringVec.end(), *vectorInput);
    
    textFileStream.close();

    return EXIT_SUCCESS;
}

