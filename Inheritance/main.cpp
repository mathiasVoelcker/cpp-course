#include <iostream>
#include "Animal.h"
#include "Cat.h"

#include "Car.h"

using namespace std;

int main()
{
    Machine machine(1);
    Vehicle vehicle(2);
    Car car(3);

    machine.info();
    vehicle.info();
    car.info();

    // Animal animal("bob");
    // animal.speak();
    // cout << animal.getName() << endl;

    // Cat cat;
    // cat.speak();
    // cat.jump();
    
    return 0;
}