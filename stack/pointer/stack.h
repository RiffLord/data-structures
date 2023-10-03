/**
 * @file    stack.h
 * @author  Bruno Pezer
 * @brief   Class definition for a pointer-based implementation of a stack data structure
 * @version 0.2
 * @date    2022-08-22
 *
 * @copyright NO COPYRIGHT !(c) 2022
 */
#ifndef STACK_H
#define STACK_H
#include "node.h"

//  TODO:   fix segmentation fault in destructor
/**
 * @brief    Generic Stack class
 *
 * @tparam T Stack type
 */
template <typename T> class Stack {
    /**
     * @brief                Overloaded output operator. Prints each item in the stack followed by a newline.
     *
     * @param out            Output
     * @param s              Stack to print
     * @return std::ostream& Output buffer
     */
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

/**
 * @brief    Stack constructor. Initializes an empty stack of size 0.
 *
 * @tparam T Stack type
 */
template <typename T>
Stack<T>::Stack() {
    head = nullptr;
    size = 0;
}

/**
 * @brief      Copy constructor. Initializes a new stack which is a copy of the provided one.
 *
 * @tparam T   Stack type
 * @param rval Stack to copy
 */
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

/**
 * @brief    Class destructor. Uses the pop() function to empty the stack and free memory.
 *
 * @tparam T Stack type
 */
template <typename T>
Stack<T>::~Stack() {
    while (!isEmpty())
        pop();
}

/**
 * @brief    Checks if the stack is empty.
 *
 * @tparam T Stack type
 * @return   true if the stack is empty, false otherwise.
 */
template <typename T>
bool Stack<T>::isEmpty() const { return head == nullptr; }

/**
 * @brief    Obtains the last item in the stack.
 *
 * @tparam T Stack type
 * @return   Last item in the stack
 */
template <typename T>
T Stack<T>::read() const {
    Node<T> *n = head;
    while (n->getNext() != nullptr) {
        n = n->getNext();
    }
    return n->getData();
}

/**
 * @brief    Removes the last item from the stack, freeing memory and decreasing the stack size.
 *
 * @tparam T Stack type
 */
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

/**
 * @brief    Adds the provided item to the end of the stack.
 *
 * @tparam T Stack type
 * @param t  Item to add to the stack.
 */
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

/**
 * @brief    Obtains the size of the stack.
 *
 * @tparam T Stack type
 * @return   Stack size
 */
template <typename T>
unsigned int Stack<T>::getSize() const { return size; }

//  TODO:   implement assignment operator overload
/**
 * @brief            Assignment operator overload. Creates a new stack using the provided one.
 *
 * @tparam T         Stack type
 * @param rval       Stack to assign
 * @return Stack<T>& New stack
 */
template <typename T>
Stack<T> &Stack<T>::operator=(const Stack<T> &rval) const { return Stack(rval); }

/**
 * @brief      Overloaded equality operator.
 *
 * @tparam T   Stack type
 * @param rval Stack to compare
 * @return     true if the stack's are identical, false if not.
 */
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

/**
 * @brief      Overloaded inequality operator.
 *
 * @tparam T   Stack type
 * @param rval Stack to compare
 * @return     true if the stacks are different, false if they are equal.
 */
template <typename T>
bool Stack<T>::operator!=(const Stack<T> &rval) const { return !(*this == rval); }

#endif // !STACK_H
