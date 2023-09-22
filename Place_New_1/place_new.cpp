#include "./place_new.h"

int main(int argc, char const *argv[])
{
    char *_buffer = new char[BUFFER];

    Place_New *pc_1, *pc_2;

    pc_1 = new (_buffer)Place_New;
    pc_2 = new (_buffer)Place_New("Heap_1", 20);

    cout << pc_1;
    pc_1->show();

    delete _buffer;

    delete pc_1;
    delete pc_2;
    
    return EXIT_SUCCESS;
}
