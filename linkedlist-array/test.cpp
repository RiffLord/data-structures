#include <iostream>
#include "list.cpp"
#include "book.h"
using namespace std;

int main() {
	List<book> l;
	List<book>::position index = l.first();
	book b;

	b.setTitle("The Hitch-Hiker's Guide to the Galaxy");
	l.insert(b, index = l.next(index));
	b.setTitle("The Holy Bible");
	l.insert(b, index = l.next(index));
	b.setTitle("The Colour of Magic");
	l.insert(b, index = l.next(index));
	b.setTitle("War and Peace");
	l.insert(b, index = l.next(index));
	b.setTitle("Dirk Gently's Holistic Detective Agency");
	l.insert(b, index = l.next(index));
	l.print();
	b.setTitle("Oriental Carpet Design");
	l.insert(b, 2);
	b.setTitle("Encyclopedia of Natural Medicine");
	l.insert(b, l.next(l.first()));
	l.print();

	return 0;
}