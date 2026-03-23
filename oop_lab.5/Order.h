#pragma once
#include "Product.h"
#include "Customer.h"
#include <iostream>

class Order {
private:
    int orderId;
    Product* product;
    Customer customer;
    int quantity;

    static int orderCount; // static

public:
    Order(int orderId = 0,
        Product* product = nullptr,
        Customer customer = Customer(),
        int quantity = 1);

    // copy constructor
    Order(const Order& other);

    // move constructor
    Order(Order&& other) noexcept;

    void printInfo() const;

    // this
    void setQuantity(int quantity);

    // const
    int getQuantity() const;

    // static
    static int getOrderCount();

    // unary operator
    Order& operator++();

    // binary operator
    Order operator+(const Order& other);

    // stream operators
    friend std::ostream& operator<<(std::ostream& os, const Order& order);
    friend std::istream& operator>>(std::istream& is, Order& order);

    ~Order();
};
