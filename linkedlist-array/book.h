#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
using namespace std;

class book {
public:
	book();
	book(string);
	void setTitle(string);
	string getTitle() const;
	bool operator==(book);
	friend ostream& operator<<(ostream& out, const book& b) {
		out << b.getTitle();
		return out;
	}
private:
	string title;
};

#endif // !BOOK_H