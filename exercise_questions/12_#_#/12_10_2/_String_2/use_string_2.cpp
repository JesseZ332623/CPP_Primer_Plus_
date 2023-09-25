#include "./src/include/_String.h"

int main(int argc, char const *argv[])
{
    _String str_1 = "AA";
    _String str_2 = "BB";

    //_String s3;
    str_1 += str_2;

    std::cout << str_1 << '\n';
    std::cout << str_2 << '\n';

    return 0;
}
