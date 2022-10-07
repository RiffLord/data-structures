/**
 * @file    tree.h
 * @author  Bruno Pezer (bruno.pezer@tutanota.com)
 * @brief   Class definition for a generic n-ary tree data structure
 * @version 0.2
 * @date    2022-10-06
 * 
 * @copyright NO COPYRIGHT !(c) 2022
 * 
 */
#ifndef TREE_H
#define TREE_H
#include <cassert>
#include "node.h"

template <typename T> class Tree {
public:
    Tree();
    ~Tree();
    bool isEmpty() const;
    bool isLeaf(Node<T> *) const;
    bool isLastSibling(Node<T> *) const;
    bool belongs(Node<T> *) const;
    void insertRoot(Node<T> *);
    void insertFirstSubtree(const Tree &, Node<T> *);
    void insertSubtree(const Tree &, Node<T> *);
    void removeSubtree(Node<T> *);
    Node<T> *getRoot() const;
    Node<T> *parent(Node<T> *) const;
    Node<T> *firstChild(Node<T> *) const;
    Node<T> *nextSibling(Node<T> *) const;
    void write(T, Node<T> *);
    T read(Node<T> *) const;
    void print(Node<T> *);
private:
    Node<T> *root;
};

template <typename T>
Tree<T>::Tree() { root = nullptr; }

template <typename T>
Tree<T>::~Tree() { removeSubtree(root); }

template <typename T>
bool Tree<T>::isEmpty() const { return root == nullptr; }

template <typename T>
bool Tree<T>::isLeaf(Node<T> *n) const {
    assert(belongs(n));
    //  TODO:   might cause issues. Replace with if/else and explicit returns if so
    return n->getFirstChild() == nullptr;
}

template <typename T>
bool Tree<T>::isLastSibling(Node<T> *n) const {
    assert(belongs(n));
    //  TODO: replace with if/else & explicit returns if causing issues
    return n->getNextSibling() == nullptr;
}

template <typename T>
bool Tree<T>::belongs(Node<T> *n) const { return true; }

template <typename T>
void Tree<T>::insertRoot(Node<T> *n) {
    assert(isEmpty());
    root = n;
}

template <typename T>
void Tree<T>::insertFirstSubtree(const Tree<T> &t, Node<T> *n) {
    assert(!t.isEmpty());
    assert(belongs(n));
    t.getRoot()->setNextSibling(n->getFirstChild());
    t.getRoot()->setParent(n);
    n->setFirstChild(t.getRoot());
}

template <typename T>
void Tree<T>::insertSubtree(const Tree<T> &t, Node<T> *n) {
    assert(!t.isEmpty());
    assert(belongs(n));
    assert(getRoot() != n);
    t.getRoot()->setNextSibling(n->getNextSibling());
    t.getRoot()->setParent(n->getParent());
    n->setNextSibling(t.getRoot());
}

/**
 *  Using delete causes free(): double free detected in tcache 2
 */
template <typename T>
void Tree<T>::removeSubtree(Node<T> *n) {
    assert(belongs(n));
    if (getRoot() == n) //delete root;
        root = nullptr;
    else {
        if (n == firstChild(parent(n))) {
            if (isLastSibling(n)) parent(n)->setFirstChild(nullptr);
            else parent(n)->setFirstChild(nextSibling(n));
        } else {
            Node<T> *previous = firstChild(parent(n));
            Node<T> *current = nextSibling(previous);
            while (current != n) {
                previous = current;
                current = nextSibling(current);
            }
            if (isLastSibling(n)) previous->setNextSibling(nullptr);
            else previous->setNextSibling(nextSibling(n));
        }
    }
    //delete n;
    n = nullptr;
}

//  TODO:   assert !isEmpty()
template <typename T>
Node<T> *Tree<T>::getRoot() const { return root; }

template <typename T>
Node<T> *Tree<T>::parent(Node<T> *n) const {
    assert(n != root);
    assert(belongs(n));
    return n->getParent();
}

template <typename T>
Node<T> *Tree<T>::firstChild(Node<T> *n) const {
    assert(belongs(n));
    assert(n->getFirstChild() != nullptr);
    return n->getFirstChild();
}

template <typename T>
Node<T> *Tree<T>::nextSibling(Node<T> *n) const {
    assert(belongs(n));
    assert(!isLastSibling(n));
    return n->getNextSibling();
}

template <typename T>
void Tree<T>::write(T t, Node<T> *n) {
    assert(belongs(n));
    n->setData(t);
}

template <typename T>
T Tree<T>::read(Node<T> *n) const {
    assert(belongs(n));
    return n->getData();
}

#endif // !TREE_H