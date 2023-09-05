#include <iostream>

using namespace std;

void other();
void another();

int x = 10;
int y;

void other()
{
    int y = 1;
    cout << "Other " << x << ' ' << y << endl;
}

int main(int argc, char const *argv[])
{
    cout << "argc: " << argc << endl << argv[0] << endl;
    cout << "----------------------------------------------\n";

    cout << x << endl;
    {
        int x = 4;
        cout << x << endl;
        cout << y << endl;
    }

    other();
    another();

    return EXIT_SUCCESS;
}
