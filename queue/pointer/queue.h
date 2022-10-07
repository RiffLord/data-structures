/**
 * @file    queue.h
 * @author  Bruno Pezer (bruno.pezer@tutanota.com)
 * @brief   Generic pointer-based queue data structure class definition
 * @version 0.2
 * @date    2022-08-17
 * 
 * @copyright NO COPYRIGHT !(c) 2022
 * 
 */
#ifndef QUEUE_H
#define QUEUE_H
#include "node.h"

template <typename T> class Queue {
    friend std::ostream &operator<<(std::ostream &out, const Queue &q) {
        Node<T> *n = q.head;
        while (n != nullptr) {
            out << n->getData() << '\n';
            n = n->getNext();
        }
        return out;
    }
    //friend std::istream &operator>>(std::istream &, const Queue &);
public:
    Queue();
    Queue(const Queue &);
    ~Queue();

    bool isEmpty() const;
    T read() const;
    void pop();
    void push(T);

    unsigned int getSize() const;

    Queue &operator=(const Queue &) const;
    bool operator==(const Queue &) const;
    bool operator!=(const Queue &) const;
private:
    Node<T> *head;
    unsigned int size;
};

template <typename T>
Queue<T>::Queue() {
    head = nullptr;
    size = 0;
}

//  TODO:   implement copy constructor
template <typename T>
Queue<T>::Queue(const Queue &rval) {
    Node<T> *n = head;
    Node<T> *m = rval.head;
    while (m->getNext() != nullptr) {
        n = new Node<T>(m->getData());
        n = n->getNext();
        m = m->getNext();
    } 
}

template <typename T>
Queue<T>::~Queue() {
    while (!isEmpty())
        pop();
}

template <typename T>
bool Queue<T>::isEmpty() const { return head == nullptr; }

template <typename T>
T Queue<T>::read() const { return head->getData(); }
    
template <typename T>
void Queue<T>::pop() {
    if (!isEmpty()) {
        Node<T> *n = head;
        head = head->getNext();
        delete n;
        --size;
    }
}

template <typename T>
void Queue<T>::push(T t) {
    if (isEmpty())
        head = new Node<T>(t);
    else {
        Node<T> *n = new Node<T>(t);
        Node<T> *iterator = head;
        while (iterator->getNext() != nullptr) {
            iterator = iterator->getNext();
        }
        iterator->setNext(n);
    }
    ++size;
}

template <typename T>
unsigned int Queue<T>::getSize() const { return size; }

//  TODO:   implement assignment operator overload
/*
template <typename T>
typename Queue<T> &Queue<T>::operator=(const Queue<T> &rval) const {}
*/

template <typename T>
bool Queue<T>::operator==(const Queue<T> &rval) const {
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
bool Queue<T>::operator!=(const Queue<T> &rval) const { return !(*this == rval); }

#endif // !QUEUE_H
