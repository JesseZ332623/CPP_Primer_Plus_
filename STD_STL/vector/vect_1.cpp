#include <iostream>
#include <vector>
#include <string>

const int NUMBER = 5;

int main(int argc, char const *argv[])
{
    using std::vector, std::string, std::printf, std::puts, std::endl, std::getline, std::cin;

    vector<int> _ratings(NUMBER);
    vector<string> _titles(NUMBER);

    int index = 0;

    for (index; index < NUMBER; ++index)
    {
        printf("Enter title #%d: ", index + 1);
        getline(cin, _titles.at(index));
        printf("Enter the rating of #%d: ", index + 1);
        cin >> _ratings.at(index);

        while (getchar() != '\n') { continue; }
    }

    puts("------------------------------------------------");
    for (index = 0; index < NUMBER; ++index)
    {
        printf("%d:\t%s \n", _ratings.at(index), _titles.at(index).c_str());
    }

    return 0;
}
