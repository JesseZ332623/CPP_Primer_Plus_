#include "change_terminal_color.h"

Change_Color::Change_Color() {}

void Change_Color::text_color(Color_Choice c_choice)
{
    using std::cout;

    switch(c_choice)
    {
        case RED:
            cout << "\033[31m";
            break;
        
        case YELLO:
            cout << "\033[33m";
            break;
        
        case GREEN:
            cout << "\033[32m";
            break;

        case WHITE:
            cout<< "\033[0m";
            break;

        /*Other special color*/
        case BLUE:
            cout << "\033[34m";
            break;

        case LIGHT_BLUE:
            cout << "\033[36m";
            break;
        
        case MAGENTA:
            cout << "\033[35m";
            break; 

        default:
            break;
    }
}

Change_Color::~Change_Color() {}



