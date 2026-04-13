#include <iostream>
#include <utility>
#include "PhysicalProduct.h"

PhysicalProduct::PhysicalProduct(int id,
    std::string name,
    double price,
    double weight)
    : Product(id, name, price), weight(weight) {
}

// copy constructor
PhysicalProduct::PhysicalProduct(const PhysicalProduct& other)
    : Product(other), weight(other.weight) {
    std::cout << "PhysicalProduct copied\n";
}

// move constructor
PhysicalProduct::PhysicalProduct(PhysicalProduct&& other) noexcept
    : Product(std::move(other)), weight(other.weight) {
    std::cout << "PhysicalProduct moved\n";
    other.weight = 0;
}

PhysicalProduct& PhysicalProduct::operator=(const PhysicalProduct& other) {
    if (this != &other) {
        weight = other.weight;
    }
    return *this;
}

void PhysicalProduct::printInfo() const {
    Product::printInfo();
    std::cout << "Weight: " << weight << std::endl;
}

double PhysicalProduct::getPrice() const {
    return price + 50; 
}

void PhysicalProduct::applyDiscount() {
    price *= 0.9;
}

PhysicalProduct::~PhysicalProduct() {
    std::cout << "PhysicalProduct destroyed\n";
}