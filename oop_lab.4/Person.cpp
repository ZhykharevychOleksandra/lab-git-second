#include "Person.h"

Person::Person(int id, std::string name)
    : id(id), name(name) {
}

void Person::printInfo() const {
    std::cout << "ID: " << id
        << ", Name: " << name << std::endl;
}

Person::~Person() {
    std::cout << "Person destroyed: " << name << std::endl;
}