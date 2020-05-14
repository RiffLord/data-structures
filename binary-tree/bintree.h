#ifndef BINTREE_H
#define BINTREE_H

#include <iostream>
#include <iomanip>
#include "node.h"

template<class T>
class bintree {
public:
    bintree();
    ~bintree();
    void init();
    bool isEmpty() const;
    node<T>* getRoot() const;
    node<T>* father(node<T>*) const;
    node<T>* leftChild(node<T>*) const;
    node<T>* rightChild(node<T>*) const;
    bool leftEmpty(node<T>*) const;
    bool rightEmpty(node<T>*) const;
    T readNode(node<T>*) const;
    void writeNode(node<T>*, T);
    void insertRoot();
    void insertLeftChild(node<T>*);
    void insertRightChild(node<T>*);
    void removeSubtree(node<T>*);
private:
    node<T>* root;
};

template<class T>
bintree<T>::bintree() { init(); }

template<class T>
bintree<T>::~bintree() { delete root; }

template<class T>
void bintree<T>::init() { root = nullptr; }

template<class T>
bool bintree<T>::isEmpty() const { return root == nullptr; }

template<class T>
node<T>* bintree<T>::getRoot() const {
    if (!isEmpty())
        return root; 
    else
        return nullptr;
}

template<class T>
node<T>* bintree<T>::father(node<T>* u) const {
    if (!isEmpty() && u != getRoot())
        return u->getFather();

    else return nullptr;
}

template<class T>
node<T>* bintree<T>::leftChild(node<T>* u) const {
    if (!isEmpty() && !leftEmpty(u))
        return u->getLeftChild();
    else
        return nullptr;
}

template<class T>
node<T>* bintree<T>::rightChild(node<T>* u) const {
    if (!isEmpty() && !rightEmpty(u))
        return u->getRightChild();
    else
        return nullptr;
}

template<class T>
bool bintree<T>::leftEmpty(node<T>* u) const { return u->getLeftChild() == nullptr; }

template<class T>
bool bintree<T>::rightEmpty(node<T>* u) const { return u->getRightChild() == nullptr; }

template<class T>
T bintree<T>::readNode(node<T>* u) const { return u->getData(); }

template<class T>
void bintree<T>::writeNode(node<T>* u, T value) { u->setData(value); }

template<class T>
void bintree<T>::insertRoot() {
    if (isEmpty()) root = new node<T>;
}

template<class T>
void bintree<T>::insertLeftChild(node<T>* u) {
    if (!isEmpty() && leftEmpty(u)) {
        node<T>* left = new node<T>;
        u->setLeftChild(left);
        left->setFather(u);
    }
}

template<class T>
void bintree<T>::insertRightChild(node<T>* u) {
    if (!isEmpty() && rightEmpty(u)) {
        node<T>* right = new node<T>;
        u->setRightChild(right);
        right->setFather(u);
    }
}

template<class T>
void bintree<T>::removeSubtree(node<T>* u) {
    if (!isEmpty()) {
        if (u == root) root = nullptr;
        else {
            node<T>* father = u->getFather();
            
            if (u == father->getLeftChild()) father->setLeftChild(nullptr);
            else father->setRightChild(nullptr);
            delete u;
        }
    }
}

#endif // !BINTREE_H