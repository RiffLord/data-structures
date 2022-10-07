/**
 * @file    node.h
 * @author  Bruno Pezer (bruno.pezer@tutanota.com)
 * @brief   Generic node class definition for use in an n-ary tree data structure
 * @version 1.4
 * @date    2022-08-17
 * 
 * @copyright NO COPYRIGHT !(c) 2022
 * 
 */
#ifndef NODE_H
#define NODE_H
#include <iostream>

template <typename T> class Node {
    friend std::ostream &operator<<(std::ostream &out, const Node &node) {
        out << node.getData() << '\n';
        return out;
    }
    friend std::istream &operator>>(std::istream &in, const T &t) {
        in >> t;
        return in;
    }
public:
    Node(T, Node * = nullptr, 
            Node * = nullptr,  
            Node * = nullptr);
    Node(const Node &);
    T getData() const;
    Node *getParent() const;
    Node *getNextSibling() const;
    Node *getFirstChild() const;
    void setData(T);
    void setParent(Node *);
    void setNextSibling(Node *);
    void setFirstChild(Node *);
    bool operator==(const Node &) const;
private:
    T data;
    Node *parent;
    Node *nextSibling;
    Node *firstChild;
};

template <typename T>
Node<T>::Node(T t, Node<T> *p, Node<T> *s, Node<T> *c) {
    data = t;
    parent = p;
    nextSibling = s;
    firstChild = c;
}

template <typename T>
Node<T>::Node(const Node<T> &rval) {
    data = rval.data;
    parent = rval.parent;
    nextSibling = rval.nextSibling;
    firstChild = rval.firstChild;
}

template <typename T>
T Node<T>::getData() const { return data; }

template <typename T>
Node<T> *Node<T>::getParent() const { return parent; }

template <typename T>
Node<T> *Node<T>::getNextSibling() const { return nextSibling; }

template <typename T>
Node<T> *Node<T>::getFirstChild() const { return firstChild; }

template <typename T>
void Node<T>::setData(T t) { data = t; }

template <typename T>
void Node<T>::setParent(Node<T> *p) { parent = p; }

template <typename T>
void Node<T>::setNextSibling(Node<T> *s) { nextSibling = s; }

template <typename T>
void Node<T>::setFirstChild(Node<T> *c) { firstChild = c; }

template <typename T>
bool Node<T>::operator==(const Node<T> &rval) const { return getData() == rval.getData(); }

#endif // !NODE_H
