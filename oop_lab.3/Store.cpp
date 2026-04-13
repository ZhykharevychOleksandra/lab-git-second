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

        if (dynamic_cast<PhysicalProduct*>(p.get())) {
            file << "P ";
        }
        else {
            file << "D ";
        }

        file << *p << std::endl;
    }
}

void Store::loadFromFile() {
    products.clear();
    std::ifstream file("products.txt");

    char type;
    int id;
    std::string name;
    double price;

    while (file >> type >> id >> name >> price) {

        if (type == 'P') {
            double weight;
            file >> weight;

            products.push_back(
                std::make_shared<PhysicalProduct>(id, name, price, weight)
            );
        }
        else if (type == 'D') {
            double size;
            file >> size;

            products.push_back(
                std::make_shared<DigitalProduct>(id, name, price, size)
            );
        }
    }
}