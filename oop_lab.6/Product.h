#pragma once
#include <string>
#include <iostream>

class Product {
protected:
    int id;
    std::string name;
    double price;

    static int productCount;

public:
    Product();
    Product(int id, std::string name, double price);

    Product(const Product& other);
    Product(Product&& other) noexcept;

    virtual void printInfo() const;
    virtual double getPrice() const;

    //pure virtual
    virtual void applyDiscount() = 0;

    void setPrice(double price);

    static int getProductCount();

    Product& operator++();

    friend std::ostream& operator<<(std::ostream& os, const Product& product);
    friend std::istream& operator>>(std::istream& is, Product& product);

    virtual ~Product();
};