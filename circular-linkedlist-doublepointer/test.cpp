#include <iostream>
#include "linked_list.hpp"

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
	
	cout << "Clearing list.\n";
	list.clear();
	cout << list << endl;
	
	cout << "list2:\n";
	cout << list2;
}