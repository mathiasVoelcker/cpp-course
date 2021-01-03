#include <iostream>
#include "Animal.h"

using namespace std;

void Wild::Animal::setSpecies(string species)
{
    this->species = species;
}

void Wild::Animal::speak()
{
    cout << "this is a " << this->species << endl;
}

string Wild::Animal::toString()
{
    return this->species;
}
