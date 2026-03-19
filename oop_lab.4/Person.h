#pragma once
#include <string>
#include <iostream>

class Person {
protected:
    int id;
    std::string name;

public:
    Person(int id = 0, std::string name = "Unknown");

    void printInfo() const;

    virtual ~Person();
};
