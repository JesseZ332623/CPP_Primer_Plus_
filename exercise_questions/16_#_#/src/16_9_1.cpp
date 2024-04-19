#include <iostream>
#include <string>

class RQ_1
{
    private:
        std::string str;

    public:

        RQ_1(void) : str{} {}

        RQ_1(const char * __str) : str{__str} {}

        RQ_1(const RQ_1 & __rq) : str{__rq.str} {}
        
        RQ_1 & operator<<(const RQ_1 & __rq) 
        { 
            if (this == &__rq) { return *this; }

            this->str = __rq.str;  return *this;
        }

        void display(void) const noexcept { std::cout << str << '\n';  }

        /**
         * 无需显式声明析构函数
        */
};

int main(int argc, char const *argv[])
{
    RQ_1 rqA;
    RQ_1 rqB("111111__");
    RQ_1 rqC(rqB);

    rqA.display();
    rqB.display();
    rqC.display();

    return EXIT_SUCCESS;
}
