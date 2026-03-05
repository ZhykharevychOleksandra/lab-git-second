#include <iostream>
#include "Product.h"

Product::Product(int id, std::string name, double price)
    : id(id), name(name), price(price) {
}

void Product::printInfo() const {
    std::cout << "ID: " << id
        << ", Name: " << name
        << ", Price: " << price << std::endl;
}

Product::~Product() {
    std::cout << "Product destroyed: " << name << std::endl;
}