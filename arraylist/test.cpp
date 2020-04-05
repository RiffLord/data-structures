#include <iostream>
#include "list.h"

int main() {
	List<char> characters;
	characters.insert(';', characters.first());
	characters.insert('o', characters.next(characters.first()));
	characters.insert('5', characters.next(characters.next(characters.first())));
	characters.insert('i', characters.first());
	characters.print();

	List<int> integers;
	integers.insert(4, integers.first());
	integers.insert(3, integers.next(integers.first()));
	integers.insert(4, integers.next(integers.next(integers.first())));
	integers.insert(7, integers.next(integers.next(integers.next(integers.first()))));
	integers.insert(1, integers.next(integers.next(integers.next(integers.first()))));
	integers.print();
	integers.insert(9, integers.first());
	integers.print();
	integers.insert(42, integers.first());
	integers.print();

	return 0;
}