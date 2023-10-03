/**
 * @file    node.h
 * @author  Bruno Pezer
 * @brief   Generic node class definition for use in various pointer-based data structures
 * @version 1.2
 * @date    2022-08-17
 *
 * @copyright NO COPYRIGHT !(c) 2022
 *
 */
#ifndef NODE_H
#define NODE_H
#include <iostream>

/**
 * @brief    Generic pointer-based node class for storing items of a given type and a reference to the next item.
 *
 * @tparam T Node type
 */
template <typename T> class Node {
    /**
     * @brief                Overloaded output operator. Prints the node contents followed by a newline.
     *
     * @param out            Output
     * @param n              Node to print
     * @return std::ostream& Output buffer
     */
    friend std::ostream &operator<<(std::ostream &out, const Node &n) {
        out << n.getData() << '\n';
        return out;
    }

    /**
     * @brief                Overloaded input operator. Allows the user to write to a node directly from the command line.
     *
     * @param in             Input
     * @param t              Data to write
     * @return std::istream& Input buffer
     */
    friend std::istream &operator>>(std::istream &in, const T &t) {
        in >> t;
        return in;
    }
public:
    Node(T, Node * = nullptr);
    Node(const Node &);
    T getData() const;
    Node *getNext() const;
    void setData(T);
    void setNext(Node *);
private:
    int data;
    Node *next;
};

/**
 * @brief    Node constructor. Uses the provided parameters to initialize a new node.
 *
 * @tparam T Node type
 * @param t  Node contents
 * @param n  Pointer to the next node.
 */
template <typename T>
Node<T>::Node(T t, Node<T> *n) {
    data = t;
    next = n;
}

/**
 * @brief      Copy constructor. Creates a new node from the provided one.
 *
 * @tparam T   Node type
 * @param rval Node to copy
 */
template <typename T>
Node<T>::Node(const Node<T> &rval) {
    data = rval.data;
    next = rval.next;
}

/**
 * @brief    Obtains the node contents.
 *
 * @tparam T Node type
 * @return   Node contents
 */
template <typename T>
T Node<T>::getData() const { return data; }

/**
 * @brief    Obtains the reference to the next node.
 *
 * @tparam T Node type
 * @return   Reference to the next node.
 */
template <typename T>
Node<T> *Node<T>::getNext() const { return next; }


/**
 * @brief    Writes the provided data to the node.
 *
 * @tparam T Node type
 * @param t  Data to store in the node.
 */
template <typename T>
void Node<T>::setData(T t) { data = t; }

/**
 * @brief    Sets the reference to the next node.
 *
 * @tparam T Node type
 * @param n  Reference to the next node.
 */
template <typename T>
void Node<T>::setNext(Node<T> *n) { next = n; }

#endif // !NODE_H
