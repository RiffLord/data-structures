/**
 * @file    tree.cpp
 * @author  Bruno Pezer (bruno.pezer@tutanota.com)
 * @brief   Binary tree data structure implementation
 * @version 0.4
 * @date    2022-08-30
 * 
 * @copyright NO COPYRIGHT !(c) 2022
 * 
 */
#include <cmath>
#include "tree.h"

Tree::Tree() { 
	root = nullptr;
	height = totalNodes = 0; 
}

Tree::Tree(Node *n) {
    if (isLeaf(n))
        setRoot(n);
}

Tree::Tree(const Tree &t) {
    if (!t.isEmpty()) {
        setRoot(t.getRoot());
    }
}

Tree::~Tree() {}

bool Tree::isEmpty() const { return root == nullptr; }

//  TODO: implement isLeaf
bool Tree::isLeaf(Node *n) const {
    if (!isEmpty()) {
        if (hasLeftChild(n) || hasRightChild(n))
            return false;
        return true;
    }
}

bool Tree::hasLeftChild(Node *n) const {
    if (!isEmpty()) {
        if (isLeaf(n)) return false;
        if (n != nullptr && 
            leftChild(n) != nullptr) return true;
    }
    return false;
}

bool Tree::hasRightChild(Node *n) const {
    if (!isEmpty()) {
        if (isLeaf(n)) return false;
        if (n != nullptr && 
            rightChild(n) != nullptr) return true;
    }
    return false;
}

//  TODO:   n must be a leaf
void Tree::setRoot(Node *n) {
    if (isEmpty() && isLeaf(n))
        root = new Node(n->getData());
}

void Tree::setValue(int t, Node *n) {
    if (n != nullptr)
        n->setData(t);
}

Node *Tree::getRoot() const {
    if (!isEmpty()) 
        return root; 
}

Node *Tree::parent(Node *n) const {
    if (getRoot() != n) {
        //  TODO: return n's parent
    }
}

Node *Tree::leftChild(Node *n) const {
    if (!isLeaf(n)) return n->getLeftChild();
}

Node *Tree::rightChild(Node *n) const {
    if (!isLeaf(n)) return n->getRightChild();
}

int Tree::readNode(Node *n) const {
    if (n != nullptr)
        return n->getData();
}

//  TODO: add subtree
void Tree::addSubtree(Node *n, Node *u, const Tree &t) {
    if (!isEmpty() && !t.isEmpty()) {
        if (n == u) {
            //  TODO: adding subtree with 
        }
        if (isLeaf(n)) {

        }
    }
}

//  TODO: remove subtree
void Tree::removeSubtree(Node *n) {
    if (!isEmpty()) {
        if (getRoot() == n && isLeaf(n)) {
            delete n;
        }
    }
}

unsigned int Tree::getHeight() const { return height; }

bool Tree::isComplete() const { return totalNodes == pow(2, height); }
