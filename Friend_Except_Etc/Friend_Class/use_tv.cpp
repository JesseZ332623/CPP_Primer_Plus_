/*基于上述编写一个交互程序。*/

#include "./tv.h"

/*遥控器的功能表*/
void remote_function();

void remote_function()
{
    using std::cout;
    cout << "-------------------------------------" << '\n';
    cout << "1.ON / OFF" << '\n';
    cout << "2.Channal UP" << "\t" << "3.Channal Down" << '\n';
    cout << "4.Volume UP" << "\t" << "5.Volume Down" << '\n';
    cout << "6.Set Channal" << "\t" << "7.Set Mode" << '\n';
    cout << "8.Set Input" << "\t" << "9.Display" << '\n';
    cout << "0.EXIT" << '\n';
    cout << "-------------------------------------" << '\n';
}



int main(int argc, char const *argv[])
{
    using std::cout, std::cin;

    system("cls");

    int choice = 0;
    int channal_val = 0;

    /*一台电视机*/
    Television S4_02;

    /*用于操控电视机的遥控器*/
    Remote S4_02_Remote;

    /*输出遥控器的功能表*/
    remote_function();
    cout << "> "; cin >> choice;

    while (true)
    {
        switch (choice)
        {
            case 1: 
                system("cls");

                S4_02_Remote.On_Off(S4_02);
                if (!(S4_02.is_on()))
                {
                    cout << "Close Television\n";
                    remote_function();
                    cout << "> "; cin >> choice;
                    break;
                }
                cout << "Open Television" << '\n';
                remote_function();
                cout << "> "; cin >> choice;
                break;

            case 2:
                system("cls");
                if (!(S4_02.is_on())) 
                { 
                    S4_02.display_settings(); 
                    remote_function();
                    cout << "> "; cin >> choice;
                    break;
                }
                S4_02_Remote.channal_up(S4_02);
                cout << "Channal + 1" << '\n';
                remote_function();
                cout << "> "; cin >> choice;
                break;

            case 3: 
                system("cls");
                if (!(S4_02.is_on())) 
                { 
                    S4_02.display_settings(); 
                    remote_function();
                    cout << "> "; cin >> choice;
                    break;
                }
                S4_02_Remote.channal_down(S4_02);
                cout << "Channal - 1" << '\n';
                remote_function();
                cout << "> "; cin >> choice;
                break;

            case 4: 
                system("cls");
                if (!(S4_02.is_on())) 
                { 
                    S4_02.display_settings(); 
                    remote_function();
                    cout << "> "; cin >> choice;
                    break;
                }
                else if (S4_02_Remote.volume_up(S4_02))
                {
                    cout << "Volume + 1" << '\n';
                    remote_function();
                    cout << "> "; cin >> choice;
                    break;
                }
                cout << "Volume is Max Value (20)." << '\n';
                remote_function();
                cout << "> "; cin >> choice;
                break;

            case 5: 
                system("cls");
                if (!(S4_02.is_on())) 
                { 
                    S4_02.display_settings(); 
                    remote_function();
                    cout << "> "; cin >> choice;
                    break;
                }
                else if (S4_02_Remote.volume_down(S4_02)) 
                {
                    cout << "Volume - 1" << '\n';
                    remote_function();
                    cout << "> "; cin >> choice;
                    break;
                }
                cout << "Volume is Min Value (0)" << '\n';
                remote_function();
                cout << "> "; cin >> choice;
                break;

            case 6: 
                system("cls");

                if (!(S4_02.is_on())) 
                { 
                    S4_02.display_settings(); 
                    remote_function();
                    cout << "> "; cin >> choice;
                    break;
                }

                cout << "> Enter Channal: "; cin >> channal_val;

                while (!(S4_02_Remote.set_channal(S4_02, channal_val)))
                {
                    cout << "Error Channal...\n";
                    cout << "> Enter Channal: "; cin >> channal_val;
                }
                cout << "Set Channal to " << channal_val << '\n';
                remote_function();
                cout << "> "; cin >> choice;
                break;

            case 7: 
                system("cls");

                if (!(S4_02.is_on())) 
                { 
                    S4_02.display_settings(); 
                    remote_function();
                    cout << "> "; cin >> choice;
                    break;
                }

                S4_02_Remote.set_mode(S4_02);

                cout << "Transmission Mode Switch." << '\n';
                remote_function();
                cout << "> "; cin >> choice;
                break;

            case 8: 
                system("cls");

                if (!(S4_02.is_on())) 
                { 
                    S4_02.display_settings(); 
                    remote_function();
                    cout << "> "; cin >> choice;
                    break;
                }
                cout << "Input Mode Switch." << '\n';
                remote_function();
                cout << "> "; cin >> choice;
            break;

            case 9: 
                system("cls");
                S4_02.display_settings();
                remote_function();
                cout << "> "; cin >> choice;
                break;

            case 0:
                system("cls");
                cout << "Colose Television \n";
                S4_02_Remote.On_Off(S4_02);

                cout << "EXIT SYSTEM.\n";
                std::exit(EXIT_SUCCESS);
                break;

            default: 
                cout << "Error Choice." << '\n';
                remote_function();
                cout << "> "; cin >> choice;
        }
        while (cin.get() != '\n') { continue; }
    }
    
    return EXIT_SUCCESS;
}
