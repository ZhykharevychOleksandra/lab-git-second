#include "Product.h"
#include "Customer.h"
#include "Order.h"

int main() {

    Product p1(1, "Laptop", 25000);
    Customer c1(2, "Sasha", "sasha@gmail.com");

    Order o1(100, p1, c1, 2);
    o1.printInfo();

    return 0;
}