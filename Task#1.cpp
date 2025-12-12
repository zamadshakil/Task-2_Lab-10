
#include <iostream>
#include <string>
using namespace std;

class Book {
private:
	string title;
	string author;

public:
	Book(const string& t, const string& a) : title(t), author(a) {}

	string getTitle() const { return title; }
	string getAuthor() const { return author; }
};

class Library {
public:
	void displayBook(const Book& book) {
		cout << "Title: " << book.getTitle() << endl;
		cout << "Author: " << book.getAuthor() << endl;
		cout << "------------------------" << endl;
	}
};

int main()
{
	Book book1("The Great Gatsby", "F. Scott Fitzgerald");
	Book book2("1984", "George Orwell");

	Library library;

	library.displayBook(book1);
	library.displayBook(book2);

	return 0;
}
