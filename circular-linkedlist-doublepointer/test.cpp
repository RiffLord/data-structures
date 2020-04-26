#include <iostream>
#include "linked_list.h"
#include "util.h"

using namespace std;

int main() {
	linked_list<int> list, list2;
	linked_list<int>::position index = list.first();
	
	int x = 1;
	list.insert(x, index);
	x = 2;
	list.insert(x, index);
	x = 3;
	list.insert(x, index);
	x = 4;
	list.insert(x, index);
	
	cout << "List:\n";
	cout << list;
	
	list2 = list;
	cout << "Assigned list to list2.\n";
	cout << list2;
	
	if (list == list2) cout << "list == list2" << endl;
	else cout << "list != list2" << endl;
	
	list2.remove(list2.first());
	cout << "Removed the first item from list2.\n";
	
	if (list == list2) cout << "list == list2" << endl;
	else cout << "list != list2" << endl;

	cout << "list after inverting order of items:\n";
	invert(list);
	cout << list;
	cout << "Is list a palindrome? " << (isPalindrome(list) ? "true" : "false") << endl;
	
	cout << "Clearing list.\n";
	list.clear();
	cout << list << endl;
	index = list.first();
	list.insert(1, index);
	list.insert(2, index);
	list.insert(1, index);
	list.insert(3, index);
	list.insert(1, index);
	list.insert(2, index);
	list.insert(1, index);
	cout << list << endl;
	cout << "Is list a palindrome? " << (isPalindrome(list) ? "true" : "false") << endl;
	
	cout << "list2:\n";
	cout << list2;
	invert(list2);
	cout << "list2 after inverting order of items:\n";
	cout << list2;
	list2.write(2, list2.first());
	cout << list2;
	cout << "Is list2 a palindrome? " << (isPalindrome(list2) ? "true" : "false");
}