#include "../include/planet.h"

int main(int argc, char const *argv[])
{
    using namespace MyLib::MyLoger;

    system("cls");

    Planet planet;

    PlanetInfo_Operator planetOp;

    planetOp.readPlanetData();
    planetOp.addNewPlanetData();
    planetOp.showRevisedPlanetData();

    DONE
    return EXIT_SUCCESS;
}
