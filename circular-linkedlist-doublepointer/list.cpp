#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "node.h"

template<typename T>
class list {
public:
	typedef node<T>* position;
	typedef typename node<T>::item item;

	list();
	list(const list<T>&);
	~list();

	//	Operators
	void init();
	bool isEmpty() const;
	item read(position) const;
	void write(item, position);
	position first() const;
	bool endOfList(position) const;
	//bool contains(item) const;
	position next(position) const;
	position prev(position) const;
	position find(item) const;
	void insert(item, position&);
	void remove(position&);
	void removeDuplicates();
	void orderAscending();
	void print();
private:
	position listId;
};

template<typename T>
list<T>::list() { init(); }

template<typename T>
list<T>::list(const list<T>& l) {}

template<typename T>
list<T>::~list() {}

template<typename T>
void list<T>::init() {
	typename list<T>::item nullItem;
	listId = new node<T>;
	listId->setLabel(nullItem);
	listId->setNext(listId);
	listId->setPrev(listId);
}

template<typename T>
bool list<T>::isEmpty() const { 
	return ((listId->getNext() == listId) && (listId->getPrev() == listId)); 
}

template<typename T>
typename list<T>::position list<T>::first() const { return listId->getNext(); }

template<typename T>
typename list<T>::position list<T>::next(position p) const { 
	return p->getNext(); 
}

template<typename T>
typename list<T>::position list<T>::prev(position p) const { 
	return p->getPrev(); 
}

template<typename T>
typename list<T>::position list<T>::find(typename list<T>::item t) const {
	//	Returns the position of the item passed to it if found
	//	or the position where it should be within the list if not found.
	//	Assumes the contents of the list are in ascending order.
	list<T>::item currentItem;
	list<T>::position current = first();
	list<T>::position previous = current;
	bool continueSearching = true;
	bool found = false;
	
	while (continueSearching && !endOfList(current)) {
		currentItem = read(current);
		if (t <= currentItem) continueSearching = false;
		else {
			previous = current;
			current = next(current);
		}
	}
	
	found = (t == currentItem);
	if (found) std::cout << "Item found.\n";
	else
		std::cout << "Item not present in list.\n";
	return current;
}

template<typename T>
bool list<T>::endOfList(position p) const { return p == listId; }



template<typename T>
typename list<T>::item list<T>::read(position p) const { return p->getLabel(); }

template<typename T>
void list<T>::write(typename list<T>::item t, position p) { p->setLabel(t); }

template<typename T>
void list<T>::insert(typename list<T>::item t, position& p) {
	list<T>::position temp;
	temp = new node<T>;
	temp->setLabel(t);
	temp->setPrev(p->getPrev());
	temp->setNext(p);
	(p->getPrev())->setNext(temp);
	p->setPrev(temp);
	p = temp;	
}

template<typename T>
void list<T>::remove(position& p) {
	list<T>::position temp;
	temp = p;
	(p->getNext())->setPrev(p->getPrev());
	(p->getPrev())->setNext(p->getNext());
	p = p->getNext();
	delete temp;
}

template<typename T>
void list<T>::removeDuplicates() {
	list<T>::position p, q, r;
	p = first();
	while (!endOfList(p)) {
		q = next(p);
		while (!endOfList(q)) {
			if (read(p) == read(q)) {
				r = next(q);
				remove(q);
				q = r;
			} else q = next(q);
		}
		p = next(p);
	}
}

template<typename T>
void list<T>::orderAscending() {
	
}

template<typename T>
void list<T>::print() {
	list<T>::position p = first();
	while (!endOfList(p)) {
		std::cout << read(p) << '\n';
		p = next(p);
	}
}

#endif // !LIST_H
