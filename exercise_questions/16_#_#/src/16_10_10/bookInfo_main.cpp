#include "./bookInfo.h"

using namespace MyLib::MyLoger;

/**
 * @brief 输出用户菜单
*/
void displayMenu(void);

int main(int argc, char const *argv[])
{
    system("cls");

    loger(std::cout, CORRECT, "Program 16.10.10\tBook_Infomation_Storage:\n");

    Book_Infomation_Storage bookLib;
    int displayMode = 0;

    
    loger(std::cout, NOTIFY, "Fill Library Review:\n");
    bookLib.fillLibraryReview();

    displayMenu();
    loger(std::cout, WARNING, "Choose display mode (Enter -1 to EXIT): \n");
    std::cin >> displayMode;
    while (displayMode != -1)
    {
        bookLib.displayBooksLibrary(std::cout, displayMode);

        displayMenu();
        loger(std::cout, WARNING, "Choose display mode (Enter [-1] to EXIT): \n");
        std::cin >> displayMode;
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