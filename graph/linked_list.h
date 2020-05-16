#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <assert.h>
#include "virtual_list.h"

template<class T>
class linked_list;

template<class T>
class listNode {
	//	Allows the linked_list class to access the listNode's private members.
	friend class linked_list<T>;
public:
	T getData() const { return data; }
private:
	T data;
	listNode<T>* prev;
	listNode<T>* next;
};

template<class T>
class linked_list : public virtual_list<T, listNode<T>*> {

	friend ostream& operator<<(ostream& out, const linked_list<T>& L) {
		listNode<T>* temp = L.first();
		if (!L.isEmpty()) {
			do {
				out << L.read(temp);
				temp = L.next(temp);
			} while (!L.end(temp));
			out << std::endl;
		}
		return out;
	}

public:
	typedef typename virtual_list<T, listNode<T>*>::data_type data_type;
	typedef typename virtual_list<T, listNode<T>*>::position position;
	
	linked_list();
	linked_list(const linked_list<T>&);
	~linked_list();
	
	//	Operators
	void init();
	bool isEmpty() const;
	data_type read(position) const;
	void write(const data_type&, position);
	position first() const;
	position last() const;
	bool end(position) const;
	position next(position) const;
	position previous(position) const;
	void insert(const data_type&, position);
	void remove(position);
	
	//	Additional functions
	int size() const;
	void clear();
	
	//	Operator overloads
	linked_list<T>& operator=(const linked_list<T>&);
	bool operator==(const linked_list<T>&) const;

private:
	listNode<T>* head;
	int length;
};

//==================== Constructors/destructors ====================

template<class T>
linked_list<T>::linked_list() {
	head = new listNode<T>;
	head->next = head;
	head->prev = head;
	length = 0;
}

template<class T>
linked_list<T>::linked_list(const linked_list<T>& L) {
	head = new listNode<T>;
	head->next = head;
	head->prev = head;
	
	if (!L.isEmpty()) {
		position p = L.last();
		for (int i = 0; i <= L.length; i++) {
			insert(L.read(p), first());
			p = L.previous(p);
		}
	}
}

template<class T>
linked_list<T>::~linked_list() {
	while (!isEmpty()) remove(first());
	
	delete head;
}

//==================== Operators ====================

template<class T>
void linked_list<T>::init() {
	if (isEmpty()) length = 0;
}

template<class T>
bool linked_list<T>::isEmpty() const { return head == head->next; }

template<class T>
typename linked_list<T>::position linked_list<T>::first() const { return head->next; }

template<class T>
typename linked_list<T>::position linked_list<T>::last() const { return head->prev; }

template<class T>
typename linked_list<T>::position linked_list<T>::next(position p) const { return p->next; }

template<class T>
typename linked_list<T>::position linked_list<T>::previous(position p) const {
	assert(p != head);
	return p->prev;
}

template<class T>
bool linked_list<T>::end(position p) const { return p == head; }

template<class T>
typename linked_list<T>::data_type linked_list<T>::read(position p) const {
	assert(!end(p));
	return p->data;
}

template<class T>
void linked_list<T>::write(const data_type& d, position p) {
	if (!end(p)) p->data = d;
}

template<class T>
void linked_list<T>::insert(const data_type& d, position p) {
	position q = new listNode<T>;
	q->data = d;
	
	q->next = p;
	q->prev = p->prev;
	(p->prev)->next = q;
	p->prev = q;
	
	length++;
}

template<class T>
void linked_list<T>::remove(position p) {
	if (!isEmpty() && !end(p)) {
		(p->prev)->next = p->next;
		(p->next)->prev = p->prev;
		length--;
		delete p;
	}
}

//==================== Additional functions ====================

template<class T>
int linked_list<T>::size() const { return length; }

template<class T>
void linked_list<T>::clear() { while (!isEmpty()) remove(first()); }

//==================== Operator overloads ====================

template<class T>
linked_list<T>& linked_list<T>::operator=(const linked_list<T>& L) {
	if (this != &L) {
		head = new listNode<T>;
		head->next = head;
		head->prev = head;
		
		if (!L.isEmpty()) {
			position p = L.last();
			for (int i = 0; i < L.size(); i++) {
				insert(L.read(p), first());
				p = L.previous(p);
			}
		}
	}
	
	return *this;
}

template<class T>
bool linked_list<T>::operator==(const linked_list<T>& L) const {
	if (L.size() != length) return false;
	
	position p, pL;
	p = first();
	pL = L.first();
	while (!end(p)) {
		if (p->data != pL->data) return false;
		
		p = p->next;
		pL = pL->next;
	}
	
	return true;
}

#endif // !LINKED_LIST_H