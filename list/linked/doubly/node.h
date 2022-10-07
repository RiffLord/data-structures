/**
 * @file    node.h
 * @author  Bruno Pezer (bruno.pezer@tutanota.com)
 * @brief   Generic node class definition for use in various pointer-based data structures
 * @version 1.1
 * @date    2022-08-15
 * 
 * @copyright NO COPYRIGHT !(c) 2022
 * 
 */
#ifndef NODE_H
#define NODE_H

template <typename T> class Node {
public:
    Node(int = 0);
    Node(const Node &);

    void setData(T);
    T getData() const;

    bool operator==(const Node &) const;
    bool operator!=(const Node &) const;
private:
    T data;
};

template <typename T>
Node<T>::Node(int d) { data = d; }

template <typename T>
Node<T>::Node(const Node<T> &rval) { data = rval.data; }

template <typename T>
void Node<T>::setData(T d) { data = d; }

template <typename T>
T Node<T>::getData() const { return data; }

template <typename T>
bool Node<T>::operator==(const Node &rval) const { return data == rval.data; }

template <typename T>
bool Node<T>::operator!=(const Node<T> &rval) const { return !(*this == rval); }

#endif // !NODE_H
