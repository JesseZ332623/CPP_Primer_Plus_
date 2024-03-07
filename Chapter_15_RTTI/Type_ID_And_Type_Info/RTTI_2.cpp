#include "./include/RTTI_2.h"

int main(int argc, char const *argv[])
{
    system("cls");
    
    std::srand(time(nullptr));

    Grand * pg = nullptr;
    Superb * ps = nullptr;

    for (int index = 0; index < 5; ++index)
    {
        pg = getOne();
        TypeInfo typeInfo(typeid(*pg).name(), typeid(*pg).hash_code());
        std::cout << "Now Processing " << typeInfo << ". \n";
    }

    return EXIT_SUCCESS;
}
