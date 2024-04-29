#include <cstdlib>
#include <cstring>

#include <MyLib/myLogerDef.h>
#include <MyLib/myDelay.h>

using namespace MyLib::MyLoger;

int main(int argc, char const *argv[])
{
    system("cls");

    loger(
            std::cout, NOTIFY, 
            "This system can generate up to ", TMP_MAX,
            " temporary names of up to ", L_tmpnam, " Characters.\n"
        );

    char pszName[L_tmpnam] = {0};
    NOTIFY_LOG("Here are ten names: \n");
    
    printSplitLine(35, '-');
    for (int index = 0; index < 10; ++index)
    {
        tmpnam(pszName);

        CORRECT_LOG(std::strcat(pszName, "\n"));

        MyLib::MyDelay::delay(45);
    }
    printSplitLine(35, '-');

    DONE
    
    return EXIT_SUCCESS;
}