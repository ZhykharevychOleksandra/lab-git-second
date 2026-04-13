#pragma once
#include "Product.h"

class DigitalProduct final : public Product {
private:
    double fileSize;

public:
    DigitalProduct(int id = 0,
        std::string name = "Unknown",
        double price = 0.0,
        double fileSize = 0.0);

    void printInfo() const override;
    double getPrice() const override;
    void applyDiscount() override;

    ~DigitalProduct();
};