#include <iostream>
#include "Animal.h"

using namespace std;

void Animal::speak() {
    cout << "Grrrr" << endl;
}

string Animal::getName()
{
    return this->name;
}