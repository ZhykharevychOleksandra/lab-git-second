#pragma once
#include <string>

class Customer {
private:
    int id;
    std::string name;
    std::string email;

public:
    Customer(int id = 0,
        std::string name = "Unknown",
        std::string email = "mail@gmail.com");

    void printInfo() const;
    ~Customer();
};

