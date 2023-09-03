#ifndef _CHANGE_TERMINAL_COLOR_H
#define _CHANGE_TERMINAL_COLOR_H

#include <iostream>

using std::cout, std::endl;

enum Color_Choice
{
    RED = -1,       /*EROOR COLOR*/
    YELLO,          /*WARNING COLOR*/
    GREEN,          /*CURRECT COLOR*/
    WHITE,          /*ORIGINAL COLOR*/
    BLUE,           /*NOTIFY COLOR*/

    /*Other special color*/
    LIGHT_BLUE,
    MAGENTA
};

class Change_Color
{
    private:
        Color_Choice c_choice;
    
    public:
        Change_Color();

        void text_color(Color_Choice c_choice);

        ~Change_Color();
};

#endif



