/**
 * @file    queue.h
 * @author  Bruno Pezer
 * @brief   Generic pointer-based queue data structure class definition
 * @version 0.3
 * @date    2022-08-17
 *
 * @copyright NO COPYRIGHT !(c) 2022
 *
 */
#ifndef QUEUE_H
#define QUEUE_H
#include "node.h"

/**
 * @brief    Generic pointer-based queue class.
 *
 * @tparam T Queue type
 */
template <typename T> class Queue {
    /**
     * @brief     Overloaded output operator. Prints the contents of the entire queue with newlines between each item.
     *
     * @param out Output
     * @param q   Queue to print
     * @return    Output buffer
     */
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

/**
 * @brief    Class constructor. Creates a new empty queue.
 *
 * @tparam T Queue type
 */
template <typename T>
Queue<T>::Queue() {
    head = nullptr;
    size = 0;
}

//  TODO:   implement copy constructor
/**
 * @brief Copy constructor. Constructs a new Queue<T>::Queue object
 *
 * @tparam T   Queue type
 * @param rval Queue to copy
 */
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

/**
 * @brief    Class destructor. Invokes the pop method to empty the queue and free memory.
 *
 * @tparam T Queue type
 */
template <typename T>
Queue<T>::~Queue() {
    while (!isEmpty())
        pop();
}

/**
 * @brief    Checks if the queue is empty.
 *
 * @tparam T Queue type
 * @return   true if the queue is empty, false if not.
 */
template <typename T>
bool Queue<T>::isEmpty() const { return head == nullptr; }

/**
 * @brief    Obtains the contents stored at the top of the queue.
 *
 * @tparam T Queue type
 * @return   The contents from the queue's first node.
 */
template <typename T>
T Queue<T>::read() const { return head->getData(); }

/**
 * @brief    Removes the item at the top of the queue, freeing memory and reducing the queue's size.
 *
 * @tparam T Queue type
 */
template <typename T>
void Queue<T>::pop() {
    if (!isEmpty()) {
        Node<T> *n = head;
        head = head->getNext();
        delete n;
        --size;
    }
}

/**
 * @brief    Adds a new node containing the provided data to the queue.
 *
 * @tparam T Queue type
 * @param t  Data to add
 */
template <typename T>
void Queue<T>::push(T t) {
    if (isEmpty())
        head = new Node<T>(t);
    else {
        Node<T> *n = new Node<T>(t);
        // TODO: extract this block to a new function if possible.
        Node<T> *iterator = head;
        while (iterator->getNext() != nullptr) {
            iterator = iterator->getNext();
        }
        iterator->setNext(n);
    }
    ++size;
}

/**
 * @brief    Obtains the size of the queue.
 *
 * @tparam T Queue type
 * @return   Queue size
 */
template <typename T>
unsigned int Queue<T>::getSize() const { return size; }

//  TODO:   implement assignment operator overload
/*
template <typename T>
typename Queue<T> &Queue<T>::operator=(const Queue<T> &rval) const {}
*/

/**
 * @brief      Overloaded equality operator.
 *
 * @tparam T   Queue type
 * @param rval Queue to compare
 * @return     true if the queue's are equals, false otherwise.
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

/**
 * @brief      Overloaded inequality operator.
 *
 * @tparam T   Queue type
 * @param rval Queue to compare
 * @return     true if the queue's are different, false if they're equal.
 */
template <typename T>
bool Queue<T>::operator!=(const Queue<T> &rval) const { return !(*this == rval); }

#endif // !QUEUE_H
