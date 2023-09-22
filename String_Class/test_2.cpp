#include "./src/include/_String.h"

using std::cout, std::cin;

int main(int argc, char const *argv[])
{
    _String str("This string will output to file......");
    ofstream file;

    file.open("./test_2.txt");

    file << str << '\n';

    file << sizeof(str);

    file.close();
    

    return EXIT_SUCCESS;
}
