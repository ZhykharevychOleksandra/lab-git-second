#include <iostream>
#include "DigitalProduct.h"

DigitalProduct::DigitalProduct(int id,
    std::string name,
    double price,
    double fileSize)
    : Product(id, name, price), fileSize(fileSize) {
}

void DigitalProduct::printInfo() const {
    Product::printInfo();
    std::cout << "File size: " << fileSize << " MB" << std::endl;
}

DigitalProduct::~DigitalProduct() {
    std::cout << "DigitalProduct destroyed\n";
}

double DigitalProduct::getPrice() const {
    return price;
}

void DigitalProduct::applyDiscount() {
    price *= 0.8;
}