#ifndef ANIMAL_H_
#define ANIMAL_H_

#include <iostream>
#include <sstream>

using namespace std;

namespace Wild {

class Animal
{
    private:
        string species;

    public:
        Animal(): species("unknow") { cout << "Animal created" << endl; };
        Animal(string species): species(species) { cout << species << " created" << endl; };
        Animal(const Animal &animal): species(animal.species) { cout << species << " copied" << endl; };
        ~Animal() { cout << species << " destroyed" << endl; };
        void setSpecies(string species);
        void speak();
        string toString();
};
}

#endif