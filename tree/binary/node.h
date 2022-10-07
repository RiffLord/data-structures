/**
 * @file    node.h
 * @author  Bruno Pezer (bruno.pezer@tutanota.com)
 * @brief   Node class definition for use in a binary tree data structure
 * @version 1.3
 * @date    2022-08-17
 * 
 * @copyright NO COPYRIGHT !(c) 2022
 * 
 */
#ifndef NODE_H
#define NODE_H
#include <iostream>

template <typename T> class Node {
    friend std::ostream &operator<<(std::ostream &out, const Node<T> &n) {
        out << n.getData() << '\n';
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
    Node *getLeftChild() const;
    Node *getRightChild() const;
    void setData(T);
    void setParent(Node *);
    void setLeftChild(Node *);
    void setRightChild(Node *);
private:
    T data;
    Node *parent;
    Node *leftChild;
    Node *rightChild;
};

template <typename T>
Node<T>::Node(T t, Node<T> *p, Node<T> *l, Node<T> *r) {
    data = t;
    parent = p;
    leftChild = l;
    rightChild = r;
}

template <typename T>
Node<T>::Node(const Node<T> &rval) {
    data = rval.data;
    parent = rval.parent;
    leftChild = rval.leftChild;
    rightChild = rval.rightChild;
}

template <typename T>
T Node<T>::getData() const { return data; }

template <typename T>
Node<T> *Node<T>::getParent() const { return parent; }

template <typename T>
Node<T> *Node<T>::getLeftChild() const { return leftChild; }

template <typename T>
Node<T> *Node<T>::getRightChild() const { return rightChild; }

template <typename T>
void Node<T>::setData(T t) { data = t; }

template <typename T>
void Node<T>::setParent(Node<T> *p) { parent = p; }

template <typename T>
void Node<T>::setLeftChild(Node<T> *l) { leftChild = l; }

template <typename T>
void Node<T>::setRightChild(Node<T> *r) { rightChild = r; }

#endif // !NODE_H
