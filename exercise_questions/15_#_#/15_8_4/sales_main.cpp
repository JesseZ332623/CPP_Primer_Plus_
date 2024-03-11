#include <iostream>
#include <fstream>
#include <typeinfo>
#include <nlohmann/json.hpp>
#include "./include/sales.h"

int main(int argc, char const *argv[])
{
    system("cls");
    using std::cout, std::cin, std::endl;
    using json = nlohmann::json;

    std::ifstream readJsonFileIn2024("./Salary2024.json", std::ios_base::in);
    std::ifstream readJsonFileIn2023("./Salary2023.json", std::ios_base::in);
    json jsonDataIn2024, jsonDataIn2023;
    int monthIndex = 0;
    double salaryIn2023[Sales::MONTH];
    double salaryIn2024[Sales::MONTH];

    if (!readJsonFileIn2024.is_open()) { std::cerr << "Open file ./Salary2024.json Failed\n"; return -1; }
    if (!readJsonFileIn2023.is_open()) { std::cerr << "Open file ./Salary2023.json Failed\n"; return -1;  }
    readJsonFileIn2024 >> jsonDataIn2024;  
    readJsonFileIn2023 >> jsonDataIn2023;

    for (const auto & month : jsonDataIn2024.items())
    {
        salaryIn2023[monthIndex] = month.value();
        ++monthIndex;
    }

    monthIndex = 0;
    for (const auto & month : jsonDataIn2023)
    {
        salaryIn2024[monthIndex] = std::stod(month.dump());
        ++monthIndex;
    }

    Sales salesIn2023_t(2023, salaryIn2023, Sales::MONTH);
    LabledSales salesIn2024_t("Blog Star", 2024, salaryIn2024, Sales::MONTH);

    cout << "First Try Block: \n";
    try
    {
        cout << "Year = " << salesIn2023_t.getYear() << endl;
        
        for (int index = 0; index < Sales::MONTH; ++index)
        {
            cout << salesIn2023_t[index] << ' ';
            if (index % 6 == 5) { cout << endl; }
        }

        cout << "Year = " << salesIn2024_t.getYear() << endl;
        cout << "Label = " << salesIn2024_t.getLabel() << endl;

        for (int index = 0; index < Sales::MONTH + 8; ++index)
        {
            cout << salesIn2024_t[index] << ' ';
            if (index % 6 == 5) { cout << endl; }
        }

        cout << "End of Try Block \n";
    }
    catch (LabledSales::NBadIndex & nBedExcept)
    {
        if (typeid(nBedExcept) != typeid(LabledSales::NBadIndex))
        {
            Sales::BadIndex * bedExcept = dynamic_cast<Sales::BadIndex *>(&nBedExcept);
            cout << bedExcept->what() << " Index = " << bedExcept->getBedIndex() << endl;
        }
        else
        {
            cout << endl << nBedExcept.what();
            cout << "Compnay = " << nBedExcept.getLableIndex() << ' ' << "Bed Index = " << nBedExcept.getBedIndex() << endl;
        }
    }


    readJsonFileIn2023.close();
    readJsonFileIn2024.close();

    return EXIT_SUCCESS;
}
