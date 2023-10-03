/**
 * @file    node.h
 * @author  Bruno Pezer
 * @brief   Node class definition for use in a binary tree data structure
 * @version 1.4
 * @date    2022-08-17
 *
 * @copyright NO COPYRIGHT !(c) 2022
 *
 */
#ifndef NODE_H
#define NODE_H
#include <iostream>

/**
 * @brief    Generic node class for use in binary trees.
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
    friend std::ostream &operator<<(std::ostream &out, const Node<T> &n) {
        out << n.getData() << '\n';
        return out;
    }

    /**
     * @brief                Overloaded input operator.
     *
     * @param in             Input
     * @param t              Data to write
     * @return std::istream& Input stream
     */
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
    Node *getLeftChild() const;
    Node *getRightChild() const;
    void setData(T);
    void setParent(Node *);
    void setLeftChild(Node *);
    void setRightChild(Node *);
private:
    T data;
    Node *parent;
    Node *leftChild;
    Node *rightChild;
};

/**
 * @brief    Class constructor. Creates a new node using the provided parameters.
 *
 * @tparam T Node type
 * @param t  Data to store in the node.
 * @param p  Pointer to the parent node.
 * @param l  Pointer to the node's right child.
 * @param r  Pointer to the node's left child.
 */
template <typename T>
Node<T>::Node(T t, Node<T> *p, Node<T> *l, Node<T> *r) {
    data = t;
    parent = p;
    leftChild = l;
    rightChild = r;
}

/**
 * @brief      Copy constructor. Creates a new node which is a copy of the one provided as a parameter.
 *
 * @tparam T   Node type
 * @param rval Node to copy
 */
template <typename T>
Node<T>::Node(const Node<T> &rval) {
    data = rval.data;
    parent = rval.parent;
    leftChild = rval.leftChild;
    rightChild = rval.rightChild;
}

/**
 * @brief    Obtains the node's contents.
 *
 * @tparam T Data type
 * @return   Node contents
 */
template <typename T>
T Node<T>::getData() const { return data; }

/**
 * @brief    Obtains a reference to the node's parent.
 *
 * @tparam T Node type
 * @return   This node's parent node.
 */
template <typename T>
Node<T> *Node<T>::getParent() const { return parent; }

/**
 * @brief    Obtains a reference to the node's left child.
 *
 * @tparam T Node type
 * @return   This node's left child.
 */
template <typename T>
Node<T> *Node<T>::getLeftChild() const { return leftChild; }

/**
 * @brief    Obtains a reference to the node's right child.
 *
 * @tparam T Node type
 * @return   This node's right child.
 */
template <typename T>
Node<T> *Node<T>::getRightChild() const { return rightChild; }

/**
 * @brief    Stores the provided data in the node.
 *
 * @tparam T Data type
 * @param t  Data to store in the node.
 */
template <typename T>
void Node<T>::setData(T t) { data = t; }

/**
 * @brief    Sets the node's parent.
 *
 * @tparam T Node type
 * @param p  The node to set as this node's parent.
 */
template <typename T>
void Node<T>::setParent(Node<T> *p) { parent = p; }

/**
 * @brief    Sets the node's left child.
 *
 * @tparam T Node type
 * @param l  The node to set as this node's left child.
 */
template <typename T>
void Node<T>::setLeftChild(Node<T> *l) { leftChild = l; }

/**
 * @brief    Sets the node's right child.
 *
 * @tparam T Node type
 * @param l  The node to set as this node's right child.
 */
template <typename T>
void Node<T>::setRightChild(Node<T> *r) { rightChild = r; }

#endif // !NODE_H
