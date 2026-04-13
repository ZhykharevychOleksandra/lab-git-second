#pragma once
#include <string>
#include <iostream>
 
class Product {
protected:
    int id;
    std::string name;
    double price;

    static int productCount; // static поле

public:
    Product();
    Product(int id, std::string name, double price);

    // 1 Copy constructor
    Product(const Product& other);

    // 2 Move constructor
    Product(Product&& other) noexcept;

    //void printInfo() const;

    // 3 this
    //void setPrice(double price);

    // 4 const
    //double getPrice() const;

    virtual void printInfo() const;
    virtual double getPrice() const;
    virtual void applyDiscount();

    void setPrice(double price);

    // 5 static
    static int getProductCount();

    // 6 оператори
    Product operator+(const Product& other);
    Product& operator++(); // unary

    // 7 stream оператори
    friend std::ostream& operator<<(std::ostream& os, const Product& product);
    friend std::istream& operator>>(std::istream& is, Product& product);

    virtual ~Product();
};

