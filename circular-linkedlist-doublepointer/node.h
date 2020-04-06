#ifndef NODE_H
#define NODE_H

template<typename T>
class node {
public:
	typedef T item;
	node() {}
	node(const T& l) { this->label = l; }
	void setLabel(item l) { label = l; }
	item getLabel() const { return label; }
	void setNext(node* n) { next = n; }
	void setPrev(node* p) { prev = p; }
	node* getNext() const { return next; }
	node* getPrev() const { return prev; }
private:
	item label;
	node* next;
	node* prev;
};

#endif // !NODE_H
