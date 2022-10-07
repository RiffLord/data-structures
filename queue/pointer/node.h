/**
 * @file    node.h
 * @author  Bruno Pezer (bruno.pezer@tutanota.com)
 * @brief   Generic node class definition for use in a various pointer-based data structures
 * @version 1.1
 * @date    2022-08-17
 * 
 * @copyright NO COPYRIGHT !(c) 2022
 * 
 */
#ifndef NODE_H
#define NODE_H
#include <iostream>

template <typename T> class Node {
    friend std::ostream &operator<<(std::ostream &out, const Node &n) {
        out << n.getData() << '\n';
        return out;
    }
    friend std::istream &operator>>(std::istream &in, const T &t) {
        in >> t;
        return in;
    }
public:
    Node(T, Node * = nullptr);
    Node(const Node &);
    T getData() const;
    Node *getNext() const;
    void setData(T);
    void setNext(Node *);
private:
    int data;
    Node *next;
};

template <typename T>
Node<T>::Node(T t, Node<T> *n) {
    data = t;
    next = n;
}

template <typename T>
Node<T>::Node(const Node<T> &rval) {
    data = rval.data;
    next = rval.next;
}

template <typename T>
T Node<T>::getData() const { return data; }

template <typename T>
Node<T> *Node<T>::getNext() const { return next; }

template <typename T>
void Node<T>::setData(T t) { data = t; }

template <typename T>
void Node<T>::setNext(Node<T> *n) { next = n; }

#endif // !NODE_H
