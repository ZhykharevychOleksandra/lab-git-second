#pragma once
#include <string>
#include <iostream>

class Customer {
private:
    int id;
    std::string name;
    std::string email;

    static int customerCount;

public:
    Customer(int id = 0,
        std::string name = "Unknown",
        std::string email = "mail@gmail.com");

    // Copy constructor
    Customer(const Customer& other);

    // Move constructor
    Customer(Customer&& other) noexcept;

    void printInfo() const;

    // this
    void setEmail(std::string email);

    // const
    std::string getEmail() const;

    // static
    static int getCustomerCount();

    // <<
    friend std::ostream& operator<<(std::ostream& os, const Customer& c);

    // >>
    friend std::istream& operator>>(std::istream& is, Customer& c);

    ~Customer();
};