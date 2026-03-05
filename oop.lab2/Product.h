#pragma once
#include <string>

class Product {
private:
    int id;
    std::string name;
    double price;

public:
    Product(int id = 0, std::string name = "Unknown", double price = 0.0);
    void printInfo() const;
    ~Product();
};
