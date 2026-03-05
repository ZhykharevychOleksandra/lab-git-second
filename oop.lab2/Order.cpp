#include <iostream>
#include "Order.h"

Order::Order(int orderId,
    Product product,
    Customer customer,
    int quantity)
    : orderId(orderId),
    product(product),
    customer(customer),
    quantity(quantity) {
}

void Order::printInfo() const {
    std::cout << "Order ID: " << orderId << std::endl;
    product.printInfo();
    customer.printInfo();
    std::cout << "Quantity: " << quantity << std::endl;
}

Order::~Order() {
    std::cout << "Order destroyed: " << orderId << std::endl;
}