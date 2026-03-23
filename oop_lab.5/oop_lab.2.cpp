#include <iostream>
#include <utility>
#include "Product.h"
#include "Customer.h"
#include "Order.h"
#include "PhysicalProduct.h"
#include "DigitalProduct.h"

// поліморфізм через reference
void show(const Product& p) {
    p.printInfo();
}

int main() {

    std::cout << "\n--- Static Binding ---\n";

    PhysicalProduct pp(10, "Laptop", 25000, 2.5);
    DigitalProduct dp(11, "Game", 500, 15.0);

    pp.printInfo();
    dp.printInfo();

    std::cout << "\n--- Dynamic Polymorphism ---\n";

    Product* p1 = new PhysicalProduct(1, "Laptop", 25000, 2.5);
    Product* p2 = new DigitalProduct(2, "Game", 500, 15.0);

    p1->printInfo();
    p2->printInfo();

    p1->applyDiscount();
    p2->applyDiscount();

    std::cout << "\nAfter discount:\n";
    p1->printInfo();
    p2->printInfo();

    std::cout << "\nPrices:\n";
    std::cout << p1->getPrice() << std::endl;
    std::cout << p2->getPrice() << std::endl;

    std::cout << "\n--- Reference polymorphism ---\n";
    show(*p1);
    show(*p2);

    delete p1;
    delete p2;

    return 0;
}