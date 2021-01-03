#include "Person.h"

// Person::Person(): name("not known"), age(0)  { }


string Person::toString()
{
    stringstream stream;
    stream << "Name: " << name << endl << "Age: " << age << endl;
    return stream.str();
}

void Person::setName(string newName)
{
    name = newName;
}

string Person::getName()
{
    return name;
}