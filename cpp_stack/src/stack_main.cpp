#include "include/stack.h"

const Item stack_len = 10;
Change_Color color_t;

int main(int argc, char const *argv[])
{
    Item stack_data[stack_len] =
    {
        12, 7564, 763, 267686, 24561, 
        111, 35478, 657, 24565, 78
    };
    Stack *stack = new Stack;

    for (int index = 0; index < stack_len; ++index)
    {
        stack->push(stack_data[index]);
    }

    if (stack->isfull())
    {
        color_t.text_color(GREEN);
        std::cout << "The stack is full.\n";  
    }

    stack->pop(stack_data[stack_len - 1]);

    if (stack->isfull())
    {
        color_t.text_color(GREEN);
        std::cout << "The stack is full.\n";   
    }
    else 
    {
        color_t.text_color(YELLO);
        std::cout << "The stack is not full"
                  << "Stack size: " 
                  << stack->show_stack_top()
                  << std::endl;
    }

    color_t.text_color(LIGHT_BLUE);
    std::cout << "stackdata_info: " << std::endl;
    stack->show_data();
    color_t.text_color(WHITE);

    delete stack;

    return EXIT_SUCCESS;
}
