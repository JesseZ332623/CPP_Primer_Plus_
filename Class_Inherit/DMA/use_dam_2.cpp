#include "./dma.h"

int main(int argc, char const *argv[])
{
    using std::cout, std::endl;

    Base_DMA shirt("Portabelly", 8);
    Lack_DMA balloon("Blimpo", 4, "Red");
    Has_DMA map("Buffalo Keys", 5, "Mercator");

    cout << shirt << endl;
    cout << balloon << endl;
    cout << map << endl;

    Lack_DMA balloon_02(balloon);
    cout << "The result of balloon copy...." << endl;
    cout << balloon << endl;

    Has_DMA map_02 = map;
    cout << "Result of Has_DMA assignment: \n";
    cout << map_02 << endl;
    
    return EXIT_SUCCESS;
}
