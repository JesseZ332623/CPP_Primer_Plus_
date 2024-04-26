#include "./planet.h"

void Planet::dataDesc(void)
{
    using namespace MyLib::MyLoger;

    std::cout.width(50);
    printSplitLine(50, '-');

    loger(
            std::cout, CORRECT,
            std::right, 
            "No.",
            std::setw(17), "Name",
            std::setw(7), "P ",
            std::setw(11), "G", '\n'
        );
    
    std::cout.width(50);
    printSplitLine(50, '-');
}

bool Planet::getPlanetData(void)
{
    using namespace MyLib::MyLoger;

    loger(std::cout, NOTIFY, "Enter planet name (Enter a black line to quit):\n");
    std::cin.get(this->name, 20);

    if (this->name[0] != '\0')
    {
        cleanResidualStream();

planetary_population:
        loger(std::cout, NOTIFY, "Enter planetary population: ");
        std::cin >> this->population;
        if (!checkInputState(std::cin)) { goto planetary_population; }

    
acceleration_of_gravity:
        loger(std::cout, NOTIFY, "Enter acceleration of gravity: ");
        std::cin >> this->g;
        if (!checkInputState(std::cin)) { goto acceleration_of_gravity; }

        cleanResidualStream();

        return true;
    }

    return false;
} 

std::ostream & operator<<(std::ostream & __os, const __Planet & __pl)
{
    using namespace MyLib::MyLoger;

    loger(
            __os, ORIGINAL,
            std::fixed, std::right, 
            std::setw(20), __pl.name, ": ",
            std::setprecision(0), std::setw(12), __pl.population,
            std::setprecision(2), std::setw(6), __pl.g, '\n'
        );

    return __os;
}

void PlanetInfo_Operator::readPlanetData(void)
{
    using namespace MyLib::MyLoger;

    using MyLib::MyDelay::delay;
    using std::ios_base;

    readStream.open(this->dataFilePath, ios_base::binary | ios_base::in);
    std::size_t planetCount = 0ULL;

    if (readStream.is_open())
    {
        loger(
                std::cout, NOTIFY,
                "Here are the contence of file: ", this->dataFilePath, '\n'
        );

        this->planet.dataDesc();
        while (readStream.read(reinterpret_cast<char *>(&this->planet), sizeof(Planet)))
        {
            std::cout << ++planetCount << this->planet;
            this->planet.clearData();
            delay(45);
        }
        printSplitLine(50, '-');

        readStream.clear();
        readStream.close();
    }
}

void PlanetInfo_Operator::addNewPlanetData(void)
{
    using std::ios_base;
    using namespace MyLib::MyLoger;

    writeStream.open(this->dataFilePath, ios_base::in | ios_base::app | ios_base::binary);

    if (!writeStream.is_open()) 
    {
        loger(std::cerr, ERROR, "Could't open file: ", this->dataFilePath, '\n');
        std::exit(EXIT_FAILURE);
    }

    while (this->planet.getPlanetData())
    {
        writeStream.write(reinterpret_cast<char *>(&this->planet), sizeof(Planet));
        this->planet.clearData();
    }

    writeStream.clear();
    writeStream.close();
}

void PlanetInfo_Operator::showRevisedPlanetData(void)
{
    using std::ios_base;
    using MyLib::MyDelay::delay;

    using namespace MyLib::MyLoger;


    readStream.open(this->dataFilePath, ios_base::binary | ios_base::in);

    std::size_t planetCount = 0ULL;

    if (readStream.is_open())
    {
        loger(
                std::cout, NOTIFY,
                "Here are the contence of file: ", this->dataFilePath, '\n'
        );

        this->planet.dataDesc();
        while (readStream.read(reinterpret_cast<char *>(&this->planet), sizeof(Planet)))
        {
            std::cout << ++planetCount << this->planet;
            this->planet.clearData();

            delay(45);
        }
        printSplitLine(50, '-');

        readStream.clear();
        readStream.close();
    }

}

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
