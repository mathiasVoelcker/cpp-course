#include <iostream>
using namespace std;

int main()
{
    for (int i = -128; i < 128; i++)
    {
        char c = i;
        cout << (int) c << ": " << c << endl;
    }
    return 0;
}