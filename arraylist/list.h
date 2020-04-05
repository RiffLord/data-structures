#ifndef LIST_H
#define LIST_H

#include<iostream>
#include <cstddef>
#include <stdexcept>

template<class T>
class List {
	const static int MAX_LENGTH = 1024;
	typedef T item;
	typedef int position;
public:
	List();
	List(int);
	~List();
	void init();
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
	int length;
	item contents[MAX_LENGTH];
};

template<class T>
List<T>::List() { init(); }

template<class T>
List<T>::List(int listSize) {
	init();
	length = listSize;
}

template<class T>
List<T>::~List() {}

template<class T>
void List<T>::init() {
	length = 0;	//	Default value
}

template<class T>
bool List<T>::isEmpty() const { return length == 0; }

template<class T>
bool List<T>::isValid(position p) const { return (0 < p && p < length + 1); }

template<class T>
bool List<T>::endOfList(position p) const {
	if (0 < p && p <= length + 1) return (p == length + 1);
	else return false; 
}           

template<class T>
typename List<T>::position List<T>::first() const { return 1; }

template<class T>
typename List<T>::position List<T>::next(position p) const {
	if (isValid(p)) return p + 1;
	else
		return p;
}

template<class T>
typename List<T>::position List<T>::prev(position p) const {
	if (first() < p && !endOfList(p)) return p - 1;
	else
		return p;
}

template<class T>
typename List<T>::item List<T>::read(position p) const {
	if (!isValid(p)) 
		throw std::out_of_range{"List::read()"};
	return contents[p - 1];
}

template<class T>
void List<T>::write(item t, position p) {
	if (!isValid(p)) 
		throw std::out_of_range{"List::write()"};
	contents[p - 1] = t;
}

template<class T>
void List<T>::insert(item t, position p) {
	if (0 < p && p <= length + 1) {
		for (int i = length; i >= p; i--) contents[i] = contents[i - 1];
		contents[p - 1] = t;
		length++;
	}
}

template<class T>
void List<T>::remove(position p) {
	if (!isValid(p)) throw std::out_of_range{"List::remove()"};

	if (!isEmpty()) {
		for (int i = p - 1; i < length - 1; i++) contents[i] = contents[i + 1];
		length--;
	}
}

template<class T>
void List<T>::print() {
	if (!isEmpty())
		for (int i = 1; i <= length; i++) {
			std::cout << contents[i - 1] << ' ';

			if (i % 10 == 0) std::cout << '\n';
		}

	std::cout << std::endl;
}

template<class T>
std::ostream& operator<<(std::ostream& out, const typename List<T>::item t) {
	out << t << " ";
	return out;
}

#endif //!LIST_H
