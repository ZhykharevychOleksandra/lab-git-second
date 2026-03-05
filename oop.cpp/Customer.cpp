#include <iostream>
#include "Customer.h"

Customer::Customer(int id,
    std::string name,
    std::string email)
    : id(id), name(name), email(email) {
}

void Customer::printInfo() const {
    std::cout << "ID: " << id
        << ", Name: " << name
        << ", Email: " << email << std::endl;
}

Customer::~Customer() {
    std::cout << "Customer destroyed: " << name << std::endl;
}