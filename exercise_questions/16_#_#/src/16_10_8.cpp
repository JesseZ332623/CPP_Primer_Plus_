#include <set>
#include <string>
#include <cctype>
#include <algorithm>

#include <MyLib/myLib.h>

using namespace MyLib::MyLoger;
using namespace MyLib::SimpleContainerOperator;

class Party_Invite
{
    private:
        std::set<std::string> matFriendsList;
        std::set<std::string> patFriendsList;

        std::set<std::string> mergedUniqueList;

        bool isNumberStr(std::string & __tempName);
        void isContainerEmpty(void);

    public:
        void matInput(void);
        void patInput(void);

        void mergeList(void);

        void cleanContent(void) { matFriendsList.clear(); patFriendsList.clear(); mergedUniqueList.clear(); }

        void display(void);
};

bool Party_Invite::isNumberStr(std::string & __tempName)
{
    for (const char ch : __tempName)
    {
        if (isdigit(ch)) { return true; }
    }

    return false;
}

void Party_Invite::isContainerEmpty(void)
{
    if (this->matFriendsList.empty()) { ERROR_LOG("No mat's friends can display....\n"); }

    if (this->patFriendsList.empty()) { ERROR_LOG("No pat's friends can display....\n"); }

    if (this->mergedUniqueList.empty()) { ERROR_LOG("After merged, there are no message to display.\n"); }
}

void Party_Invite::matInput(void)
{
    std::string tempNameStr;

    loger(std::cout, CORRECT, getCurrentTime(), '\n');
    loger(std::cout, NOTIFY, "Hello mat! Please enter your friend list here (Press q to back):\n");

    while (std::cin >> tempNameStr && tempNameStr != "q")
    {
        if (isNumberStr(tempNameStr)) { continue; }

        this->matFriendsList.insert(tempNameStr);
        tempNameStr.clear();
    }
}

void Party_Invite::patInput(void)
{
    std::string tempNameStr;

    loger(std::cout, CORRECT, getCurrentTime(), '\n');
    loger(std::cout, NOTIFY, "Hello pat! Please enter your friend list here (Press q to back):\n");

    while (std::cin >> tempNameStr && tempNameStr != "q")
    {
        if (isNumberStr(tempNameStr)) { continue; }

        this->patFriendsList.insert(tempNameStr);
        tempNameStr.clear();
    }
}

void Party_Invite::mergeList(void)
{
    this->mergedUniqueList.insert(this->matFriendsList.begin(), this->matFriendsList.end());
    this->mergedUniqueList.insert(this->patFriendsList.begin(), this->patFriendsList.end());
}

void Party_Invite::display(void)
{
    system("cls");

    isContainerEmpty();

    loger(std::cout, NOTIFY, "Mat's friend list: \n");
    showContainerToStream(std::cout, this->matFriendsList);
    printSplitLine(35, '-');

    loger(std::cout, NOTIFY, "Pat's friend list: \n");
    showContainerToStream(std::cout, this->patFriendsList);
    printSplitLine(35, '-');
    
    loger(std::cout, NOTIFY, "After merged.\n");
    showContainerToStream(std::cout, this->mergedUniqueList);
    printSplitLine(35, '-');
}

int main(int argc, char const *argv[])
{
    system("cls");

    Party_Invite party;

    while (true)
    {
        system("cls");
        
        party.matInput();
        party.patInput();
        party.mergeList();
        party.display();
        party.cleanContent();

        while (std::cin.get() != '\n') { continue; }

        loger(std::cout, NOTIFY, "Press ENTER to next invite:");
        std::cin.get();
    }
    
    DONE
    return EXIT_SUCCESS;
}
