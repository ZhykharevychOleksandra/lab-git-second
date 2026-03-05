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

































/*
#include <iostream>
#include <string>
using namespace std;

class Product {
private:
    int id;
    string name;
    double price;

public:
    //конструктор за замовчування
    Product(int id = 0, string name = "Unknown", double price = 0.0)
        : id(id), name(name), price(price) {}

    //делегувальник (типу є дублікати і через це погано працює)
    //Product() : Product(0, "Unknown", 0.0) {} //або дефолт або делегувальник

    void printInfo() {
        cout << "ID: " << id << "\n" << ", Name: " << name << "\n" << ", Price: " << price;
    }

    //деструктор
    ~Product() {
        cout << "Product destroyed: " << name << endl;
    }
};

class Customer {
private:
    int id;
    string name;
    string email;

public:
    //конструктор за замовчування 
    Customer(int id = 0, string name = "Unknown", string email = "sasha@gmail.com")
        : id(id), name(name), email(email) {}

    //делегувальник
    //Customer() : Customer(0, "Unknown", "sasha@gmail.com") {}

    void printInfo() {
        cout << "ID: " << id << ", Name: " << name << ",Email: " << email;
    }

    //деструктор
    ~Customer() {
        cout << "Customer destroyed: " << name << endl;
    }
};

class Order {
private:
    int orderId;
    Product product;
    Customer customer;
    int quantity;

public:
    //конструктор за замовчуванням
    Order(int orderId = 0,
        Product product = Product(),
        Customer customer = Customer(),
        int quantity = 1)
        : orderId(orderId),
        product(product),
        customer(customer),
        quantity(quantity) {}

    //делегувальник/ якщо є параметри за замовчуванням, то Order вже існує автоматично.
    Order() : Order(0, Product(), Customer(), 1) {}

    void printInfo() {
        cout << "Order ID: " << orderId << endl;
        product.printInfo();
        cout << endl;
        customer.printInfo();
        cout << endl;
        cout << "Quantity: " << quantity << endl;
    }

    //деструктор
    ~Order() {
        cout << "Order destroyed: " << orderId << endl;
    }
};

int main() {
    Product p1 (1, "Laptop", 25000);
    p1.printInfo();

    Product p2;
    p2.printInfo();

    Customer c1(2, "Sasha", "Sasha@gmail.com");
    c1.printInfo();

    Customer c2;
    c2.printInfo();

    Order o1 (100, p1, c1, 2);
    o1.printInfo();

    Order o2(101, p2, c2, 5);
    o2.printInfo();

    return 0;
} */

















































//Product(int id, string name, double price)
  //  : id(id), name(name), price(price) {
//}
