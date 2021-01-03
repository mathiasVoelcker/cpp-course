#include <iostream>

using namespace std;

class Machine {

    private:
        int id;

    public:
        Machine(): id(0) { cout << "hey there!" << endl; };
        Machine(int id): id(id) { cout << "id " << id << " saved!" << endl; };
        void info();
};