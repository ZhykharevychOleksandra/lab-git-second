#include <iostream>
#include <utility>
#include "Product.h"
#include "Customer.h"
#include "Order.h"
#include "PhysicalProduct.h"
#include "DigitalProduct.h"

#include <memory>
#include <fstream>
#include "Store.h"

void show(const Product& p) {
    p.printInfo();
}

void adminMenu(Store& store) {
    std::string password;

    std::cout << "Enter password: ";
    std::cin >> password;

    if (password != "1234") {
        std::cout << "Wrong password!\n";
        return;
    }

    int choice;
    std::cout << "1. Add Physical Product\n2. Add Digital Product\n";
    std::cin >> choice;

    if (choice == 1) {
        store.addProduct(std::make_shared<PhysicalProduct>(1, "Laptop", 25000, 2.5));
    }
    else if (choice == 2) {
        store.addProduct(std::make_shared<DigitalProduct>(2, "Game", 500, 10));
    }

    store.saveToFile();
}

void userMenu(Store& store) {
    store.loadFromFile();
    store.showProducts();
    std::ofstream history("history.txt", std::ios::app);
    history << "User opened product list\n";
}

int main() {

    Store store;

    int choice;

    while (true) {
        std::cout << "1. Admin\n2. User\n0. Exit\n";
        std::cin >> choice;

        try {
            if (std::cin.fail()) {
                throw std::runtime_error("Invalid input");
            }

            if (choice == 1) {
                adminMenu(store);
            }
            else if (choice == 2) {
                userMenu(store);
            }
            else {
                break;
            }
        }
        catch (std::exception& e) {
            std::cout << e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
    }

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