#pragma once
#include <string>
#include "Product.h"

class PhysicalProduct : public Product {
private:
    double weight;

public:
    PhysicalProduct(int id = 0,
        std::string name = "Unknown",
        double price = 0.0,
        double weight = 0.0);

    PhysicalProduct(const PhysicalProduct& other);  //copy
    PhysicalProduct(PhysicalProduct&& other) noexcept;  //move

    PhysicalProduct& operator=(const PhysicalProduct& other); 

    void printInfo() const override;
    double getPrice() const override;
    void applyDiscount() override;

    ~PhysicalProduct();
};