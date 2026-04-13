#include <iostream>
#include "Product.h"

int Product::productCount = 0;

Product::Product() : Product(0, "Unknown", 0.0) {}

Product::Product(int id, std::string name, double price)
    : id(id), name(name), price(price) {
    productCount++;
}

// Copy constructor
Product::Product(const Product& other)
    : id(other.id), name(other.name), price(other.price) {
    std::cout << "Copy constructor called\n";
    productCount++;
}

// Move constructor
Product::Product(Product&& other) noexcept
    : id(other.id), name(std::move(other.name)), price(other.price) {

    std::cout << "Move constructor called\n";

    other.id = 0;
    other.price = 0;
    productCount++;
}

void Product::printInfo() const {
    std::cout << "ID: " << id
        << ", Name: " << name
        << ", Price: " << price << std::endl;
}

// this
void Product::setPrice(double price) {
    this->price = price;
}

// const
double Product::getPrice() const {
    return price;
}

// static
int Product::getProductCount() {
    return productCount;
}

// binary operator +
Product Product::operator+(const Product& other) {
    return Product(
        id,
        name + "+" + other.name,
        price + other.price
    );
}

Product& Product::operator++() {
    price++;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Product& product) {
    os << "ID: " << product.id
        << ", Name: " << product.name
        << ", Price: " << product.price;
    return os;
}

std::istream& operator>>(std::istream& is, Product& product) {
    std::cout << "Enter ID: ";
    is >> product.id;

    std::cout << "Enter name: ";
    is >> product.name;

    std::cout << "Enter price: ";
    is >> product.price;

    return is;
}

void Product::applyDiscount() {
    std::cout << "Base discount applied\n";
}

Product::~Product() {
    std::cout << "Product destroyed: " << name << std::endl;
    productCount--;
}