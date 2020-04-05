#include <iostream>
#include "list.cpp"
#include "book.h"
using namespace std;

int main() {
	List<book> l;
	List<book>::position index = l.first();
	if (l.isEmpty()) {
		cout << "List is empty." << endl;
	}
	book b;

	cout << "Inserting items of type \"book\" into the list..." << endl;
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
	cout << "List length: " << l.getLength() << '\n';
	cout << "List capacity: " << l.getCapacity() << "\n\n";
	b.setTitle("Oriental Carpet Design");
	l.insert(b, 2);
	b.setTitle("Encyclopedia of Natural Medicine");
	l.insert(b, l.next(l.first()));
	l.insert(b, l.next(l.first()));
	l.insert(b, l.next(l.first()));
	l.insert(b, l.next(l.first()));
	l.insert(b, l.next(l.first()));
	l.print();
	cout << "List length: " << l.getLength() << '\n';
	cout << "List capacity: " << l.getCapacity() << "\n\n";

	cout << "Overwriting content of positions 6 and 9...\n";
	b.setTitle("Satanism and Witchcraft");
	l.write(b, 6);
	b.setTitle("The Long, Dark Tea-Time of the Soul");
	l.write(b, 9);
	//l.write(b, 12);	Throws an error as expected.
	l.insert(b, 12);
	l.print();
	cout << "List length: " << l.getLength() << "\n\n";

	l.insert(b, 17);	//	Does nothing because the specified position is beyond the current length.

	cout << "Removing items from the list...\n";
	l.remove(4);
	l.remove(l.prev(4));
	//l.remove(15);		Throws an error as expected.
	l.print();
	cout << "List length: " << l.getLength() << "\n\n";
	cout << "Removing duplicates...\n";
	l.removeDuplicates();
	l.print();
	cout << "List length: " << l.getLength() << "\n";

	return 0;
}