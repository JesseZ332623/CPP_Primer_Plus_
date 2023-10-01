#include "./tab_tenn_1.h"
#include <windows.h>

using std::cout, std::endl;

void show_player_info(Table_Tennis_Player & player)
{
    player.Name();
    if (player.Has_Table()) 
    {
        cout << ": has table" << endl;
    }
    else
    {
        cout << ": has't table" << endl;
    }
}

void show_player_info(Rated_Player & rate_player)
{
    rate_player.Name();
    if (rate_player.Has_Table()) 
    {
        cout << ": has table" << ' ';
        cout << "Rating: " << rate_player.Get_Rating() << endl;
    }
    else
    {
        cout << ": has't table" << ' ';
        cout << "Rating: " << rate_player.Get_Rating() << endl;
    }
}

int main(int argc, char const *argv[])
{
    system("cls");

    Table_Tennis_Player player_01("Tara", "Boomdea", false);

    /*先创建基类，再创建派生类*/
    Rated_Player rate_player_01(1140, "Mallory", "Duck", true);

    /*创建基类时，把 player_01 对象的数据拷贝给基类对象*/
    Rated_Player rate_player_02(1212, player_01);

    show_player_info(player_01);
    show_player_info(rate_player_01);
    show_player_info(rate_player_02);
    
    return EXIT_SUCCESS;
}