#include "Book.h"
#include <iostream>

using namespace std;

// Getters
string Book::getISBN() const {
    return isbn;
}

string Book::getTitle() const {
    return title;
}

string Book::getAuthor() const {
    return author;
}

int Book::getPublicationYear() const {
    return publicationYear;
}

// Setters
void Book::setISBN(const string& newIsbn) {
    if (newIsbn.length() == 13) {
        isbn = newIsbn;
    }
    else {
        cerr << "Errore: l'ISBN deve contenere esattamente 13 caratteri." << endl;
    }
}

void Book::setTitle(const string& newTitle) {
    title = newTitle;
}

void Book::setAuthor(const string& newAuthor) {
    author = newAuthor;
}

void Book::setPublicationYear(int newPublicationYear) {
    // Ottieni l'anno corrente in modo sicuro con localtime_s
    time_t now = time(0);
    tm localTime;

    if (localtime_s(&localTime, &now) != 0) {
        std::cerr << "Errore: impossibile ottenere la data corrente." << std::endl;
        return;
    }

    int currentYear = localTime.tm_year + 1900;

    if (newPublicationYear > 0 && newPublicationYear <= currentYear) {
        publicationYear = newPublicationYear;
    }
    else {
        std::cerr << "Errore: l'anno di pubblicazione deve essere compreso tra 1 e "
            << currentYear << "." << std::endl;
    }
}

// Display book information
void Book::displayInfo() const {
    cout << "Book Information:" << endl;
    cout << "ISBN: " << isbn << endl;
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Publication Year: " << publicationYear << endl;
}