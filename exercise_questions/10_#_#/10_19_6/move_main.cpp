#include "move_def.h"

int main(int argc, char const *argv[])
{
    Move *move_1 = new Move(10, 11);
    Move *move_2 = new Move(14, 21);

    move_1->show_move();
    move_2->show_move();

    Move move_3 = move_1->add(*move_2);

    move_3.show_move();

    delete move_1;
    delete move_2;

    return EXIT_SUCCESS;
}
