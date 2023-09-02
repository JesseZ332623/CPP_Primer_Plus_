#include "new_def.h"

char buffer[buffer_size];

void show_chaff(const Chaff & chaffs)
{
    std::cout << "dorss: " << chaffs.dross << std::endl;
    std::cout << "slag: " << chaffs.slag << std::endl;
}

int main(int argc, char const *argv[])
{
    Chaff *chaff = new (buffer) Chaff[2];

    strcpy(chaff[0].dross, "Jesse_EC");
    chaff[0].slag = 100;

    strcpy(chaff[1].dross, "Mike");
    chaff[1].slag = 47;

    for (int index = 0; index < 2; ++index)
    {
        show_chaff(chaff[index]);
        std::cout.put('\n');
    }

    return EXIT_SUCCESS;
}
