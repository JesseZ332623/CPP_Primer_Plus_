#include "./src/include/CD.h"
#include "./src/include/Classic.h"
#include <windows.h>

void Bravo(const CD & disc);

void Bravo(const CD & disc)
{
    disc.Report(); std::cout << '\n';
}

int main(int argc, char const *argv[])
{
    using std::cout,std::cin,std::endl;

    system("cls");

    CD disc_1("Beatles", "Capitol", 14, 35.5);
    Classic disc_2("Piano Sonata in B flat, Fantasia in C", "Alfred Brendel", "Philips", 2, 57.17);
    CD *p_cd = &disc_1;

    cout << "Using object directly:\n";
    disc_1.Report(); cout << "\n";
    disc_2.Report(); cout << "\n";
    

    cout << "Using type CD * pointer to objects:\n";
    p_cd->Report(); cout << "\n";
    p_cd = &disc_2;
    p_cd->Report(); cout << "\n";

    cout << "Calling a function with a CD reference argument:\n";
    Bravo(disc_1);
    Bravo(disc_2);

    cout << "Testing assignment: ";
    Classic copy = disc_2;
    copy.Report();

    return EXIT_SUCCESS;
}
