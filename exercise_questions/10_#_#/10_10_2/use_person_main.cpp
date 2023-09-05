#include "person.h"

int main(int argc, char const *argv[])
{
    Person one;
    Person two("Smythecraft");
    Person three("Dimwiddy", "Sam");

    /*use defult constructor*/
    one.Show();
    one.Formal_Show();

    two.Show();
    two.Formal_Show();

    three.Show();
    three.Formal_Show();

    return EXIT_SUCCESS;
}
