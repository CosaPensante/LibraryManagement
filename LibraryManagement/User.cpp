#include "User.h"
#include <iostream>

using namespace std;

// Constructor
User::User(int id, const string& firstName, const string& lastName, const string& email)
    : id(id), firstName(firstName), lastName(lastName), email(email) {}

// Getters
int User::getId() const { return id; }
string User::getFirstName() const { return firstName; }
string User::getLastName() const { return lastName; }
string User::getEmail() const { return email; }

// Setters
void User::setFirstName(const string& newFirstName) { firstName = newFirstName; }
void User::setLastName(const string& newLastName) { lastName = newLastName; }
void User::setEmail(const string& newEmail) { email = newEmail; }

// Print method
void User::print() const {
    cout << "User [" << id << "] - " << firstName << " " << lastName
        << " | Email: " << email << endl;
}
