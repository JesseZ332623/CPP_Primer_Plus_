#include "./src/include/Port.h"

int main(int argc, char const *argv[])
{
    Port port_box_1("Gallo", BRAND_LIST[1], 20);
    Port port_box_2(port_box_1);
    Port port_box_3 = port_box_2;

    port_box_1 += 100;

    port_box_1.Show(); 

    port_box_1 -= 100;

    cout << port_box_1;
    cout << port_box_2;
    cout << port_box_3;

    return EXIT_SUCCESS;
}
