/**
 * @file    stack.h
 * @author  Bruno Pezer (bruno.pezer@tutanota.com)
 * @brief   Class definition for a pointer-based implementation of a stack data structure
 * @version 0.1
 * @date    2022-08-22
 * 
 * @copyright NO COPYRIGHT !(c) 2022
 */
#ifndef STACK_H
#define STACK_H
#include "node.h"

//  TODO:   fix segmentation fault in destructor
template <typename T> class Stack {
    friend std::ostream &operator<<(std::ostream &out, const Stack &s) {
        Node<T> *n = s.head;
        while (n->getNext() != nullptr) { 
            out << n->getData() << '\n';
            n = n->getNext();
        }
        out << n->getData() << '\n';
        return out;
    }
    //friend std::istream &operator>>(std::istream &, const Stack &);
public:
    Stack();
    Stack(const Stack &);
    ~Stack();

    bool isEmpty() const;
    T read() const;
    void pop();
    void push(T);

    unsigned int getSize() const;
    
    Stack &operator=(const Stack &) const;
    bool operator==(const Stack &) const;
    bool operator!=(const Stack &) const;
private:
    Node<T> *head;
    unsigned int size;
};

template <typename T>
Stack<T>::Stack() {
    head = nullptr;
    size = 0;
}

template <typename T>
Stack<T>::Stack(const Stack<T> &rval) {
    head = new Node<T>(rval.head->getData());
    size = 1;
    Node<T> *lnPtr = head;
    Node<T> *rnPtr = rval.head->getNext();
    while (rnPtr != nullptr) {
        Node<T> *n = new Node<T>(rnPtr->getData());
        lnPtr->setNext(n);
        lnPtr = lnPtr->getNext();
        rnPtr = rnPtr->getNext();
        ++size;
    }
}

template <typename T>
Stack<T>::~Stack() {
    while (!isEmpty())
        pop();
}

template <typename T>
bool Stack<T>::isEmpty() const { return head == nullptr; }

template <typename T>
T Stack<T>::read() const {
    Node<T> *n = head;
    while (n->getNext() != nullptr) {
        n = n->getNext();
    }
    return n->getData();
}

template <typename T>
void Stack<T>::pop() {
    if (!isEmpty()) {
        Node<T> *n = head;
        Node<T> *iterator = n->getNext();
        while (iterator->getNext() != nullptr) {
            n = n->getNext();
            iterator = iterator->getNext();
        }
        n->setNext(nullptr);
        delete iterator;
        --size;
    }
}

template <typename T>
void Stack<T>::push(T t) {
    if (isEmpty())
        head = new Node<T>(t);
    else {
        Node<T> *n = new Node<T>(t);
        Node<T> *offset = head;
        while (offset->getNext() != nullptr) {
            offset = offset->getNext();
        }
        offset->setNext(n);
    }
    ++size;
}

template <typename T>
unsigned int Stack<T>::getSize() const { return size; }

//  TODO:   implement assignment operator overload
template <typename T>
Stack<T> &Stack<T>::operator=(const Stack<T> &rval) const {}

template <typename T>
bool Stack<T>::operator==(const Stack<T> &rval) const {
    if (size != rval.size)
        return false;
    Node<T> *n = head;
    Node<T> *m = rval.head;
    while (n != nullptr) {
        if (n->getData() != m->getData())
            return false;
        n = n->getNext();
        m = m->getNext();
    }
    return true;
}

template <typename T>
bool Stack<T>::operator!=(const Stack<T> &rval) const { return !(*this == rval); }

#endif // !STACK_H
