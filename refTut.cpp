#include <iostream>

using namespace std;


void change(int &value)
{
    value = 2;
}

void changePointer(int *pValue)
{
    *pValue = 2;
}

int main()
{
    int value1 = 5;
    int &value2 = value1;

    value2 = 10;

    cout << "value 1: " << value1 << endl;
    cout << "value 2: " << value2 << endl;

    int value3 = 5;
    int *pValue3 = &value3;
    changePointer(pValue3);

    cout << "value 3: " << value3 << endl;

    cout << "value 3: " << *pValue3 << endl;

}