#include "./src/include/Port.h"
#include "./src/include/Vintage_Port.h"

/*打印 BRAND_LIST 和 NICKNAME_LIST*/
void print_list();

void print_list()
{
    std::cout << "Brand List: " << std::endl;
    for (int index = 0; index < BRAND_TYPES; ++index)
    {
        std::cout << BRAND_LIST[index] << std::endl;
    }
    std::cout << "Nickname List: " << std::endl;
    for (int index = 0; index < NICKNAME_TYPES; ++index)
    {
        std::cout << NICKNAME_LIST[index] << std::endl;
    }
}


int main(int argc, char const *argv[])
{
#if true
    Port port_box_1("Gallo", BRAND_LIST[1], 20);
    
    Vintage_Port vintage_box_1("Gallo", 100, NICKNAME_LIST[1], 10);
    Vintage_Port vintage_box_2 = vintage_box_1;
    Vintage_Port vintage_box_3 = Vintage_Port(vintage_box_1);

    //vintage_box_1.Show();

    cout << vintage_box_1 << endl;
    cout << vintage_box_2 << endl;
    cout << vintage_box_3 << endl;
#endif


    return EXIT_SUCCESS;
}
