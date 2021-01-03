#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>
#include <sstream>

using namespace std;

class Person 
{
private:
    string name;
    int age;
public:
    Person(): name("not known again"), age(-1) { cout << "person created" << endl; };
    Person(string newName, int newAge): name(newName), age(newAge) { };
    Person(const Person &copy): name(copy.name), age(copy.age) { cout << "person copied" << endl; };
    string toString();
    void setName(string newName);
    string getName();
};

#endif