#pragma once
#include "Product.h"

class PhysicalProduct : public Product {
private:
    double weight;

public:
    PhysicalProduct(int id = 0,
        std::string name = "Unknown",
        double price = 0.0,
        double weight = 0.0);

    void printInfo() const;

    // copy constructor
    PhysicalProduct(const PhysicalProduct& other);

    // move constructor
    PhysicalProduct(PhysicalProduct&& other) noexcept;

    PhysicalProduct& operator=(const PhysicalProduct& other);

    ~PhysicalProduct();
};