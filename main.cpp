#include <iostream>
#include "Person.h"
#include "Animal.h"

using namespace std;

using namespace Wild;

Animal *createAnimal()
{
    Animal *pAnimal = new Animal();
    pAnimal->setSpecies("chicken");
    cout << pAnimal << endl;
    return pAnimal;
}

void setAnimalSpecies(Animal *list)
{
    cout << list << endl;
    list->setSpecies("cow");
    list++;
    list->setSpecies("pig");
    list++;
    list->setSpecies("chicken");
}

Animal * getAnimals()
{
    Animal *animalList = new Animal[3];
    Animal *baseRef = animalList;
    animalList->setSpecies("lion");
    // cout << animalList->toString() << endl;
    animalList++;
    animalList->setSpecies("tiger");
    animalList++;
    animalList->setSpecies("elephant");
    animalList++;
    return baseRef;
}

int main()
{
    // Animal animal;
    Animal *animalList = new Animal[3];

    cout << animalList << endl; //address of array

    setAnimalSpecies(animalList);

    for (int i = 0; i < 3; i++)
    {
        animalList[i].speak();
    }

    cout << "" << endl;

    Animal *newAnimals = getAnimals();

    for (int i = 0; i < 3; i++)
    {
        newAnimals->speak();
        newAnimals++;
    }
    newAnimals -= 3;

    // while(animalList < &animalList[2])
    // {
    //     animalList->speak();
    //     animalList++;
    // }


    delete [] animalList;
    delete [] newAnimals;

    // animal = *lion;
    // lion->setSpecies("pig");

    // animal.speak();
    // lion->speak();

    // cout << lion << endl;
    // cout << animal.toString() << endl;

    // delete lion;

    // cout << "end of program" << endl;




    // // Person emptyPerson; 
    // // Person person1("Mathias", 26);

    // // Person person2 = person1;


    // // cout << emptyPerson.toString() << endl;
    // // cout << person1.toString() << endl;
    // // cout << person2.toString() << endl;

    
    

    // // int val1 = 1;
    
    // // const int *pValue1 = &val1;
    // // // int * const pValue1 = &val1;

    // // int val2 = 2;

    // // *pValue1 = val2;

    // // cout << *pValue1 << endl;

    return 0;
}