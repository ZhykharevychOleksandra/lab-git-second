#pragma once
#include <string>
#include <iostream>
#include "Person.h" 

class Customer : public Person {
private:
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

    void setEmail(std::string email);

    std::string getEmail() const;

    static int getCustomerCount();

    friend std::ostream& operator<<(std::ostream& os, const Customer& c);
    friend std::istream& operator>>(std::istream& is, Customer& c);

    ~Customer();
};