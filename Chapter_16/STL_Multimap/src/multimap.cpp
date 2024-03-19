#include "./include/useMultimapDefs.h"

template <typename KeyType, typename ValueType>
std::pair<const KeyType, ValueType> makeStringToPair(const std::string & __fileLineString)
{
    std::size_t spacePos = __fileLineString.find(' ');

    return std::pair<const KeyType, ValueType>
           (
                std::stoi(__fileLineString.substr(0, spacePos), nullptr, 10), 
                __fileLineString.substr(spacePos + 1)
           );
}

template <typename KeyType, typename ValueType>
void readConvertAndInsert(const std::string __filePath, std::multimap<KeyType, ValueType> & __cityInfoTable)
{
   
    std::ifstream readStream(__filePath, std::ios_base::in);

    if (!readStream.is_open())
    {
        std::string what = "Open file: ";
        what += __filePath;
        what += " failed.\n";

        throw std::ios_base::failure(what);
    }

    std::cout << NOTIFY << "Load file: " << __filePath << "\n" << ORIGINAL;    

    std::string tempFileLine;

    while (std::getline(readStream, tempFileLine, '\n'))
    {
        __cityInfoTable.insert(makeStringToPair<KeyType, ValueType>(tempFileLine));
    }

    readStream.close();
}

template <typename KeyType, typename ValueType, typename DataFormatRule>
void showMultimap(const std::multimap<KeyType, ValueType> & __cityInfoTable, DataFormatRule __datformat)
{
    __datformat();

    std::for_each(__cityInfoTable.begin(), __cityInfoTable.end(), 
                  [](const auto & cityPair) 
                  { 
                        std::cout << cityPair.first << "\t\t" << cityPair.second << '\n';
                        delay(DEFAULT_DELAY_TIME);
                  }
                  );
    printSplitLine(30, '-'); 
}
