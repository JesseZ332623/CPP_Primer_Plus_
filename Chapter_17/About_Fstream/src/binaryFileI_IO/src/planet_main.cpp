#include "../include/planet.h"

int main(int argc, char const *argv[])
{
    using namespace MyLib::MyLoger;

    system("cls");

    PlanetInfo_Operator planetOp;

    planetOp.showRevisedPlanetData();

    while (true)
    {
        char userChoice;
        planetOp.showOperatorMenu();

        Planet::inputAndCheck(
                                std::cin, userChoice, 
                                "Enter your choice: ", "Invalid input! Please only enter correct number!\n",
                                [&userChoice]() -> bool { return (userChoice <= 51 && userChoice >= 48); }
        );

        switch(userChoice)
        {
            case PlanetInfo_Operator::ADD_NEW_DATA:
                planetOp.addNewPlanetData();
                planetOp.showRevisedPlanetData();
                break;

            case PlanetInfo_Operator::MODIFY_DATA:
                planetOp.modifyPlanetData();
                planetOp.showRevisedPlanetData();
                break;

            case PlanetInfo_Operator::SHOW_DATA:
                system("cls");
                planetOp.showRevisedPlanetData();
                break;

            case PlanetInfo_Operator::EXIT:
                DONE
                std::exit(EXIT_SUCCESS);

            default:
                break;
        };

        //cleanResidualStream();
    }

    DONE
    return EXIT_SUCCESS;
}
