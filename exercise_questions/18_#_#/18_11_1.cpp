/**
 * 使用 {} 符号重写下面的代码。重写后的代码不应该使用数组 ar
*/

#include <iostream>
#include <string>
#include <vector>

class Z200
{
    private:
        int j       {0};
        char ch     {0};
        double z    {0.0};

    public:
        Z200(int __j, char __c, double __z) : j(__j), ch(__c), z(__z) { }

        /* ..... */
};

int main(int argc, char const *argv[])
{
    double x = 0.0;
    std::string s = "What a bracing effect!";
    int k{99};

    Z200 zip(200, 'Z', 0.675);
    std::vector<int> ai{3, 9, 4, 7, 1};

    return EXIT_SUCCESS;
}
