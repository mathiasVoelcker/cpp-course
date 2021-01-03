#include <iostream>

using namespace std;

int main()
{
    char text[] = "hello";

    cout << text << endl;

    char *pChar = text;

    cout << *pChar << endl;

    while (*pChar != 0)
    {
        cout << pChar << endl;
        cout << *pChar << endl;
        pChar++;
    }

    return 0;
}