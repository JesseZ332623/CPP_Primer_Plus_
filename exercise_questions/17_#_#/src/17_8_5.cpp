#include <set>
#include <map>
#include <string>
#include <cstring>
#include <cctype>
#include <fstream>

#include <MyLib/myLogerDef.h>
#include <MyLib/cinCheck.h>
#include <MyLib/simpleContainerOperator.h>

using namespace MyLib::MyLoger;
using namespace MyLib::cinCheck;
using namespace MyLib::SimpleContainerOperator;

class Party_Invite
{
    private:
        /**
         * @brief 孩子们的朋友列表，
         *        每一个元素都是一个键值对（std::pair<std::string, std::set<std::string>>）
        */
        std::map<std::string, std::set<std::string>> kidsFriendsList;

        /**
         * @brief 孩子们的朋友列表组去重合并后的列表
        */
        std::set<std::string> mergedUniqueFriendsList;

        /**
         * @brief 要将数据写入文件要用到的文件流
        */
        std::fstream IOFStream;
        std::string defaultFilePath = "..\\data\\17_8_5\\";

        /**
         * @brief 判断一个字符串中有没有数字字符
         * 
         * @param __tempName 孩子的名字
         * 
         * @return 是否有数字字符（true 有数字字符，false 没有）
        */
        bool isNumberStr(std::string & __tempName) const;

        /**
         * @brief 判断 mergedUniqueFriendsList 是否为空。
        */
        bool isUniqueListEmpty(void) const { return mergedUniqueFriendsList.empty(); }

    public:
        std::string returnDefaultPath(void) const { return defaultFilePath; }

        void kidsFriendsInput(void);

        void fileWriteing(const std::string & __kidsName);
        void mergeFileWriting(void);

        void mergeList(void);

        //void cleanContent(void) { kidsFriendsList.clear(); mergedUniqueFriendsList.clear(); }

        void display(void) const;
};

bool Party_Invite::isNumberStr(std::string & __tempName) const
{
    for (const char ch : __tempName)
    {
        if (isdigit(ch)) { return true; }
    }

    return false;
}

void Party_Invite::kidsFriendsInput(void)
{
    while (true)
    {
        std::pair<std::string, std::set<std::string>> tempPair;
        std::string tempFriendName;

        CORRECT_LOG(getCurrentTime() + '\n');
        NOTIFY_LOG("Enter kids name (Press <q> to back): ");
        std::getline(std::cin, tempPair.first);

        if (tempPair.first == "q") { tempPair.first.clear(); return; }

        NOTIFY_LOG("Hello [" + tempPair.first + "]!\nPlease enter your friend list here (Press <q> to end):\n");

        while (std::getline(std::cin, tempFriendName))
        {
            if (this->isNumberStr(tempFriendName)) { continue; }
            if (tempFriendName == "q") { std::cin.clear(); break; }

            tempPair.second.insert(tempFriendName);
        }

        kidsFriendsList.insert(tempPair);
        this->fileWriteing(tempPair.first);

        NOTIFY_LOG("Press <Enter> duplicate to press next kids info (Press <q> to back): ");
        if (std::cin.get() != '\n') { break; }
        eatLine();
    }
}

void Party_Invite::fileWriteing(const std::string & __kidsName)
{
    try
    {
        std::string writePath = (this->defaultFilePath + __kidsName + ".txt");

        if (kidsFriendsList.empty()) 
        { 
            WARNING_LOG("No cotent could write to: " + writePath + '\n'); 
            return; 
        }

        this->IOFStream.open(
            writePath, std::ios_base::out | std::ios_base::trunc
        );

        if (!this->IOFStream.is_open())
        {
            throw std::runtime_error("Couldn't open [" + writePath + "]!\n");
        }

        std::set<std::string> & targetSet = this->kidsFriendsList[__kidsName];

        this->IOFStream << __kidsName + "'s Frieds:\n";
        printSplitLine(45, '-', this->IOFStream);
        for (const std::string & name : targetSet)
        {
            this->IOFStream << name << ' ';
        }

        this->IOFStream << '\n';
        printSplitLine(45, '-', this->IOFStream);

        CORRECT_LOG("Write to [" + writePath + "] Complete!\n");

        this->IOFStream.clear();
        this->IOFStream.close();
    }
    catch (const std::exception & __except) { ERROR_LOG(__except.what()); }
}

void Party_Invite::mergeFileWriting(void)
{
    try
    {
        std::string mergeFilePath = (this->defaultFilePath + "after_merge.txt");

        if (this->isUniqueListEmpty()) 
        { 
            WARNING_LOG("No cotent could write to: " + mergeFilePath + '\n'); 
            return;
        }

        this->IOFStream.open(
            mergeFilePath, std::ios_base::out | std::ios_base::trunc
        );

        this->IOFStream << "After merged, children's friends: \n";
        printSplitLine(45, '-', this->IOFStream);
        for (const std::string & name : this->mergedUniqueFriendsList)
        {   
            this->IOFStream << name << ' ';
        }

        this->IOFStream << '\n';
        printSplitLine(45, '-', this->IOFStream);
        
        CORRECT_LOG("Write to [" + mergeFilePath + "] Complete!\n");

        this->IOFStream.clear();
        this->IOFStream.close();
    }
    catch (const std::exception & __except) { ERROR_LOG(__except.what()); }
}

void Party_Invite::mergeList(void)
{
    for (const auto & tempPair : this->kidsFriendsList)
    {
        for (const std::string & friendName : tempPair.second)
        {
            this->mergedUniqueFriendsList.insert(friendName);
        }
    }
}

void Party_Invite::display(void) const
{
    system("cls");

    printSplitLine(45, '-');
    NOTIFY_LOG("Kid Name\tHis / Her Friends\n");
    printSplitLine(45, '-');

    for (const auto & tempPair : this->kidsFriendsList)
    {
        std::cout << tempPair.first << "\t\t";

        if (tempPair.second.empty()) { ERROR_LOG("No Friends!\n"); continue; }

        showContainerToStream(std::cout, tempPair.second, tempPair.second.size());
    }

    printSplitLine(45, '-');
    NOTIFY_LOG("Merge kidsFriendsList\n");
    printSplitLine(45, '-');

    if (this->isUniqueListEmpty()) 
    { 
        ERROR_LOG("God Damn Jesus Christ! No Unique Data!\n"); 
    }
    else
    {    
        showContainerToStream(
            std::cout, 
            this->mergedUniqueFriendsList, 
            this->mergedUniqueFriendsList.size()
        );
    }

    printSplitLine(45, '-');
}

int main(int argc, char const *argv[])
{
    system("cls");

    Party_Invite kidsParty;
    std::string cleanPathCommand = "del " + kidsParty.returnDefaultPath() + "*";
    
    WARNING_LOG("Delete " + kidsParty.returnDefaultPath() + "*" + " Files\n");

    std::system(cleanPathCommand.c_str());

    kidsParty.kidsFriendsInput();

    kidsParty.mergeList();

    kidsParty.display();
    kidsParty.mergeFileWriting();
    
    DONE
    return EXIT_SUCCESS;
}
