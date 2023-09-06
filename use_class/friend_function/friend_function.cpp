#include <iostream>
#include <ostream>
#include <vector>

const size_t data_len = 10;

class Friend_Function
{
    private:
        std::string disc;
        std::vector<double> data_t;

    public:
        Friend_Function();

        friend std::ostream & operator<<(std::ostream & os, const Friend_Function & _friend);

        ~Friend_Function() {}
        
};

Friend_Function::Friend_Function()
{
    disc += "Friend_Function";
    
    data_t.reserve(data_len);
    
    for (int index = 0; index < data_len; ++index)
    {
        data_t.push_back(index + 9.091);
    }
}

std::ostream & operator<<(std::ostream & os, const Friend_Function & _friend)
{
    os << _friend.disc << ' ';

    os << "Class data contence: " << std::endl;
    for (const auto & vec_data : _friend.data_t)
    {
        os << vec_data;
        os.put(' ');
    }

    return os;
}

int main(int argc, char const *argv[])
{
    Friend_Function _friend_func;

    std::cout << _friend_func << "Over...." << std::endl;
    
    return 0;
}
