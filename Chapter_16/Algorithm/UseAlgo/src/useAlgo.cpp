#include "../include/useAlgo.h"

bool isWord(const std::string & __string)
{
    if (__string.empty()) { return false; }

    bool foundNonAlpha = false;

    for (const char ch : __string)
    {
        if (!std::isalpha(ch)) { foundNonAlpha = true; break; }
    }

    return (!foundNonAlpha) && (__string.front() != ' ');
}

std::string & getLowerString(std::string & __string)
{
    std::transform(
                    __string.begin(), __string.end(), __string.begin(), 
                    [] (unsigned char n) { return std::tolower(n); }
                  );
    return __string;
}

void wordsUserInput(std::vector<std::string> & __wordsArray)
{
    std::string tempWordsString;
    using namespace MyLib::MyLog;
    using MyLib::MyDelay::delay;
    
    log(std::cout, NOTIFY, "Enter some words (Press `.quit` to Quit.):\n");
    while (std::cin >> tempWordsString && tempWordsString != ".quit")
    {
        if (!isWord(tempWordsString))
        { 
            log(std::cout, WARNING, tempWordsString, " Is Invalid Input! Just Input Words!\n");
            log(std::cout, NOTIFY, "Enter some words (Press `.quit` to quit.):\n");

            continue;
        }
        __wordsArray.push_back(tempWordsString);
    }

    log(std::cout, NOTIFY, "Input Complete, quit.\n");
    delay(1000);
    system("cls");
}

void getAlphabeticalOrderSet(const std::vector<std::string> & __wordsArray, std::set<std::string> & __wordsSet)
{
    std::vector<std::string> tempWordsArray = __wordsArray;

    std::transform(tempWordsArray.begin(), tempWordsArray.end(), tempWordsArray.begin(), getLowerString);
    /*
        先把 __wordsArray 所有的字符串全转成小写，
        然后插入 __wordsSet
    */
    __wordsSet.insert(tempWordsArray.begin(), tempWordsArray.end());
}

void getAppearTimesOfEveryWords(const std::vector<std::string> & __wordsArray, const std::set<std::string> & __wordsSet, 
                                std::map<std::string, int> & __wordsMap)
{
    std::set<std::string>::iterator wordsSetIter;

    for (wordsSetIter = __wordsSet.begin(); wordsSetIter != __wordsSet.end(); ++wordsSetIter)
    {
        __wordsMap[*wordsSetIter] = std::count(__wordsArray.begin(), __wordsArray.end(), *wordsSetIter);
    }
}

std::ostream & operator<<(std::ostream & __os, const std::pair<std::string, int> & __pair)
{
    __os.width(15);
    __os << std::left << __pair.first << "\t\t" << __pair.second << '\n';

    return __os;
}