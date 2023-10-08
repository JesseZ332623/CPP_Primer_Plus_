#include "./include/brass_account.h"
#include <windows.h>
//#include <type_traits>

int main(int argc, char const *argv[])
{
    using std::cout;
    using std::endl;

    system("cls");

    Brass_Account piggy("Pappa Pig", "331081200403455687", 4000.00);
    Brass_Plus _plus_client_01("Jesse_EC", "331081200403044836", 3000.00);
    std::ofstream info_file("client_info.txt");

    piggy.View_Account();
    p_line();
    _plus_client_01.View_Account();
    p_line();

    /*存 1000 美元给 _plus_client_01 用户*/
    cout << "Deposit $1000 to _plus_client_01: " << endl;
    _plus_client_01.Deposit(1000.00);
    cout << "_plus_client_01's balance: $" << _plus_client_01.Balence() << endl;
    p_line();

    /*从用户 piggy 那里取 4200 美元*/
    cout << "Withdraw $4200 from piggy's account: " << endl;
    piggy.With_Draw(4200);
    cout << "piggy's balance: $" << piggy.Balence() << endl;
    p_line();

    /*从用户 _plus_client_01 那里取 4200 美元*/
    cout << "Withdraw $4200 from piggy's account: " << endl;
    _plus_client_01.With_Draw(4200);
    cout << "piggy's balance: $" << _plus_client_01.Balence() << endl;
    p_line();

    info_file << piggy;

    info_file << _plus_client_01;

    return 0;
}