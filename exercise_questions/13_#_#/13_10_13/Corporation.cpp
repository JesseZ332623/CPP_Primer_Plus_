#include "Corporation.h"

int main(int argc, char const *argv[])
{
    Corporation *ph = new Public_Corporation(100);

    std::cout << ph->head();

    delete ph;

    return 0;
}
