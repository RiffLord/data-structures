#include <iostream>
#include "list.cpp"
#include "util.h"
using namespace std;

int main() {
 	list<int> numbers;
 	list<int>::position index = numbers.first();
 	
 	if (numbers.isEmpty()) cout << "List is empty.\n";
 	
 	numbers.insert(1, index = numbers.next(index));
 	numbers.insert(2, index = numbers.next(index));
 	numbers.insert(3, index = numbers.next(index));
 	numbers.insert(4, index = numbers.next(index));
 	numbers.insert(5, index = numbers.next(index));
 	
 	if (!numbers.isEmpty()) cout << "List has been populated.\n";
 	
 	numbers.print();
 	cout << "Removing an item from the list.\n";
 	numbers.remove(index = numbers.prev(index));
 	numbers.print();
 	
 	cout << "Overwriting an item.\n";
 	numbers.write(0, numbers.first());
 	numbers.print();
 	
 	cout << "Inserting duplicates into the list.\n";
 	numbers.insert(42, index = numbers.next(index));
 	numbers.insert(42, index = numbers.next(index));
 	numbers.insert(42, index = numbers.next(index));
 	numbers.insert(0, index = numbers.next(index));
 	numbers.print();
 	cout << "Removing duplicates...\n";
 	numbers.removeDuplicates();
 	numbers.print();
 	
 	cout << "Searching for the position of 3.\n";
 	list<int>::position n = numbers.find(3);
 	cout << numbers.read(n) << " at location " << n << endl;
 	cout << "Searching for the position of 4.\n";
 	list<int>::position p = numbers.find(4);
 	numbers.insert(4, p);
 	numbers.print();
 	cout << "Searching for the position of 4.\n";
 	list<int>::position q = numbers.find(4);
 	cout << numbers.read(q) << " at location " << q << endl;
 	
 	list<int> moreNumbers;
 	index = moreNumbers.first();
 	
 	cout << "Another list:\n";
 	moreNumbers.insert(1, index = moreNumbers.next(index));
 	moreNumbers.insert(4, index = moreNumbers.next(index));
 	moreNumbers.insert(5, index = moreNumbers.next(index));
 	moreNumbers.insert(6, index = moreNumbers.next(index));
 	moreNumbers.insert(8, index = moreNumbers.next(index));
 	moreNumbers.insert(10, index = moreNumbers.next(index));
 	moreNumbers.print();
 	
 	cout << "Merging the two lists...\n";
 	list<int> megaList = merge(numbers, moreNumbers);
 	megaList.print();
 	
	return 0;
}
