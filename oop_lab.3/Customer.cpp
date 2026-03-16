#include <iostream>
#include "Customer.h"

int Customer::customerCount = 0;

Customer::Customer(int id,
    std::string name,
    std::string email)
    : id(id), name(name), email(email) {

    customerCount++;
}

// copy constructor
Customer::Customer(const Customer& other)
    : id(other.id), name(other.name), email(other.email) {

    std::cout << "Customer copied\n";
    customerCount++;
}

// move constructor
Customer::Customer(Customer&& other) noexcept
    : id(other.id), name(std::move(other.name)), email(std::move(other.email)) {

    std::cout << "Customer moved\n";
    other.id = 0;
    customerCount++;
}

void Customer::printInfo() const {
    std::cout << "ID: " << id
        << ", Name: " << name
        << ", Email: " << email << std::endl;
}

// this
void Customer::setEmail(std::string email) {
    this->email = email;
}

// const
std::string Customer::getEmail() const {
    return email;
}

// static
int Customer::getCustomerCount() {
    return customerCount;
}

// <<
std::ostream& operator<<(std::ostream& os, const Customer& c) {
    os << "ID: " << c.id
        << ", Name: " << c.name
        << ", Email: " << c.email;
    return os;
}

// >>
std::istream& operator>>(std::istream& is, Customer& c) {
    std::cout << "Enter id: ";
    is >> c.id;

    std::cout << "Enter name: ";
    is >> c.name;

    std::cout << "Enter email: ";
    is >> c.email;

    return is;
}

Customer::~Customer() {
    std::cout << "Customer destroyed: " << name << std::endl;
    customerCount--;
}