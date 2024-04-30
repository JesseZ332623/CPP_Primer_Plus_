#include <iostream>

int main(int argc, char const *argv[])
{
    char ch1, ch2;
    int ct1 = 0, ct2 = 0;

    std::cin >> ch1;
    while (ch1 != 'q')
    {
        ct1++;
        std::cin >> ch1;
    }

    std::cin.get(ch2);
    while (ch2 != 'q')
    {
        ct2++;
        std::cin.get(ch2);
    }

    std::cout << "ct1 = " << ct1 << "; ct2 = " << ct2 << "\n";

    return EXIT_SUCCESS;
}
