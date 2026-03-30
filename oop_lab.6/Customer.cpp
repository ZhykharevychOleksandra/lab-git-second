#include <iostream>
#include "Customer.h"

int Customer::customerCount = 0;

//конструктор
Customer::Customer(int id,
    std::string name,
    std::string email)
    : Person(id, name), email(email) {

    customerCount++;
}

// copy
Customer::Customer(const Customer& other)
    : Person(other), email(other.email) {

    std::cout << "Customer copied\n";
    customerCount++;
}

// move
Customer::Customer(Customer&& other) noexcept
    : Person(std::move(other)), email(std::move(other.email)) {

    std::cout << "Customer moved\n";
    customerCount++;
}

void Customer::printInfo() const {
    Person::printInfo();
    std::cout << "Email: " << email << std::endl;
}

void Customer::setEmail(std::string email) {
    this->email = email;
}

std::string Customer::getEmail() const {
    return email;
}

int Customer::getCustomerCount() {
    return customerCount;
}

std::ostream& operator<<(std::ostream& os, const Customer& c) {
    os << "Email: " << c.email;
    return os;
}

std::istream& operator>>(std::istream& is, Customer& c) {
    std::cout << "Enter email: ";
    is >> c.email;
    return is;
}

Customer::~Customer() {
    std::cout << "Customer destroyed\n";
    customerCount--;
}