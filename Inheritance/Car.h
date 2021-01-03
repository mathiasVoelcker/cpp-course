#include "Vehicle.h"
#include <iostream>

using namespace std;


class Car: public Vehicle {
    public: 
        Car() { cout << "car created" << endl; };
        Car(int id): Vehicle(id) {};
};