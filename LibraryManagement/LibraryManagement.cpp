// LibraryManagement.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

#include <conio.h>  // _getch
#include <windows.h> // SetConsoleCursorPosition

#include "Book.h"
#include "User.h"
#include "Loan.h"

using namespace std;


void printMenu(const vector<string>& options, int selectedIndex) {
    system("cls"); // clear screen

    cout << "=== Library Management ===" << endl << endl;

    for (size_t i = 0; i < options.size(); ++i) {
        if (i == selectedIndex) {
            cout << " > " << options[i] << endl;
        }
        else {
            cout << "   " << options[i] << endl;
        }
    }
}

void addUser(vector<User>& users) {
	int id;
	string firstName, lastName, email;

	cout << "Enter User ID: ";
	cin >> id;
	cin.ignore(); // Clear newline character from input buffer

	cout << "Enter First Name: ";
	getline(cin, firstName);

	cout << "Enter Last Name: ";
	getline(cin, lastName);

	cout << "Enter Email: ";
	getline(cin, email);

	users.emplace_back(id, firstName, lastName, email);
}
void addBook(vector<Book>& books) {
	string isbn, title, author;
	int publicationYear;

	cout << "Enter ISBN (13 characters): ";
	cin >> isbn;
	cin.ignore(); // Clear newline character from input buffer

	cout << "Enter Title: ";
	getline(cin, title);

	cout << "Enter Author: ";
	getline(cin, author);

	cout << "Enter Publication Year: ";
	cin >> publicationYear;

	books.emplace_back(isbn, title, author, publicationYear);
}
void createLoan(vector<Loan>& loans, const vector<User>& users, const vector<Book>& books) {
    int loanId, userId, bookId;

    cout << "Enter Loan ID for Loan: ";
    cin >> loanId;

    // 🔍 Verifica che l'ID del prestito non esista già
    auto existingLoan = find_if(loans.begin(), loans.end(), [loanId](const Loan& l) {
        return l.getId() == loanId;
        });

    if (existingLoan != loans.end()) {
        cout << "Errore: esiste già un prestito con ID " << loanId << "." << endl;
        return;
    }

    cout << "Enter User ID for Loan: ";
    cin >> userId;

    cout << "Enter Book ID for Loan: ";
    cin >> bookId;

    // 🔍 Verifica che l'utente esista
    auto userIt = find_if(users.begin(), users.end(), [userId](const User& u) {
        return u.getId() == userId;
        });

    // 🔍 Verifica che il libro esista (confronta ID libro con ISBN convertito in int)
    auto bookIt = find_if(books.begin(), books.end(), [bookId](const Book& b) {
        return stoi(b.getISBN()) == bookId;
        });

    if (userIt != users.end() && bookIt != books.end()) {
        // ✅ Crea il prestito con data automatica
        loans.emplace_back(loanId, userId, bookIt->getISBN());
        cout << "Loan created successfully!" << endl;
    }
    else {
        cout << "Invalid User ID or Book ID." << endl;
    }
}

void listUsers(const vector<User>& users) {
	cout << "=== List of Users ===" << endl;
	for (const auto& user : users) {
		user.print();
	}
}
void listBooks(const vector<Book>& books) {
	cout << "=== List of Books ===" << endl;
	for (const auto& book : books) {
		book.displayInfo();
	}
}
void listLoans(const vector<Loan>& loans) {
	cout << "=== List of Loans ===" << endl;
	for (const auto& loan : loans) {
		loan.print();
	}
}

int main()
{
    vector<Book> books;
    vector<User> users; 
    vector<Loan> loans;

    vector<string> menuOptions = {
        "Add User",
        "Add Book",
        "Create Loan",
        "List All Users",
        "List All Books",
        "List All Loans",
        "Exit"
    };

    int selected = 0;
    const int ENTER = 13;
    const int UP = 72;
    const int DOWN = 80;

    while (true) {
        printMenu(menuOptions, selected);

        int key = _getch();

        if (key == 224) { // arrow keys
            int arrow = _getch();

            if (arrow == UP && selected > 0) {
                selected--;
            }
            else if (arrow == DOWN && selected < menuOptions.size() - 1) {
                selected++;
            }
        }
        else if (key == ENTER) {
            system("cls");

            switch (selected) {
            case 0:
                addUser(users);
                break;
            case 1:
                addBook(books);
                break;
            case 2:
                createLoan(loans, users, books);
                break;
            case 3:
                listUsers(users);
                break;
            case 4:
                listBooks(books);
                break;
            case 5:
                listLoans(loans);
                break;
            case 6:
                cout << "Exiting..." << endl;
                return 0; // exit the program
            default:
                cout << "Invalid option selected." << endl;
                break;
            }

            system("pause"); // Wait for user to press a key
        }
    }

    return 0;
}