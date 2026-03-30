#include "Store.h"

void Store::addProduct(std::shared_ptr<Product> product) {
    products.push_back(product);
}

void Store::showProducts() const {
    for (const auto& p : products) {
        p->printInfo();
    }
}

void Store::saveToFile() {
    std::ofstream file("products.txt");

    for (const auto& p : products) {
        file << p->getPrice() << std::endl;
    }
}

void Store::loadFromFile() {
    products.clear();
    std::ifstream file("products.txt");

    double price;
    while (file >> price) {
        products.push_back(std::make_shared<DigitalProduct>(0, "Loaded", price, 0));
    }
}