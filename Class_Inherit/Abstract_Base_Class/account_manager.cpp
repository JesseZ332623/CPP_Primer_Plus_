#include "./src/include/brass_account.h"
#include <memory>

/*普通用户 和 PLUS用户 的数量*/
const int BRASS_CLIENT = 2;
const int BRASS_PLUS_CLIENT = 2;

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
    std::unique_ptr<Brass_Account[]> brass_client_set(new Brass_Account[BRASS_CLIENT]);

    auto brass_client_ptr = brass_client_set.get();

    for (int index = 0; index < BRASS_CLIENT; ++index)
    {
        
        brass_client_ptr->View_Account();
        ++brass_client_ptr;
    }

    return EXIT_SUCCESS;
}
