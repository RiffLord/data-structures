/**
 * @file    tree.cpp
 * @author  Bruno Pezer (bruno.pezer@tutanota.com)
 * @brief   Binary tree data structure implementation
 * @version 0.8
 * @date    2022-08-30
 * 
 * @copyright NO COPYRIGHT !(c) 2022
 * 
 */
#include <cmath>
#include "tree.h"

Tree::Tree() { root = nullptr; }

Tree::Tree(Node *n) { insertRoot(n); }

Tree::~Tree() { removeSubtree(root); }

bool Tree::isEmpty() const { return root == nullptr; }

bool Tree::hasLeftChild(Node *n) const {
    if (n->getLeftChild() == nullptr) return false;
    else return true;
}

bool Tree::hasRightChild(Node *n) const {
    if (n->getRightChild() == nullptr) return false;
    else return true;    
}

void Tree::write(int t, Node *n) {
    if (n != nullptr) {
        n->setData(t);
    }
}

void Tree::insertRoot(Node *n) {
    if (!isEmpty())
        throw std::runtime_error{"Tree::insertRoot()\nTree::isEmpty() == false"};
    root = n;
}

//  Creates an empty node as n's left child
void Tree::insertLeftChild(Node *n) {
    if (isEmpty())
        throw std::runtime_error{""};
    if (hasLeftChild(n))
        throw std::runtime_error{""};
    n->setLeftChild(new Node);
    n->getLeftChild()->setParent(n);
}

/**
 *  Creates a new node with the provided data
 *  and sets it to be n's left child
 */
void Tree::insertLeftChild(int t, Node *n) {
    if (isEmpty())
        throw std::runtime_error{""};
    if (hasLeftChild(n))
        throw std::runtime_error{""};
    n->setLeftChild(new Node(t, n));   
}

//  Creates an empty node as n's right child
void Tree::insertRightChild(Node *n) {
    if (isEmpty())
        throw std::runtime_error{""};
    if (hasRightChild(n))
        throw std::runtime_error{""};
    n->setRightChild(new Node);
    n->getRightChild()->setParent(n);
}

/**
 *  Creates a new node with the provided data
 *  and sets it to be n's right child
 */
void Tree::insertRightChild(int t, Node *n) {
    if (isEmpty())
        throw std::runtime_error{""};
    if (hasRightChild(n))
        throw std::runtime_error{""};
    n->setRightChild(new Node(t, n));   
}

void Tree::removeSubtree(Node *n) {
    if (n != nullptr) {
        if (hasLeftChild(n))
            removeSubtree(leftChild(n));
        if (hasRightChild(n))
            removeSubtree(rightChild(n));
        if (n != root) {
            Node *p = parent(n);
            if (leftChild(p) == n) {
                //Node *l = leftChild(p);
                p->setLeftChild(nullptr);
                //delete l;
            } else {
                //Node *r = rightChild(p);
                p->setRightChild(nullptr);
                //delete r;
            }
        } else root = nullptr;
    }
}

Node *Tree::getRoot() const {
    if (isEmpty())
        throw std::runtime_error{"Tree::getRoot()\nTree::isEmpty() == true"}; 
    return root; 
}

Node *Tree::parent(Node *n) const {
    if (isEmpty())
        throw std::runtime_error{"Tree::parent()\nTree::isEmpty() == true"};
    if (n == root)
        throw std::runtime_error{"Tree::parent()\nRoot has no parent node"};
    return n->getParent();
}

Node *Tree::leftChild(Node *n) const {
    if (isEmpty())
        throw std::runtime_error{"Tree::leftChild()\nTree::isEmpty() == true"};
    if (n == nullptr)
        throw std::runtime_error{"Tree::leftChild()"}; 
    return n->getLeftChild(); 
}

Node *Tree::rightChild(Node *n) const {
    if (isEmpty())
        throw std::runtime_error{"Tree::rightChild()\nTree::isEmpty() == true"};
    if (n == nullptr)
        throw std::runtime_error{"Tree::rightChild()"}; 
    return n->getRightChild(); 
}

int Tree::read(Node *n) const { return n->getData(); }

void Tree::print(Node *n) {
    using namespace std;
    cout << "[" << n->getData() << ", ";
    if (hasLeftChild(n)) print(leftChild(n));
    else cout << "°";
    cout << ", ";
    if (hasRightChild(n)) print(rightChild(n));
    else cout << "°";
    cout << "]";
}
