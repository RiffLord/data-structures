#ifndef NODE_H
#define NODE_H

#include <iostream>

template<typename T>
class Node {
public:
	typedef T item;
	
	Node();
	Node(item);
	~Node();
	void writeLabel(item);
	item readLabel() const;
	//bool operator==(Node);	//	TO IMPLEMENT
private:
	item label;
};

#endif // !NODE_H

template<typename T>
Node<T>::Node() {}

template<typename T>
Node<T>::Node(item t) { writeLabel(t); }

template<typename T>
Node<T>::~Node() {}

template<typename T>
void Node<T>::writeLabel(item t) { label = t; }

template<typename T>
typename Node<T>::item Node<T>::readLabel() const { return label; }

//template<typename T>
//bool Node<T>::operator==(Node n) {}
