#include "golf.h"

/*设置队员的数量*/
golf *set_golf_member(int member_no);

golf *set_golf_member(int member_no)
{
    golf *_golf = new golf[member_no];

    return _golf;
}

int main(int argc, char const *argv[])
{
    system("cls");

    using std::cout, std::endl, std::cin;

    int golf_member = 0;            /*队员数量*/
    golf *_golf_ = nullptr;         /*golf 结构体指针*/

    cout << "Enter golf play number :"; /*输入数量*/
    cin >> golf_member;

    _golf_ = set_golf_member(golf_member);  /*设置队员的数量*/

    /*用循环依次输入队员的信息*/
    for (int index = 0; index < golf_member; ++index)
    {
        set_golf(_golf_[index], index);
    }

    /*依次展示队员的信息*/
    for (int index = 0; index < golf_member; ++index)
    {
        show_golf(_golf_[index], index);
    }

    set_golf(_golf_[2], "Mike", 18);

    /*依次展示队员的信息*/
    for (int index = 0; index < golf_member; ++index)
    {
        show_golf(_golf_[index], index);
    }

    delete _golf_;

    return EXIT_SUCCESS;
}