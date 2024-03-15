#include "./include/defs.h"

std::vector<std::string> WORDS_LIST;

std::size_t loadFileInList(const char * __filePath)
{
    std::ifstream readStream(__filePath, std::ios_base::in);
    std::string tempString;

    if (!readStream.is_open()) 
    { 
        std::string faildReport("Open ");
        faildReport += __filePath;
        faildReport += " Failed\n";

        throw std::ios_base::failure(faildReport); 
    } 

    std::getline(readStream, tempString, ':');

    while (readStream)
    {
        WORDS_LIST.push_back(tempString);

        std::getline(readStream, tempString, ':');

        if (*(tempString.begin()) == '\n') { tempString.erase(tempString.begin()); }
    }

    readStream.close();

    return WORDS_LIST.size();
}

void userPlay(char & __ifPlay, bool __ifAgain)
{
    using std::cin, std::cout;

    if (!__ifAgain)
    {
        cout << "Will you play a word game <y/n> ? \n";
        cin  >> __ifPlay;
        std::tolower(__ifPlay);
    }
    else
    {
        cout << "Will you play a word game again <y/n> ?? \n";
        cin  >> __ifPlay;
        std::tolower(__ifPlay);
    }
}

void displayWordList(std::ostream & __os)
{
    std::size_t count = 0;
    __os << "Total String Count = " << WORDS_LIST.size() << '\n';

    if (WORDS_LIST.size() == 0) { __os << "Empty List! " << std::endl; return; }

    for (const std::string & str : WORDS_LIST)
    {
        ++count;
        __os << count << ":\t" << str << '\n';
    }
}