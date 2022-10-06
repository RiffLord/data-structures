/**
 * @file    node.cpp
 * @author  Bruno Pezer (bruno.pezer@tutanota.com)
 * @brief   Node implementation file for use in a binary tree data structure
 * @version 1.2
 * @date    2022-08-17
 * 
 * @copyright NO COPYRIGHT !(c) 2022
 * 
 */
#include "node.h"

Node::Node(int t, Node *p, /*Node *s,*/ Node *l, Node *r) {
    data = t;
    parent = p;
    //sibling = s;
    leftChild = l;
    rightChild = r;
}

Node::Node(const Node &rval) {
    data = rval.data;
    parent = rval.parent;
    //sibling = rval.sibling;
    leftChild = rval.leftChild;
    rightChild = rval.rightChild;
}

int Node::getData() const { return data; }

Node *Node::getParent() const { return parent; }

//Node *Node::getSibling() const { return sibling; }

Node *Node::getLeftChild() const { return leftChild; }

Node *Node::getRightChild() const { return rightChild; }

void Node::setData(int t) { data = t; }

void Node::setParent(Node *p) { parent = p; }

//void Node::setSibling(Node *s) { sibling = s; }

void Node::setLeftChild(Node *l) { leftChild = l; }

void Node::setRightChild(Node *r) { rightChild = r; }

std::ostream &operator<<(std::ostream &out, const Node &node) {
    out << node.getData() << '\n';
    return out;
}

std::istream &operator>>(std::istream &in, const int &t) {
    in >> t;
    return in;
}
