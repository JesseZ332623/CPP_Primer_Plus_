#include <iostream>
#include <string>

class Test_Class
{
    private:
        std::string discrible_class;
    
    public:
        Test_Class(std::string init_string);

        bool Set_String(std::string set_str);

        ~Test_Class();
};

Test_Class::Test_Class(std::string init_string)
{
    std::cout << "class was create...\n";
    this->discrible_class = init_string;
}

bool Test_Class::Set_String(std::string set_str)
{
    if (set_str.empty())
    {
        return false;
    }

    std::cout << this->discrible_class + set_str << std::endl;

    return true;
}

Test_Class::~Test_Class(void)
{
    std::cout << "This class was free...\n";
}

int main(int argc, char const *argv[])
{
    std::cout << __FILE__ << __DATE__ << __TIME__ << std::endl;

    Test_Class *test_class = new Test_Class("New String");

    test_class->Set_String(" to Create...\n");

    delete test_class;


    return 0;
}
