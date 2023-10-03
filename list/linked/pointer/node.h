/**
 * @file    node.h
 * @author  Bruno Pezer
 * @brief   Generic node class definition for use in various pointer-based data structures.
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
 * @brief    Generic node for storing items of a given type and the locations in memory of the next node.
 *
 * @tparam T Node type
 */
template <typename T> class Node {
    /**
     * @brief                Overloaded output operator for the Node class.
     *
     * @param out            Node contents and a newline.
     * @param n              Node to print.
     * @return std::ostream& Output
     */
    friend std::ostream &operator<<(std::ostream &out, const Node &n) {
        out << n.getData() << '\n';
        return out;
    }

    /**
     * @brief                Overloaded input operator.
     *
     * @param in             Input
     * @param t              Node content
     * @return std::istream& Input
     */
    friend std::istream &operator>>(std::istream &in, const T &t) {
        in >> t;
        return in;
    }
public:
    Node(T, Node<T> * = nullptr);
    Node(const Node<T> &);
    T getData() const;
    Node<T> *getNext() const;
    void setData(T);
    void setNext(Node<T> *);
private:
    T data;
    Node<T> *next;
};

/**
 * @brief    Creates a new node using the provided parameters.
 *
 * @tparam T Node type
 * @param t  Data to store in the node.
 * @param n  Pointer to the next node.
 */
template <typename T>
Node<T>::Node(T t, Node<T> *n) {
    data = t;
    next = n;
}

/**
 * @brief      Creates a new node by copying an existing node.
 *
 * @tparam T   Node type
 * @param rval Node to copy.
 */
template <typename T>
Node<T>::Node(const Node<T> &rval) {
    data = rval.data;
    next = rval.next;
}

/**
 * @brief    Obtains the contents of a node.
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
 * @return   Node to which this node points.
 */
template <typename T>
Node<T> *Node<T>::getNext() const { return next; }

/**
 * @brief    Uses the parameter to set the node's contents.
 *
 * @tparam T Node type
 * @param t  Data to store in this node.
 */
template <typename T>
void Node<T>::setData(T t) { data = t; }

/**
 * @brief    Uses the parameter to set the next node.
 *
 * @tparam T Node type
 * @param n  Node to point to.
 */
template <typename T>
void Node<T>::setNext(Node<T> *n) { next = n; }

#endif // !NODE_H
