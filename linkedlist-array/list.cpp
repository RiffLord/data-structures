#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "node.cpp"
#include "book.h"

template<typename T>
class List {
	typedef typename Node<T>::item item;
public:
	typedef int position;
	
	List(int s = 10);
	List(const List<T>&);	//	Copy constructor
	~List();

	//	Operators
	void init();
	void changeCapacity(Node<T>*&, int, int);
	bool isEmpty() const;
	bool isValid(position) const;
	bool endOfList(position) const;
	position first() const;
	position next(position) const;
	position prev(position) const;
	item read(position) const;
	void write(item, position);
	void insert(item, position);
	void remove(position);
	void removeDuplicates();
	void print();

	//	Auxiliary functions to check the status of the list
	int getLength() const;
	int getCapacity() const;
private:
	Node<T>* contents;
	int length, capacity;
};

//==================== Constructors/destructor ====================

template<typename T>
List<T>::List(int s) {
	capacity = s;
	contents = new Node<T>[capacity]; 
	this->init(); 
}

template<typename T>
List<T>::List(const List<T>& l) {
	this->length = l.length;
	this->capacity = l.capacity;
	this->contents = new Node<T>[capacity];
	for (int i = 0; i < l.length; i++)
		this->contents[i] = l.contents[i];
}

template<typename T>
List<T>::~List() { delete[] contents; }

//==================== Operators ======================

template<typename T>
void List<T>::init() { length = 0; } //	Default value

template<typename T>
void List<T>::changeCapacity(Node<T>*& a, int currentSize, int newSize) {
	if (newSize < 0) throw out_of_range("List::changeCapacity()");

	capacity = newSize;
	Node<T>* temp = new Node<T>[capacity];

	int numberOfItems;
	if (currentSize < newSize) numberOfItems = currentSize;
	else
		numberOfItems = newSize;

	for (int i = 0; i < numberOfItems; i++) temp[i] = a[i];
	delete[] a;
	a = temp;
}

template<typename T>
bool List<T>::isEmpty() const { return length == 0; }

template<typename T>
bool List<T>::isValid(position p) const { return (0 < p && p < length + 1); }

template<typename T>
bool List<T>::endOfList(position p) const {
	if (0 < p && p <= length + 1) return (p == length + 1);
	else return false; 
}           

template<typename T>
typename List<T>::position List<T>::first() const { return 1; }

template<typename T>
typename List<T>::position List<T>::next(position p) const {
	if (isValid(p)) return p + 1;
	else
		return p;
}

template<typename T>
typename List<T>::position List<T>::prev(position p) const {
	if (first() < p && !endOfList(p)) return p - 1;
	else
		return p;
}

template<typename T>
typename List<T>::item List<T>::read(position p) const {
	if (!isValid(p)) 
		throw std::out_of_range{"List::read()"};
	return contents[p - 1].readLabel();
}

template<typename T>
void List<T>::write(item t, position p) {
	if (!isValid(p)) 
		throw std::out_of_range{"List::write()"};
	contents[p - 1] = t;
}

template<typename T>
void List<T>::insert(item t, position p) {
	if (length == capacity) changeCapacity(contents, length, length * 2);
	if (0 < p && p <= length + 1) {
		for (int i = length; i >= p; i--) contents[i] = contents[i - 1];
		contents[p - 1] = t;
		length++;
	}
}

template<typename T>
void List<T>::remove(position p) {
	if (!isValid(p)) throw std::out_of_range{"List::remove()"};

	if (!isEmpty()) {
		for (int i = p - 1; i < length - 1; i++) contents[i] = contents[i + 1];
		length--;
	}
}

template<typename T>
void List<T>::removeDuplicates() {
	typename List<T>::position p, q;
	p = first();

	while(!endOfList(p)) {
		q = next(p);
		while(!endOfList(q)) {
			if (read(p) == read(q)) remove(q);
			else q = next(q);
		}
		p = next(p);
	}
}

template<typename T>
void List<T>::print() {
	if (!isEmpty())
		for (int i = 1; i <= length; i++)
			std::cout << contents[i - 1].readLabel() << '\n';

	std::cout << std::endl;
}

template<typename T>
int List<T>::getLength() const { return length; }

template<typename T>
int List<T>::getCapacity() const { return capacity; }

#endif // !LIST_H
