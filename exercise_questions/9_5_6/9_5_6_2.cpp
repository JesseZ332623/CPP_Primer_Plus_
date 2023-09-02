#include <iostream>

using namespace std;

extern int x;

namespace 
{
    int y = -4;
}

void another()
{
    cout << "anthor(): " << x << ' ' << y << endl;
}