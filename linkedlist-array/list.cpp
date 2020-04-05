#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "node.cpp"
#include "book.h"

template<typename T>
class List {
	const static int MAX_LENGTH = 1024;
	typedef typename Node<T>::item item;
public:
	typedef int position;
	
	List();
	List(int);
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
	void print();
private:
	Node<T> contents[MAX_LENGTH];
	int length;
};

template<typename T>
List<T>::List() { init(); }

template<typename T>
List<T>::List(int size) { length = size; }

template<typename T>
List<T>::List(const List<T>& l) {
	//	Change max_length to a dynamic size variable
	length = l.length;
	contents = new Node<T>[MAX_LENGTH];
	for (int i = 0; i < l.length; i++)
		contents[i] = l.contents[i];
}

template<typename T>
List<T>::~List() {}

template<typename T>
void List<T>::init() { length = 0; } //	Default value

template<typename T>
void List<T>::changeCapacity(Node<T>*& a, int currentSize, int newSize) {
	if (newSize < 0) throw out_of_range("List::changeCapacity()");

	Node<T>* temp = new T[newSize];
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
	return contents[p - 1];
}

template<typename T>
void List<T>::write(item t, position p) {
	if (!isValid(p)) 
		throw std::out_of_range{"List::write()"};
	contents[p - 1] = t;
}

template<typename T>
void List<T>::insert(item t, position p) {
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
void List<T>::print() {
	if (!isEmpty())
		for (int i = 1; i <= length; i++) {
			std::cout << contents[i - 1].readLabel() << ' ';

			if (i % 10 == 0) std::cout << '\n';
		}

	std::cout << std::endl;
}

#endif // !LIST_H
