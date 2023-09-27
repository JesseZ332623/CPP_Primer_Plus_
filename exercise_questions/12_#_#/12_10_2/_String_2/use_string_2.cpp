#include "./src/include/_String.h"

int main(int argc, char const *argv[])
{
    _String str_1 = "AAAAAAAAAAAAAAAAA";
    _String str_2 = "bbbbbbbbbbbbb";
    _String str_3 = "AhDGdfjgskjdglLLLL";

    std::cout << "The char L appear " << str_3.appear_times('\0') << " times..\n";

    str_1.string_low();
    str_2.string_upper();
    str_3.string_low();

    std::cout << str_1 << '\n'
              << str_2 << '\n'
              << str_3 << '\n';
    return 0;
    
}
