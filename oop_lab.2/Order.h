#pragma once
#include "Product.h"
#include "Customer.h"

class Order {
private:
    int orderId;
    Product product;
    Customer customer;
    int quantity;

public:
    Order(int orderId = 0,
        Product product = Product(),
        Customer customer = Customer(),
        int quantity = 1);

    void printInfo() const;
    ~Order();
};
