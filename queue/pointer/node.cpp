/**
 * @file    node.cpp
 * @author  Bruno Pezer (bruno.pezer@tutanota.com)
 * @brief   Node implementation file for use in various pointer-based data structures
 * @version 1.0
 * @date    2022-08-17
 * 
 * @copyright NO COPYRIGHT !(c) 2022
 * 
 */
#include "node.h"

Node::Node(int t, Node *n) {
    data = t;
    next = n;
}

Node::Node(const Node &rval) {
    data = rval.data;
    next = rval.next;
}

int Node::getData() const { return data; }

Node *Node::getNext() const { return next; }

void Node::setData(int t) { data = t; }

void Node::setNext(Node *n) { next = n; }

std::ostream &operator<<(std::ostream &out, const Node &node) {
    out << node.getData() << '\n';
    return out;
}

std::istream &operator>>(std::istream &in, const int &t) {
    in >> t;
    return in;
}
