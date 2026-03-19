#include <iostream>
#include "Product.h"
#include "Customer.h"
#include "Order.h"

int main() {

    // базові об'єкти
    Product p1(1, "Laptop", 25000);
    Customer c1(2, "Sasha", "sasha@gmail.com");

    Order o1(100, p1, c1, 2);
    o1.printInfo();

    std::cout << "\n--- Copy constructor ---\n";
    Product p2 = p1; // копія

    std::cout << "\n--- Move constructor ---\n";
    Product p3 = std::move(p1); // переміщення

    std::cout << "\n--- Unary operator ++ ---\n";
    ++p2;
    p2.printInfo();

    std::cout << "\n--- Binary operator + ---\n";
    Product p4 = p2 + p3;
    std::cout << p4 << std::endl;

    std::cout << "\n--- Stream operators ---\n";
    Product p5;
    std::cin >> p5;
    std::cout << p5 << std::endl;

    std::cout << "\n--- Const object ---\n";
    const Product p6(3, "Phone", 15000);
    std::cout << "Price: " << p6.getPrice() << std::endl;

    std::cout << "\n--- Static field ---\n";
    std::cout << "Products created: "
        << Product::getProductCount()
        << std::endl;

    return 0;
}