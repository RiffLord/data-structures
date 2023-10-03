/**
 * @file    node.h
 * @author  Bruno Pezer
 * @brief   Generic node class definition for use in various pointer-based data structures.
 * @version 1.2
 * @date    2022-08-15
 *
 * @copyright NO COPYRIGHT !(c) 2022
 *
 */
#ifndef NODE_H
#define NODE_H

/**
 * @brief    Generic node for use in linked lists.
 *
 * @tparam T Node type
 */
template <typename T> class Node {
public:
    Node(T);
    Node(const Node &);

    void setData(T);
    T getData() const;

    bool operator==(const Node &) const;
    bool operator!=(const Node &) const;
private:
    T data;
};

/**
 * @brief    Creates a new node with the data provided by the parameter.
 *
 * @tparam T Data type
 * @param t  Node contents
 */
template <typename T>
Node<T>::Node(T t) { data = t; }

/**
 * @brief      Creates a new node by copying the contents from another node.
 *
 * @tparam T   Data type
 * @param rval Node to copy.
 */
template <typename T>
Node<T>::Node(const Node<T> &rval) { data = rval.data; }

/**
 * @brief    Stores the data provided by the parameter in the node.
 *
 * @tparam T Data type
 * @param d  Data to store.
 */
template <typename T>
void Node<T>::setData(T d) { data = d; }

/**
 * @brief    Obtains the node contents.
 *
 * @tparam T Data type
 * @return   Data stored in this node.
 */
template <typename T>
T Node<T>::getData() const { return data; }

/**
 * @brief      Overloaded equality operator.
 *
 * @tparam T   Data type
 * @param rval Node to compare.
 * @return     True if the nodes contain the same data, false otherwise.
 */
template <typename T>
bool Node<T>::operator==(const Node &rval) const { return data == rval.data; }

/**
 * @brief      Overloaded inequality operator.
 *
 * @tparam T   Data type
 * @param rval Node to compare.
 * @return     True if the nodes contain differing data, false otherwise.
 */
template <typename T>
bool Node<T>::operator!=(const Node<T> &rval) const { return !(*this == rval); }

#endif // !NODE_H
