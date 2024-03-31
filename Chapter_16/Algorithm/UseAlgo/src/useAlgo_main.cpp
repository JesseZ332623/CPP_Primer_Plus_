#include "../include/useAlgo.h"

int main(int argc, char const *argv[])
{
    system("cls");

    using namespace MyLib::SimpleContainerOperator;
    using namespace MyLib::MyLog;
    using MyLib::MyDelay::delay;

    std::string userExit;
    std::vector<std::string>    wordsArray;
    std::set<std::string>       wordsSet;
    std::map<std::string, int>  wordsMap;

    wordsUserInput(wordsArray);

    while (true)
    {
        while (std::cin.get() != '\n') { continue; }

        getAlphabeticalOrderSet(wordsArray, wordsSet);
        getAppearTimesOfEveryWords(wordsArray, wordsSet, wordsMap);

        log(std::cout, CORRECT, "Show Result: \n");

        log(std::cout, NOTIFY, "1. A list of words arranged in input order: \n");
        showContainerToStream(std::cout, wordsArray, true);
        printSplitLine(35, '-');

        log(std::cout, NOTIFY, "2. A set of words arranged in alphabetical order: \n");
        showContainerToStream(std::cout, wordsSet, true);
        printSplitLine(35, '-');

        log(std::cout, NOTIFY, "3. A list record everyWords appear times: \n");
        log(std::cout, CORRECT, std::left, "Words\t\t  AppearTimes\n");
        std::for_each(
                        wordsMap.cbegin(), wordsMap.cend(), 
                        [](const std::pair<std::string, int> & __pair) { std::cout << __pair; delay(65); }
                    );
        printSplitLine(35, '-');

        log(std::cout, WARNING, "Again? Press `y` to continue Or Press `.exit` to EXIT > ");
        std::getline(std::cin, userExit);

        if (userExit == ".exit") { break; }

        wordsArray.clear();
        wordsSet.clear();
        wordsMap.clear();

        wordsUserInput(wordsArray);
    }

    log(std::cout, CORRECT,"Done.\n");

    return EXIT_SUCCESS;
}