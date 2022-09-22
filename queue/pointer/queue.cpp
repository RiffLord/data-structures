/**
 * @file    queue.cpp
 * @author  Bruno Pezer (bruno.pezer@tutanota.com)
 * @brief   Implementation file for a pointer-based queue data structure
 * @version 0.2
 * @date    2022-08-17
 * 
 * @copyright NO COPYRIGHT !(c) 2022
 * 
 */
#include "queue.h"

Queue::Queue() {
    head = nullptr;
    size = 0;
}

//  TODO:   implement copy constructor
Queue::Queue(const Queue &rval) {
    Node *n = head;
    Node *m = rval.head;
    while (m->getNext() != nullptr) {
        n = new Node(m->getData());
        n = n->getNext();
        m = m->getNext();
    } 
}

Queue::~Queue() {
    while (!isEmpty())
        pop();
}

bool Queue::isEmpty() const { return head == nullptr; }

int Queue::read() const { return head->getData(); }
    
void Queue::pop() {
    if (!isEmpty()) {
        Node *n = head;
        head = head->getNext();
        delete n;
        --size;
    }
}

void Queue::push(int t) {
    if (isEmpty())
        head = new Node(t);
    else {
        Node *n = new Node(t);
        Node *iterator = head;
        while (iterator->getNext() != nullptr) {
            iterator = iterator->getNext();
        }
        iterator->setNext(n);
    }
    ++size;
}

unsigned int Queue::getSize() const { return size; }

//  TODO:   implement assignment operator overload
Queue &Queue::operator=(const Queue &rval) const {}

bool Queue::operator==(const Queue &rval) const {
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

bool Queue::operator!=(const Queue &rval) const { return !(*this == rval); }

std::ostream &operator<<(std::ostream &out, const Queue &queue) {
    Node *n = queue.head;
    while (n != nullptr) {
        out << n->getData() << '\n';
        n = n->getNext();
    }
    return out;
}

//  TODO:   implement input operator overload
std::istream &operator>>(std::istream &, const Queue &) {}
