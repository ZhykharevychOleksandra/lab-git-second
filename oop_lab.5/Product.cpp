#include <iostream>
#include <utility>
#include "Product.h"

int Product::productCount = 0;

Product::Product() : Product(0, "Unknown", 0.0) {}

Product::Product(int id, std::string name, double price)
    : id(id), name(name), price(price) {
    productCount++;
}

//copy constructor
Product::Product(const Product& other)
    : id(other.id), name(other.name), price(other.price) {
    std::cout << "Copy constructor called\n";
    productCount++;
}

//move constructor
Product::Product(Product&& other) noexcept
    : id(other.id), name(std::move(other.name)), price(other.price) {

    std::cout << "Move constructor called\n";

    other.id = 0;
    other.price = 0;
    productCount++;
}

//ןמכ³למנפ³חל
void Product::applyDiscount() {
    std::cout << "No discount applied for base product\n";
}

void Product::printInfo() const {
    std::cout << "ID: " << id
        << ", Name: " << name
        << ", Price: " << price << std::endl;
}

void Product::setPrice(double price) {
    this->price = price;
}

double Product::getPrice() const {
    return price;
}

int Product::getProductCount() {
    return productCount;
}

//Product Product::operator+(const Product& other) {
  //  return Product(
    //    id,
      //  name + "+" + other.name,
        //price + other.price
 //   );
//}

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

Product::~Product() {
    std::cout << "Product destroyed: " << name << std::endl;
    productCount--;
}