/**
 * @file    tree.h
 * @author  Bruno Pezer (bruno.pezer@tutanota.com)
 * @brief   Generic binary tree data structure definition
 * @version 0.8
 * @date    2022-08-30
 * 
 * @copyright NO COPYRIGHT !(c) 2022
 * 
 */
#ifndef TREE_H
#define TREE_H
#include "node.h"

template <typename T> class Tree {
public:
    Tree();
    Tree(const Tree &);
    Tree(Node<T> *);
    ~Tree();
    bool isEmpty() const;
    bool hasLeftChild(Node<T> *) const;
    bool hasRightChild(Node<T> *) const;
    Node<T> *getRoot() const;
    Node<T> *parent(Node<T> *) const;
    Node<T> *leftChild(Node<T> *) const;
    Node<T> *rightChild(Node<T> *) const;
    void insertRoot(Node<T> *);
    void insertLeftChild(Node<T> *);
    void insertLeftChild(T, Node<T> *);
    void insertRightChild(Node<T> *);
    void insertRightChild(T, Node<T> *);
    void removeSubtree(Node<T> *);
    void write(T, Node<T> *);
    T read(Node<T> *) const;
    void print(Node<T> *n);
private:
    Node<T> *root;
};

template <typename T>
Tree<T>::Tree() { root = nullptr; }

template <typename T>
Tree<T>::Tree(Node<T> *n) { insertRoot(n); }

template <typename T>
Tree<T>::~Tree() { removeSubtree(root); }

template <typename T>
bool Tree<T>::isEmpty() const { return root == nullptr; }

template <typename T>
bool Tree<T>::hasLeftChild(Node<T> *n) const {
    if (n->getLeftChild() == nullptr) return false;
    else return true;
}

template <typename T>
bool Tree<T>::hasRightChild(Node<T> *n) const {
    if (n->getRightChild() == nullptr) return false;
    else return true;    
}

template <typename T>
void Tree<T>::write(T t, Node<T> *n) {
    if (n != nullptr) {
        n->setData(t);
    }
}

template <typename T>
void Tree<T>::insertRoot(Node<T> *n) {
    if (!isEmpty())
        throw std::runtime_error{"Tree::insertRoot()\nTree::isEmpty() == false"};
    root = n;
}

//  Creates an empty node as n's left child
template <typename T>
void Tree<T>::insertLeftChild(Node<T> *n) {
    if (isEmpty())
        throw std::runtime_error{""};
    if (hasLeftChild(n))
        throw std::runtime_error{""};
    n->setLeftChild(new Node<T>);
    n->getLeftChild()->setParent(n);
}

/**
 *  Creates a new node with the provided data
 *  and sets it to be n's left child
 */
template <typename T>
void Tree<T>::insertLeftChild(T t, Node<T> *n) {
    if (isEmpty())
        throw std::runtime_error{""};
    if (hasLeftChild(n))
        throw std::runtime_error{""};
    n->setLeftChild(new Node<T>(t, n));   
}

//  Creates an empty node as n's right child
template <typename T>
void Tree<T>::insertRightChild(Node<T> *n) {
    if (isEmpty())
        throw std::runtime_error{""};
    if (hasRightChild(n))
        throw std::runtime_error{""};
    n->setRightChild(new Node<T>);
    n->getRightChild()->setParent(n);
}

/**
 *  Creates a new node with the provided data
 *  and sets it to be n's right child
 */
template <typename T>
void Tree<T>::insertRightChild(T t, Node<T> *n) {
    if (isEmpty())
        throw std::runtime_error{""};
    if (hasRightChild(n))
        throw std::runtime_error{""};
    n->setRightChild(new Node<T>(t, n));   
}

template <typename T>
void Tree<T>::removeSubtree(Node<T> *n) {
    if (n != nullptr) {
        if (hasLeftChild(n))
            removeSubtree(leftChild(n));
        if (hasRightChild(n))
            removeSubtree(rightChild(n));
        if (n != root) {
            Node<T> *p = parent(n);
            if (leftChild(p) == n) {
                //Node<T> *l = leftChild(p);
                p->setLeftChild(nullptr);
                //delete l;
            } else {
                //Node<T> *r = rightChild(p);
                p->setRightChild(nullptr);
                //delete r;
            }
        } else root = nullptr;
    }
}

template <typename T>
Node<T> *Tree<T>::getRoot() const {
    if (isEmpty())
        throw std::runtime_error{"Tree::getRoot()\nTree::isEmpty() == true"}; 
    return root; 
}

template <typename T>
Node<T> *Tree<T>::parent(Node<T> *n) const {
    if (isEmpty())
        throw std::runtime_error{"Tree::parent()\nTree::isEmpty() == true"};
    if (n == root)
        throw std::runtime_error{"Tree::parent()\nRoot has no parent Node<T>"};
    return n->getParent();
}

template <typename T>
Node<T> *Tree<T>::leftChild(Node<T> *n) const {
    if (isEmpty())
        throw std::runtime_error{"Tree::leftChild()\nTree::isEmpty() == true"};
    if (n == nullptr)
        throw std::runtime_error{"Tree::leftChild()"}; 
    return n->getLeftChild(); 
}

template <typename T>
Node<T> *Tree<T>::rightChild(Node<T> *n) const {
    if (isEmpty())
        throw std::runtime_error{"Tree::rightChild()\nTree::isEmpty() == true"};
    if (n == nullptr)
        throw std::runtime_error{"Tree::rightChild()"}; 
    return n->getRightChild(); 
}

template <typename T>
T Tree<T>::read(Node<T> *n) const { return n->getData(); }

//  TODO:   transform into overloaded output operator
template <typename T>
void Tree<T>::print(Node<T> *n) {
    using namespace std;
    cout << "[" << n->getData() << ", ";
    if (hasLeftChild(n)) print(leftChild(n));
    else cout << "°";
    cout << ", ";
    if (hasRightChild(n)) print(rightChild(n));
    else cout << "°";
    cout << "]";
}

#endif // !TREE_H
