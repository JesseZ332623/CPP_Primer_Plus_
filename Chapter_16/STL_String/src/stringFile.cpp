#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char const *argv[])
{
    std::ifstream fin("./data/toBuy.txt", std::ios_base::in);
    std::string item;
    int count = 0;

    if (!fin.is_open()) { std::cerr << "Can't open file...\n"; }

    std::getline(fin, item, ':');
    while (fin)
    {
        ++count;
        std::cout << count << ":\t" << item << '\n';

        /*
            std::getline() 的第三个参数可以控制从流中读取字符串的方式，
            即以哪个字符为界（默认是 '\n'）
        */
        std::getline(fin, item, ':');

        /*若读取到换行符，就删除掉*/
        if (*(item.begin()) == '\n') { item.erase(item.begin()); }
    }

    fin.close();
    std::cout << "Done.\n";
    
    return EXIT_SUCCESS;
}
