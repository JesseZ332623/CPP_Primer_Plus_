#include "../include/planet.h"

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

    auto trueForever = [](){ return true; };

    loger(std::cout, NOTIFY, "Enter planet name (Enter a black line to quit):\n");

    cleanResidualStream();
    std::cin.get(this->name, 20);

    if (this->name[0] != '\0')
    {
        cleanResidualStream();

        inputAndCheck(
                        std::cin, this->population, 
                        "Enter planetary population: ", 
                        "Invalid input! Please only enter number!\n",
                        trueForever
                    );

        inputAndCheck(
                        std::cin, this->g, 
                        "Enter acceleration of gravity: ", 
                        "Invalid input! Please only enter number!\n",
                        trueForever
                    );

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

void PlanetInfo_Operator::showOperatorMenu(void)
{
    using namespace MyLib::MyLoger;

    printSplitLine(50, '-');
    loger(
        std::cout, NOTIFY,
        "1. Add new planet data to the file end.\n",
        "2. Modify planet data (Data Path = ", this->dataFilePath, ")\n",
        "3. Show data from ", this->dataFilePath, "\n",
        "0. EXIT\n"
    );
    printSplitLine(50, '-');
}

void PlanetInfo_Operator::readPlanetData(void)
{
    using namespace MyLib::MyLoger;

    using MyLib::MyDelay::delay;
    using std::ios_base;

    IOStream.open(this->dataFilePath, ios_base::binary | ios_base::in);

    if (IOStream.is_open())
    {
        this->planetRecordCount = 0ULL;

        loger(
                std::cout, NOTIFY,
                "Here are the contence of file: ", this->dataFilePath, '\n'
        );

        this->planet.dataDesc();
        while (IOStream.read(reinterpret_cast<char *>(&this->planet), sizeof(Planet)))
        {
            std::cout << ++planetRecordCount << this->planet;
            this->planet.clearData();
            delay(45);
        }
        printSplitLine(50, '-');
    }

    IOStream.clear();
    IOStream.close();
}

void PlanetInfo_Operator::addNewPlanetData(void)
{
    using std::ios_base;
    using namespace MyLib::MyLoger;

    IOStream.open(this->dataFilePath, ios_base::in | ios_base::app | ios_base::binary);

    if (!IOStream.is_open()) 
    {
        loger(std::cerr, ERROR, "Could't open file: ", this->dataFilePath, '\n');
        std::exit(EXIT_FAILURE);
    }

    while (this->planet.getPlanetData())
    {
        IOStream.write(reinterpret_cast<char *>(&this->planet), sizeof(Planet));
        this->planet.clearData();
    }

    IOStream.clear();
    IOStream.close();
}

void PlanetInfo_Operator::modifyPlanetData(void)
{
    using namespace MyLib::MyLoger;
    using MyLib::MyDelay::delay;
    using std::ios_base;

    long int record = 0L;
    std::streampos IOPos;

    /*
        确定要修改数据在文件内的索引值（不得小于 0 或 大于文件内的最大索引值）
    */
    while (record <= 0 || record > this->planetRecordCount)
    {
        this->showRevisedPlanetData();

        loger(
                std::cout, NOTIFY, 
                "Which record do you want to modify? (Current record = ", 
                this->planetRecordCount, ")\n"
            );

        std::cin >> record;
        cleanResidualStream();

        if (record <= 0 || record > this->planetRecordCount)
        {
            loger(
                std::cout, ERROR, 
                "INVALID RECORD! (Current record = ", 
                this->planetRecordCount, ")\n"
            );

            delay(1000);
            system("cls");
            continue;
        }

        /*
            确定数据索引后以读写和二进制模式打开文件
        */
        IOStream.open(
                    this->dataFilePath, 
                    ios_base::in | ios_base::out | ios_base::binary
                );

        /*确定要修改数据头在文件的具体字节数*/
        IOPos = (record - 1) * sizeof(Planet);

        /*偏移写指针*/
        IOStream.seekg(IOPos);

        /*这里用于检测越界读写的情况，但是应该不会出现*/
        if (IOStream.fail()) 
        { 
            ERROR_LOG("Error on attempted seek.\n"); 
            IOStream.seekg(ios_base::beg); 
            continue; 
        }
    }

    /*读取修改前的数据用于提示用户*/
    IOStream.read(reinterpret_cast<char *>(&this->planet), sizeof(Planet));
    loger(std::cout, NOTIFY, "Your selection: ", record);
    std::cout << this->planet;

    if (IOStream.eof()) { IOStream.clear(); }

    /*将数据从标准输入写入一个临时的 planet 对象*/
    this->planet.clearData();
    this->planet.getPlanetData();

    /*偏移写指针到指定位置*/
    IOStream.seekp(IOPos);

    /*写入并刷新*/
    IOStream.write(reinterpret_cast<char *>(&this->planet), sizeof(Planet)) << std::flush;

    if (IOStream.fail())
    {
        ERROR_LOG("Error on attempted seek.\n"); 
        IOStream.seekg(ios_base::beg); 
    }

    IOStream.clear();
    IOStream.close();
}

void PlanetInfo_Operator::showRevisedPlanetData(void)
{
    using std::ios_base;
    using MyLib::MyDelay::delay;

    using namespace MyLib::MyLoger;


    IOStream.open(this->dataFilePath, ios_base::binary | ios_base::in);

    if (IOStream.is_open())
    {
        this->planetRecordCount = 0ULL;

        loger(
                std::cout, NOTIFY,
                "Here are the content of file: ", this->dataFilePath, '\n'
        );

        this->planet.dataDesc();
        while (IOStream.read(reinterpret_cast<char *>(&this->planet), sizeof(Planet)))
        {
            std::cout << ++planetRecordCount << this->planet;
            this->planet.clearData();

            delay(45);
        }
        printSplitLine(50, '-');
    }
    
    //cleanResidualStream();
    IOStream.clear();
    IOStream.close();
}