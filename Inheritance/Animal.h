#ifndef ANIMAL_H_
#define ANIMAL_H_

using namespace std;

class Animal {

    private: 
        string name;

    public :
        Animal() {};
        Animal(string name): name(name) {};
        void speak();
        string getName();
    
};

#endif