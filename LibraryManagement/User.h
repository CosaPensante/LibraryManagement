#pragma once
#include <string>

class User {
private:
    int id;
    std::string firstName;
    std::string lastName;
    std::string email;

public:
    // Constructor
    User(int id, const std::string& firstName, const std::string& lastName, const std::string& email);

    // Getters
    int getId() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getEmail() const;

    // Setters
    void setFirstName(const std::string& newFirstName);
    void setLastName(const std::string& newLastName);
    void setEmail(const std::string& newEmail);

    // Print method
    void print() const;
};
