/**
 * @file    node.h
 * @author  Bruno Pezer
 * @brief   Generic node class definition for use in an n-ary tree data structure.
 * @version 1.5
 * @date    2022-08-17
 *
 * @copyright NO COPYRIGHT !(c) 2022
 *
 */
#ifndef NODE_H
#define NODE_H
#include <iostream>

/**
 * @brief    Generic node for use in trees.
 *
 * @tparam T Node type
 */
template <typename T> class Node {
    /**
     * @brief                Overloaded output operator. Prints the contents of the node followed by a newline.
     *
     * @param out            Output
     * @param node           Node to print
     * @return std::ostream& Output buffer
     */
    friend std::ostream &operator<<(std::ostream &out, const Node &node) {
        out << node.getData() << '\n';
        return out;
    }
    friend std::istream &operator>>(std::istream &in, const T &t) {
        in >> t;
        return in;
    }
public:
    Node(T, Node * = nullptr,
            Node * = nullptr,
            Node * = nullptr);
    Node(const Node &);
    T getData() const;
    Node *getParent() const;
    Node *getNextSibling() const;
    Node *getFirstChild() const;
    void setData(T);
    void setParent(Node *);
    void setNextSibling(Node *);
    void setFirstChild(Node *);
    bool operator==(const Node &) const;
private:
    T data;
    Node *parent;
    Node *nextSibling;
    Node *firstChild;
};

/**
 * @brief    Class constructor. Creates a new node using the provided parameters.
 *
 * @tparam T Node type
 * @param t  Node contents
 * @param p  Pointer to the parent node
 * @param s  Pointer to the sibling node
 * @param c  Pointer to the first child node.
 */
template <typename T>
Node<T>::Node(T t, Node<T> *p, Node<T> *s, Node<T> *c) {
    data = t;
    parent = p;
    nextSibling = s;
    firstChild = c;
}

/**
 * @brief      Copy constructor. Creates a new node from the one provided as a parameter.
 *
 * @tparam T   Node type
 * @param rval Node to copy
 */
template <typename T>
Node<T>::Node(const Node<T> &rval) {
    data = rval.data;
    parent = rval.parent;
    nextSibling = rval.nextSibling;
    firstChild = rval.firstChild;
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
 * @brief    Obtains a reference to the current node's parent.
 *
 * @tparam T Node type
 * @return   Pointer to this node's parent.
 */
template <typename T>
Node<T> *Node<T>::getParent() const { return parent; }

/**
 * @brief    Obtains a reference to the current node's next sibling.
 *
 * @tparam T Node type
 * @return   Pointer to this node's next sibling.
 */
template <typename T>
Node<T> *Node<T>::getNextSibling() const { return nextSibling; }

/**
 * @brief    Obtains a reference to the current node's first child.
 *
 * @tparam T Node type
 * @return   Pointer to this node's first child.
 */
template <typename T>
Node<T> *Node<T>::getFirstChild() const { return firstChild; }

/**
 * @brief    Stores the provided data in the node.
 *
 * @tparam T Data type
 * @param t  Data to write
 */
template <typename T>
void Node<T>::setData(T t) { data = t; }

/**
 * @brief    Sets the node's parent.
 *
 * @tparam T Node type
 * @param p  Pointer to the node's parent.
 */
template <typename T>
void Node<T>::setParent(Node<T> *p) { parent = p; }

/**
 * @brief    Sets the node's next sibling.
 *
 * @tparam T Node type
 * @param s  Pointer to the node's next sibling.
 */
template <typename T>
void Node<T>::setNextSibling(Node<T> *s) { nextSibling = s; }

/**
 * @brief    Sets the node's first child node.
 *
 * @tparam T Node type
 * @param c  Pointer to the node's first child.
 */
template <typename T>
void Node<T>::setFirstChild(Node<T> *c) { firstChild = c; }

/**
 * @brief      Overloaded equality operator.
 *
 * @tparam T   Node type
 * @param rval Node to compare.
 * @return    True if the  node's are equal, false otherwise.
 */
template <typename T>
bool Node<T>::operator==(const Node<T> &rval) const { return getData() == rval.getData(); }

#endif // !NODE_H
