#include "./bookInfo.h"

#include <limits>

using namespace MyLib::MyLoger;

/**
 * @brief 输出显示模式菜单。
*/
void displayMenu(void);

/**
 * @brief 输出输入模式菜单，有 2 个选项：
 * @brief - 继续输入数据
 * @brief - 清空整个容器重新输入数据
*/
void fillReviewMenu(void);

/**
 * @brief 检测输入流的状态，防止用户输入非数字字符导致程序错乱。
 * 
 * @param __in C++ 标准输入流
 * 
 * @return non-return
*/
void checkInputState(std::istream & __in);

int main(int argc, char const *argv[])
{
    system("cls");

    loger(std::cout, CORRECT, "Program 16.10.10\nBook_Infomation_Storage\n");

    Book_Infomation_Storage bookLib;
    int displayMode = 0;
    int fillReviewMode = 0;
    //bool exitSystem = false;

    while (fillReviewMode != -1)
    {
        loger(std::cout, NOTIFY, "Fill Library Review:\n");
        bookLib.fillLibraryReview();

        displayMenu();
        loger(std::cout, WARNING, "Choose display mode (Enter -1 to EXIT): \n");
        std::cin >> displayMode;
        checkInputState(std::cin);
        while (displayMode != -1)
        {
            bookLib.displayBooksLibrary(std::cout, displayMode);

            displayMenu();
            loger(std::cout, WARNING, "Choose display mode (Enter [-1] to EXIT): \n");
            std::cin >> displayMode;
            checkInputState(std::cin);
        }
        
        system("cls");
        fillReviewMenu();
        loger(std::cout, WARNING, "Choose fill review mode (Enter -1 to EXIT): \n");
        std::cin >> fillReviewMode;
        checkInputState(std::cin);
        while (std::cin.get() != '\n') { continue; } 

        if (!fillReviewMode) {  bookLib.clearCointer(); }
    }

    DONE;
    return EXIT_SUCCESS;
}

void displayMenu(void)
{
    printSplitLine(65, '-');
    loger(
            std::cout, NOTIFY,
            "0. Original vector order\t",
            "1. Alphabetical order\n",
            "2. Order of ratings (Ascendng)\t",
            "3. Order of ratings (Descendng)\n",
            "4. Order of price (Ascendng)\t",
            "5. Order of price (Descendng)\n",
            "-1. Exit.\n"
         );
    printSplitLine(65, '-');
}

void fillReviewMenu(void)
{
    printSplitLine(35, '-');
    loger(
            std::cout, NOTIFY,
            "0. Clear container for new fill\n",
            "1. Continue input data\n"
    );
    printSplitLine(35, '-');
}

void checkInputState(std::istream & __in)
{
    if (__in.fail())
    {
        __in.clear();
        __in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        ERROR_LOG("Invalid input! Please only enter intenger.\n");

        MyLib::MyDelay::delay(1000);
    }
}