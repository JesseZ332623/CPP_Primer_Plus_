/*
    这个测试用例很简单，用户输入 AR_SIZE 条谚语，
    逐条展示并找出最短的那一条和 ASCII 码最大的那一条。
*/

#include "./src/include/_String.h"
#include <algorithm>
#include <ctime>
#include <cstdlib>

using std::cout, std::cin, std::endl;

const int AR_SIZE = 10;
const int MAX_LEN = 81;

int main(int argc, char const *argv[])
{
    srand(time(0));

    _String name;
    _String sayings[AR_SIZE];
    char temp_string[MAX_LEN];

    cout << "Hi what's your name? >> ";
    cin >> name;
    cout << "-----------------------------------------------------------" << endl;
    cout << name << ", Please enter up to " << AR_SIZE << "short sayings <empty line to quit>: \n";

    int loop_index = 0;
    for (loop_index = 0; loop_index < AR_SIZE; ++loop_index)
    {
        cout << loop_index + 1 << ": ";
        cin.get(temp_string, MAX_LEN);

        while (cin && cin.get() != '\n') { continue; }

        if (!cin)
        {
            break;
        }
        else
        {
            sayings[loop_index] = temp_string;
        }   
    }
    cout << "-----------------------------------------------------------" << endl;

    int total = loop_index;

    if (total > 0)
    {
        int first = 0;
        int shortest = 0;
        for (loop_index = 1; loop_index < total; ++loop_index)
        {
            if (sayings[loop_index].length() < sayings[shortest].length())
            {
                shortest = loop_index;
            }

            
            if (sayings[loop_index] < sayings[first])
            {
                first = loop_index;
            }   
        }
        cout << "Here are your sayings: " << endl;
        for (loop_index = 0; loop_index < total; ++loop_index)
        {
            cout << sayings[loop_index][0] << ": " << sayings[loop_index] << endl;
        }

        int favor_index = rand() % total;
        _String *favorite = new _String(sayings[favor_index]);
        
        cout << "-----------------------------------------------------------" << endl;
        cout << "Shortest saying: \n" << sayings[shortest] << endl;
        cout << "First alphabetically: \n" << sayings[first] << endl;
        cout << name << "'s favorite saying is: " << *favorite << endl;
        cout << "This program used " << _String::String_Count() << " String objects. Bye.\n";

        delete favorite;
    }
    else
    {
        cout << "No input! Bye!" << endl;
    }

    return EXIT_SUCCESS;
}
