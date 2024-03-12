#include "./include/RTTI_2.h"

int main(int argc, char const *argv[])
{
    system("cls");
    
    std::srand(time(nullptr));

    Grand * pg = nullptr;
    Superb * ps = nullptr;
    Magnificent * pd = nullptr;

    for (int index = 0; index < 5; ++index)
    {
        pg = getOne();
        TypeInfo typeInfo(typeid(*pg).name(), typeid(*pg).hash_code());
        std::cout << "Now Processing " << typeInfo << ". \n";

        if ((typeid(*pg) == typeid(Grand)))
        {
            pg->Speak();
        }

        if ((ps = dynamic_cast<Superb *>(pg)))
        {
            ps->Speak();
            ps->Say();
        }

        puts("---------------------------------------------------------");

        delete pg;
    }

    pg = nullptr;
    ps = nullptr;
    pd = nullptr;

    return EXIT_SUCCESS;
}
