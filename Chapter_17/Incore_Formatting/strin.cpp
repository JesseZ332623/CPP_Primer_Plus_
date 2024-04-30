#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>



int main(int argc, char const *argv[])
{
    system("cls");
    
    /**
     * 那是一个黑暗且狂风作浪的日子，满月发出灿烂的光芒。
    */
    std::string sentence = "It was a dark and stormy day, and the full moon glowed brilliantly. ";
    std::istringstream inputStream(sentence);

    std::string word;

    std::cout << sentence + '\n';
    while (inputStream >> word)
    {
        std::cout << word << '\n';  
    }

    return EXIT_SUCCESS;
}
