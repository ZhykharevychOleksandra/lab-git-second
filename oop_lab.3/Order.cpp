#include <iostream>
#include "Order.h"

int Order::orderCount = 0;

Order::Order(int orderId,
    Product product,
    Customer customer,
    int quantity)
    : orderId(orderId),
    product(product),
    customer(customer),
    quantity(quantity) {

    orderCount++;
}

// copy constructor
Order::Order(const Order& other)
    : orderId(other.orderId),
    product(other.product),
    customer(other.customer),
    quantity(other.quantity) {

    std::cout << "Order copied\n";
    orderCount++;
}

// move constructor
Order::Order(Order&& other) noexcept
    : orderId(other.orderId),
    product(std::move(other.product)),
    customer(std::move(other.customer)),
    quantity(other.quantity) {

    std::cout << "Order moved\n";

    other.orderId = 0;
    other.quantity = 0;
    orderCount++;
}

void Order::printInfo() const {
    std::cout << "Order ID: " << orderId << std::endl;
    product.printInfo();
    customer.printInfo();
    std::cout << "Quantity: " << quantity << std::endl;
}

// this
void Order::setQuantity(int quantity) {
    this->quantity = quantity;
}

// const
int Order::getQuantity() const {
    return quantity;
}

// static
int Order::getOrderCount() {
    return orderCount;
}

// unary operator
Order& Order::operator++() {
    quantity++;
    return *this;
}

// binary operator
Order Order::operator+(const Order& other) {
    return Order(
        orderId,
        product,
        customer,
        quantity + other.quantity
    );
}

// <<
std::ostream& operator<<(std::ostream& os, const Order& order) {
    os << "Order ID: " << order.orderId
        << ", Quantity: " << order.quantity;
    return os;
}

// >>
std::istream& operator>>(std::istream& is, Order& order) {
    std::cout << "Enter order ID: ";
    is >> order.orderId;

    std::cout << "Enter quantity: ";
    is >> order.quantity;

    return is;
}

Order::~Order() {
    std::cout << "Order destroyed: " << orderId << std::endl;
    orderCount--;
}