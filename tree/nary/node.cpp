/**
 * @file    node.cpp
 * @author  Bruno Pezer (bruno.pezer@tutanota.com)
 * @brief   Node implementation file for use in an n-ary tree data structure
 * @version 1.3
 * @date    2022-08-17
 * 
 * @copyright NO COPYRIGHT !(c) 2022
 * 
 */
#include "node.h"

Node::Node(int t, Node *p, Node *s, Node *c) {
    data = t;
    parent = p;
    nextSibling = s;
    firstChild = c;
}

Node::Node(const Node &rval) {
    data = rval.data;
    parent = rval.parent;
    nextSibling = rval.nextSibling;
    firstChild = rval.firstChild;
}

int Node::getData() const { return data; }

Node *Node::getParent() const { return parent; }

Node *Node::getNextSibling() const { return nextSibling; }

Node *Node::getFirstChild() const { return firstChild; }

void Node::setData(int t) { data = t; }

void Node::setParent(Node *p) { parent = p; }

void Node::setNextSibling(Node *s) { nextSibling = s; }

void Node::setFirstChild(Node *c) { firstChild = c; }

bool Node::operator==(const Node &rval) const { return getData() == rval.getData(); }

std::ostream &operator<<(std::ostream &out, const Node &node) {
    out << node.getData() << '\n';
    return out;
}

std::istream &operator>>(std::istream &in, const int &t) {
    in >> t;
    return in;
}
