#pragma once
#include <string>

class Loan {
private:
    int id;
    int userId;               // ID of the user who borrowed the book
    std::string isbn;         // ISBN of the borrowed book
    std::string loanDate;     // Date when the book was borrowed
    std::string returnDate;   // Date when the book was returned (or empty if not returned)

    std::string calculateDefaultReturnDate(const std::string& loanDate);

public:
    // Constructor
    Loan(int id, int userId, const std::string& isbn);

    // Getters
    int getId() const;
    int getUserId() const;
    std::string getIsbn() const;
    std::string getLoanDate() const;
    std::string getReturnDate() const;

    // Setters
    void setUserId(int newUserId);
    void setIsbn(const std::string& newIsbn);
    void setLoanDate(const std::string& newLoanDate);
    void setReturnDate(const std::string& newReturnDate);

    // Print method
    void print() const;
};