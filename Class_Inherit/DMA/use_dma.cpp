#include "./dma.h"

int main(int argc, char const *argv[])
{
    Base_DMA base_dma("Blue Achive", 10);
    Lack_DMA lack_dma(base_dma, "Blue");
    Has_DMA has_dma(base_dma, "Game");

    std::cout << base_dma << std::endl;

    Base_DMA _move_copy_base(std::move(base_dma));

    std::cout << lack_dma << std::endl;
    std::cout << has_dma << std::endl;
    std::cout << _move_copy_base;

    base_dma = Base_DMA("Ganshin Impact", 9);
    std::cout << base_dma;

    return EXIT_SUCCESS;
}
