/**
 * @file    stack.cpp
 * @author  Bruno Pezer (bruno.pezer@tutanota.com)
 * @brief   Implementation file for a pointer-based stack data structure
 * @version 0.3
 * @date    2022-08-22
 * 
 * @copyright NO COPYRIGHT !(c) 2022
 */
#include "stack.h"

Stack::Stack() {
    head = nullptr;
    size = 0;
}

Stack::Stack(const Stack &rval) {
    head = new Node(rval.head->getData());
    size = 1;
    Node *lnPtr = head;
    Node *rnPtr = rval.head->getNext();
    while (rnPtr != nullptr) {
        Node *n = new Node(rnPtr->getData());
        lnPtr->setNext(n);
        lnPtr = lnPtr->getNext();
        rnPtr = rnPtr->getNext();
        ++size;
    }
}

Stack::~Stack() {
    while (!isEmpty())
        pop();
}

bool Stack::isEmpty() const { return head == nullptr; }

int Stack::read() const {
    Node *n = head;
    while (n->getNext() != nullptr) {
        n = n->getNext();
    }
    return n->getData();
}
    
void Stack::pop() {
    if (!isEmpty()) {
        Node *n = head;
        Node *iterator = n->getNext();
        while (iterator->getNext() != nullptr) {
            n = n->getNext();
            iterator = iterator->getNext();
        }
        n->setNext(nullptr);
        delete iterator;
        --size;
    }
}

void Stack::push(int t) {
    if (isEmpty())
        head = new Node(t);
    else {
        Node *n = new Node(t);
        Node *offset = head;
        while (offset->getNext() != nullptr) {
            offset = offset->getNext();
        }
        offset->setNext(n);
    }
    ++size;
}

unsigned int Stack::getSize() const { return size; }

//  TODO:   implement assignment operator overload
Stack &Stack::operator=(const Stack &rval) const {}

bool Stack::operator==(const Stack &rval) const {
    if (size != rval.size)
        return false;
    Node *n = head;
    Node *m = rval.head;
    while (n != nullptr) {
        if (n->getData() != m->getData())
            return false;
        n = n->getNext();
        m = m->getNext();
    }
    return true;
}

bool Stack::operator!=(const Stack &rval) const { return !(*this == rval); }

std::ostream &operator<<(std::ostream &out, const Stack &stack) {
    Node *n = stack.head;
    while (n->getNext() != nullptr) { 
        out << n->getData() << '\n';
        n = n->getNext();
    }
    out << n->getData() << '\n';
    return out;
}

//  TODO:   implement input operator overload
std::istream &operator>>(std::istream &, const Stack &) {}
