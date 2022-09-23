/**
 * @file    tree.cpp
 * @author  Bruno Pezer (bruno.pezer@tutanota.com)
 * @brief   Binary tree data structure implementation
 * @version 0.5
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

Tree::Tree(Node *n) { setRoot(n); }

//  TODO:   correctly implement class destructor
Tree::~Tree() { delete root; }

bool Tree::isEmpty() const { return root == nullptr; }

bool Tree::isLeaf(Node *n) const {
    if (n->getLeftChild() != nullptr || n->getRightChild() != nullptr)
		return false;
	return true;
}

void Tree::setRoot(Node *n) {
	if (isEmpty() && isLeaf(n) && n != nullptr)
		root = n;
}

void Tree::setValue(int t, Node *n) {
    if (n != nullptr) {
        n->setData(t);
    }
}

Node *Tree::getRoot() const {
    if (isEmpty())
        throw std::runtime_error{"Tree::getRoot()\nTree::isEmpty() == true"}; 
    return root; 
}

Node *Tree::parent(Node *n) const {
    //  TODO:   gracefully fail if attempting to call function on root node
    if (n == root) return nullptr;
    return n->getParent();
}

//  TODO:   assert n != nullptr
Node *Tree::leftChild(Node *n) const { return n->getLeftChild(); }

//  TODO:   assert n != nullptr
Node *Tree::rightChild(Node *n) const { return n->getRightChild(); }

int Tree::readNode(Node *n) const { return n->getData(); }
