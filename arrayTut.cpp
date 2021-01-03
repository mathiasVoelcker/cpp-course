#include <iostream>
using namespace std;

void manipulate(double *value)
{
    *value = 10;
    cout << "value's address: " << value << endl;
    cout << "value inside manipulate: " << *value << endl;
}

int main()
{

    string texts[] = { "one", "two", "three" };
    
    cout << texts << endl; //the address which the array is at

    string *pTexts = texts;
    cout << sizeof(texts) << endl;

    cout << &pTexts << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "address: " << &pTexts << endl; //prints the address of the array, not of the elements
        cout << "value: " << *pTexts << endl;
        cout << "something: " << pTexts << endl; //prints the address of the value printed on the line above
        cout << endl;
        pTexts++; //the address at pTexts is added by 24, the length of a string object, now, pTexts is pointing to the next el of the array
    }

    string *currentMemory = &texts[0];
    string *finalMemory = &texts[2];
    
    do
    {
        cout << "value: " << *currentMemory << endl;
        currentMemory++;
    } while (currentMemory <= finalMemory);
    
}