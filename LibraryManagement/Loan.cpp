#include "Loan.h"
#include <iostream>

#include <sstream>
#include <iomanip>

using namespace std;

// Utility: Add one month to a YYYY-MM-DD date
string Loan::calculateDefaultReturnDate(const string& loanDate) {
    int year, month, day;
    char sep1, sep2;

    istringstream iss(loanDate);
    iss >> year >> sep1 >> month >> sep2 >> day;

    if (sep1 != '-' || sep2 != '-' || iss.fail()) {
        return ""; // Invalid format
    }

    // Add one month
    month += 1;
    if (month > 12) {
        month = 1;
        year++;
    }

    // Adjust day if necessary (e.g. Feb 30)
    static const int daysInMonth[] = {
        31,28,31,30,31,30,31,31,30,31,30,31
    };

    int maxDay = daysInMonth[month - 1];
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
        maxDay = 29; // Leap year
    }

    if (day > maxDay) {
        day = maxDay;
    }

    ostringstream oss;
    oss << setw(4) << setfill('0') << year << "-"
        << setw(2) << setfill('0') << month << "-"
        << setw(2) << setfill('0') << day;

    return oss.str();
}

// Constructor
Loan::Loan(int id, int userId, const string& isbn, const string& loanDate, const string& returnDate)
    : id(id), userId(userId), isbn(isbn), loanDate(loanDate), returnDate(returnDate) {}

// Getters
int Loan::getId() const { return id; }
int Loan::getUserId() const { return userId; }
string Loan::getIsbn() const { return isbn; }
string Loan::getLoanDate() const { return loanDate; }
string Loan::getReturnDate() const { return returnDate; }

// Setters
void Loan::setUserId(int newUserId) { userId = newUserId; }
void Loan::setIsbn(const string& newIsbn) { isbn = newIsbn; }
void Loan::setLoanDate(const string& newLoanDate) { loanDate = newLoanDate; }
void Loan::setReturnDate(const string& newReturnDate) { returnDate = newReturnDate; }

// Print method
void Loan::print() const {
    cout << "Loan [" << id << "] - User ID: " << userId
        << ", ISBN: " << isbn
        << ", Loan Date: " << loanDate
        << ", Return Date: " << (returnDate.empty() ? "Not returned" : returnDate)
        << endl;
}