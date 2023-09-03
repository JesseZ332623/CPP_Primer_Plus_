#include "include/stack.h"

Change_Color color_t;

int main(int argc, char const *argv[])
{
    Stack stack_t;
    char ch;
    Item po;

    /*
        请按 A 来增加货单，
        P 来处理 货单号（PO），
        Q 退出。
    */
    color_t.text_color(BLUE);
    cout << "Please enter [A] to add a purchase order,\n"
         << "[P] to process a PO,\n"
         << "[Q] to Quit." << endl;
    color_t.text_color(LIGHT_BLUE);
    
    while (std::cin >> ch && toupper(ch) != 'Q')
    {
        while (std::cin.get() != '\n') { continue; }

        if (!isalpha(ch))
        {
            cout << '\a';
            continue;
        }
         
        switch (ch)
        {
            case 'A': 
            case 'a':
                color_t.text_color(LIGHT_BLUE);
                cout << "Enter a PO number: ";
                std::cin >> po;
                if (stack_t.isfull())
                {
                    color_t.text_color(RED);
                    cout << "stack already full.\n";
                    color_t.text_color(WHITE);
                }
                else 
                {
                    stack_t.push(po);
                }
                break;
            
            case 'P':
            case 'p':
                if (stack_t.isempty())
                {
                    color_t.text_color(RED);
                    cout << "stack already empty.\n";
                    color_t.text_color(WHITE);
                }
                else
                {
                    stack_t.pop(po);
                    color_t.text_color(GREEN);
                    cout << "PO #" << po << " popped.\n";
                    color_t.text_color(WHITE);
                }
                break;
        }
        color_t.text_color(BLUE);
        cout << "Please enter [A] to add a purchase order,\n"
         << "[P] to process a PO,\n"
         << "[Q] to Quit." << endl; 
    }
    color_t.text_color(BLUE);

    cout << "Have a good time! \n";

    color_t.text_color(WHITE);

    return 0;
}
