/**
 * @file    tree.cpp
 * @author  Bruno Pezer (bruno.pezer@tutanota.com)
 * @brief   Implementation file for an n-ary tree data structure
 * @version 0.1
 * @date    2022-10-06
 * 
 * @copyright NO COPYRIGHT !(c) 2022
 * 
 */
#include <cassert>
#include "tree.h"

Tree::Tree() { root = nullptr; }

Tree::~Tree() { removeSubtree(root); }

bool Tree::isEmpty() const { return root == nullptr; }

bool Tree::isLeaf(Node *n) const {
    assert(belongs(n));
    //  TODO:   might cause issues. Replace with if/else and explicit returns if so
    return n->getFirstChild() == nullptr;
}

bool Tree::isLastSibling(Node *n) const {
    assert(belongs(n));
    //  TODO: replace with if/else & explicit returns if causing issues
    return n->getNextSibling() == nullptr;
}

bool Tree::belongs(Node *n) const { return true; }

void Tree::insertRoot(Node *n) {
    assert(isEmpty());
    root = n;
}

void Tree::insertFirstSubtree(const Tree &t, Node *n) {
    assert(!t.isEmpty());
    assert(belongs(n));
    t.getRoot()->setNextSibling(n->getFirstChild());
    t.getRoot()->setParent(n);
    n->setFirstChild(t.getRoot());
}

void Tree::insertSubtree(const Tree &t, Node *n) {
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
void Tree::removeSubtree(Node *n) {
    assert(belongs(n));
    if (getRoot() == n) //delete root;
        root = nullptr;
    else {
        if (n == firstChild(parent(n))) {
            if (isLastSibling(n)) parent(n)->setFirstChild(nullptr);
            else parent(n)->setFirstChild(nextSibling(n));
        } else {
            Node *previous = firstChild(parent(n));
            Node *current = nextSibling(previous);
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
Node *Tree::getRoot() const { return root; }

Node *Tree::parent(Node *n) const {
    assert(n != root);
    assert(belongs(n));
    return n->getParent();
}

Node *Tree::firstChild(Node *n) const {
    assert(belongs(n));
    assert(n->getFirstChild() != nullptr);
    return n->getFirstChild();
}

Node *Tree::nextSibling(Node *n) const {
    assert(belongs(n));
    assert(!isLastSibling(n));
    return n->getNextSibling();
}

void Tree::write(int t, Node *n) {
    assert(belongs(n));
    n->setData(t);
}

int Tree::read(Node *n) const {
    assert(belongs(n));
    return n->getData();
}
