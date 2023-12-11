#include <iostream>

int main(int argc, char const *argv[])
{
    std::string _receive_str;

    printf("%s\n", (_receive_str.empty()) ? "Empty String" : "Not Empty String");

    /*从标准输入中获取来自程序 A 的标准输出*/
    std::getline(std::cin, _receive_str);

    /*最终输出到屏幕*/
    fprintf(stdout, "We received message Info: %s\n", _receive_str.c_str());   

    
    return EXIT_SUCCESS;
}