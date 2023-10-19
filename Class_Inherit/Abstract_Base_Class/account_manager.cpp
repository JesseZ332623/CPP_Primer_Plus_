#include "./src/include/brass_account.h"

/*普通用户 和 PLUS用户 的数量*/
const int BRASS_CLIENT = 2;
const int BRASS_PLUS_CLIENT = 2;

/*普通用户 和 PLUS用户 的对象数组*/
static Brass_Account *brass_client_set;
static Brass_Plus *plus_client_set;

void Show_Set_Info(Account *clinet, const int count);

void Show_Set_Info(Account *clinet, const int count)
{
    for (int index = 0; index < count; ++index)
    {
        clinet[index].View_Account();
        std::cout << "---------------------------------------" << std::endl;
    }
}

int main(int argc, char const *argv[])
{
    std::cout << argc << " " << argv << std::endl;

    brass_client_set = new Brass_Account[BRASS_CLIENT]
    {
        Brass_Account("Jesse", "331081200403044836", 1000.00),
        Brass_Account("Mike", "331081203445780011x", 1208.00)
    };
    plus_client_set = new Brass_Plus[BRASS_PLUS_CLIENT]
    {
        Brass_Plus("Bad Man_01", "1010102102912910011", 50000.00),
        Brass_Plus("Bad Man_01", "842801488184881489x", 20000.00)
    };

    
    Show_Set_Info(brass_client_set, BRASS_CLIENT);
    Show_Set_Info(plus_client_set, BRASS_PLUS_CLIENT);

    delete[] brass_client_set;
    delete[] plus_client_set;


    return EXIT_SUCCESS;
}
