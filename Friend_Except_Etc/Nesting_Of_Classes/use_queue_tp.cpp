#include <iostream>
#include <string>
#include <windows.h>
#include "./link_queue_tp.h"

int main(int argc, char const *argv[])
{
    using string = std::string;

    Link_Queue<string> _cs(5);
    string name;

    printf("Enter your name, You will be served in the order of arrival\n");

    while (!_cs.isfull())
    {
        printf("(Client No. %zd) > Name: ", _cs.count() + 1);
        std::getline(std::cin, name);
        _cs.enqueue(name);

        //while (std::cin.get() != '\n') { continue; }
    }

    printf("Now, The Queue is full, The Processing begins!\n");

#if true

    while (!_cs.isempty())
    {
        _cs.dequeue(name);
        printf("Now Processing: %s\n", name.c_str());
        Sleep(600);
    }

#endif
    
    return EXIT_SUCCESS;
}