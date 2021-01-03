#include <iostream>
#include "Cat.h"

using namespace std;

Cat::Cat() {
    cout << "Cat created." << endl;
    happy = true;
}

Cat::~Cat() {
    cout << "Cat destroyed" << endl;
}

void Cat::speak()
{
    if (happy)
    {
        cout << "Miau" << endl;
    }
    else {
        cout << "sssss" << endl;
    }
}

void Cat::jump()
{
    cout << "Jumping!" << endl;
}

bool Cat::isHappy()
{
    return Cat::happy;
}

void Cat::setHappy(bool isHappy)
{
    happy = isHappy;
}