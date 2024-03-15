#include "./include/defs.h"

int main(int argc, char const *argv[])
{
    using std::cin, std::cout, std::endl, std::endl;
    extern std::vector<std::string> WORDS_LIST;

    system("cls");
    std::size_t wordsCount = loadFileInList(LIST_FILEPATH);
    //displayWordList(cout);

    cout << "Load Lexicon complete. \nPath: " << LIST_FILEPATH << '\n';
    cout << "Total words count = " << wordsCount << '\n';

    std::srand(std::time(nullptr));

    char ifPlay = 'n';
    userPlay(ifPlay);

    while (ifPlay !='y' && ifPlay != 'n') 
    { 
        cout << "Error input!\n";
        userPlay(ifPlay);
    }

    while (ifPlay == 'y')
    {
        system("cls");

        /*目标单词，从 WORDS_LIST 中随机挑选*/
        string targetWord = WORDS_LIST.at(std::rand() % wordsCount);

        /*目标单词长度*/
        std::size_t targetLength = targetWord.length();

        /*
            提示字符串，长度和 目标单词 一样，
            如果用户输入正确字母，会根据目标单词的下标填充
        */
        string attmpt(targetLength, '-');

        /*
            错误字符集，不符合正确单词字母的输入都会存于此处
        */
        string badchars;

        /*用户可以猜的次数，当前为 6 次*/
        int userGuessTimes = GUESS_TIMES;

        cout << "Guess my secert word. It has " << targetLength
             << " letters, and you get [" << GUESS_TIMES << "] worng guesses.\n";

        cout << "Your word: " << attmpt << '\n';

        /*
            在 猜词次数未耗尽 以及 
            提示字符串 和 目标单词 不完全相等时，进入循环
        */
        while (userGuessTimes > 0 && attmpt != targetWord)
        {
            char letter;
            cout << "Guess a letter: ";     // 用户输入单个字母
            cin >> letter;

            /*
                若在 错误字符集 或 提示字符串 中都找不到用户输入的单词，
                这用来检查用户前几次是否猜测过这个字母
            */
            if (badchars.find(letter) != string::npos || attmpt.find(letter) != string::npos)
            {
                /*
                    你已经猜过这个（字母）了
                */
                cout << "You already guessed that. Try again!\n";
                continue;
            }

            /*在 目标单词 中搜索用户输入的字母*/
            std::size_t tarPos = targetWord.find(letter);

            /*
                若没找到，find 返回 string::npos，则：
                输出猜错信息，并减少一次猜词机会并往错误字符集中加入这个字符
            */
            if (tarPos == string::npos)
            {
                cout << "Oh bed guess!\n";
                --userGuessTimes;
                badchars += letter;
            }
            /*
                若才对了这个字母，则
                输出正确信息，并修改 提示字符串 指定位置的字符为用户输入的字符
            */
            else
            {
                cout << "Good guess!\n";
                attmpt.at(tarPos) = letter;

                /*
                    由于一个字母在一个单词中可能会出现多次，如：单词 apple 中字母 p 出现两次，
                    所以需要一个循环将这个字母在单词中第一次出现这个字母的位置之后进行搜索，
                    直到找不到这个字母为止。
                */
                tarPos = targetWord.find(letter, tarPos + 1);
                while (tarPos != string::npos)
                {
                    attmpt.at(tarPos) = letter;
                    tarPos = targetWord.find(letter, tarPos + 1);
                }
            }

            /*
                输出目前用户猜的单词状态，比如要猜 apple，用户猜对了字母 p，
                字符串的内容就为 -pp--
            */
            cout << "Your word: " << attmpt << endl;

            /*
                在用户没有完全猜出 目标单词 的情况下
            */
            if (attmpt != targetWord)
            {
                /*
                    在用户有猜错单词的情况下
                */
                if (badchars.length() > 0)
                {
                    /*
                        输出猜错的单词们，
                        以及用户在此次游戏中剩余的猜词次数。
                    */
                    cout << "Bad choice: " << badchars << endl;
                    cout << userGuessTimes << " bed guesses left\n";
                }
            }
            REMOVE_NEWLINE_IN_STDIN
        }
        if (userGuessTimes > 0) { cout << "That's right!\n"; }
        else 
        {
            cout << "Sorry, the word is: " << targetWord << ".\n";
        }

        userPlay(ifPlay, PLAY_AGAIN);

        while (ifPlay !='y' && ifPlay != 'n') 
        { 
            cout << "Error input!\n";
            userPlay(ifPlay, PLAY_AGAIN);
        }

        REMOVE_NEWLINE_IN_STDIN
    }

    cout << "Done. \n";
    
    return EXIT_SUCCESS;
}
