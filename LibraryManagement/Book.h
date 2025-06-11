#pragma once
#include <string>
using namespace std;



class Book
{
	private:
		string isbn;
		string title;
		string author;
		int publicationYear;
	public:
		// Constructor
		Book(string isbn, string title, string author, int publicationYear)
			: isbn(isbn), title(title), author(author), publicationYear(publicationYear) {}

		// Getters
		string getISBN() const;
		string getTitle() const;
		string getAuthor() const;
		int getPublicationYear() const;
		// Setters
		void setISBN(const string& newIsbn);
		void setTitle(const string& newTitle);
		void setAuthor(const string& newAuthor);
		void setPublicationYear(int newPublicationYear);

		// Display book information
		void displayInfo() const;
};

