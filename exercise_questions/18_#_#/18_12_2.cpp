#include <MyLib/myLogerDef.h>

using namespace MyLib::MyLoger;

class Cpmv
{
    public:
        struct Info
        {
            std::string qCode;
            std::string zCode;
        };

    private:
        Info * info;

    public:
        Cpmv(void) : info(nullptr) { CORRECT_LOG("Call method Cpmv(void);\n"); }
        Cpmv(std::string __q, std::string __z);
        Cpmv(const Cpmv & __mv);
        Cpmv(Cpmv && __mv);

        Cpmv & operator=(const Cpmv & __cp);
        Cpmv & operator=(Cpmv && __cp);
        Cpmv operator+(const Cpmv & __obj) const;

        void display(void) const;

        ~Cpmv() { delete info; }
};

Cpmv::Cpmv(std::string __q, std::string __z) : info(new Info{__q, __z}) 
{
    CORRECT_LOG("Call method Cpmv(std::string __q, std::string __z);\n");
}

Cpmv::Cpmv(const Cpmv & __mv) : info(new Info{__mv.info->qCode, __mv.info->zCode}) 
{
    CORRECT_LOG("Call method Cpmv(const Cpmv & __mv);\n");
}

Cpmv::Cpmv(Cpmv && __mv) : info(__mv.info)
{
    CORRECT_LOG("Call method [Cpmv & operator=(Cpmv && __cp);]\n");
    __mv.info = nullptr;
}

Cpmv & Cpmv::operator=(const Cpmv & __cp)
{
    CORRECT_LOG("Call method [Cpmv & operator=(const Cpmv & __cp);]\n");

    if (this != &__cp)
    {
        Info * newInfo = new Info{__cp.info->qCode, __cp.info->zCode};
        delete this->info;
        info = newInfo;
    }

    return *this;
}

Cpmv & Cpmv::operator=(Cpmv && __cp)
{
    CORRECT_LOG("Call method [Cpmv & operator=(Cpmv && __cp);]\n");

    if (this != &__cp)
    {
        Info * newInfo = new Info{__cp.info->qCode, __cp.info->zCode};

        delete this->info;

        this->info = newInfo;
        __cp.info = nullptr;
    }

    return *this;
}

Cpmv Cpmv::operator+(const Cpmv & __obj) const
{
    CORRECT_LOG("Call method [Cpmv operator+(const Cpmv & __obj) const;]\n");

    return Cpmv(
                    (this->info->qCode + __obj.info->qCode), 
                    (this->info->zCode + __obj.info->zCode)
                );
}

void Cpmv::display(void) const
{
    using namespace MyLib::MyLoger;

    printSplitLine(45, '-');
    loger(
        std::cout, ORIGINAL,
        "Q Code = ", this->info->qCode, '\n',
        "Z Code = ", this->info->zCode, '\n'
    );
    printSplitLine(45, '-');
}

int main(int argc, char const *argv[])
{
    system("cls");

    Cpmv newMv("114514", "1919810");

    Cpmv newMv_2;
    newMv_2 = newMv;
    Cpmv newMv_3(newMv_2);

    Cpmv combinMv = (newMv + newMv_2); 

    NOTIFY_LOG("newMv content: \n");
    newMv.display();

    NOTIFY_LOG("newMv_2 content: \n");
    newMv_2.display();

    NOTIFY_LOG("newMv_3 content: \n");
    newMv_3.display();

    NOTIFY_LOG("combinMv content: \n");
    combinMv.display();

    return EXIT_SUCCESS;
}
