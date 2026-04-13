#pragma once
#include <vector>
#include <memory>
#include <fstream>
#include <iostream>
#include "Product.h"
#include "PhysicalProduct.h"
#include "DigitalProduct.h"

class Store {
private:
    std::vector<std::shared_ptr<Product>> products;

public:
    void addProduct(std::shared_ptr<Product> product);
    void showProducts() const;

    void saveToFile();
    void loadFromFile();
};