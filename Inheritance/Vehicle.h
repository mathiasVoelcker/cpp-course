#include <iostream>

#include "Machine.h"

using namespace std;

class Vehicle: public Machine {
    public:
        Vehicle() { cout << "hey vehicle!" << endl; };
        Vehicle(int id): Machine(id) { };
};