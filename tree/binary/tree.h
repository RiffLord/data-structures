/**
 * @file    tree.h
 * @author  Bruno Pezer
 * @brief   Generic binary tree data structure definition
 * @version 0.9
 * @date    2022-08-30
 *
 * @copyright NO COPYRIGHT !(c) 2022
 *
 */
#ifndef TREE_H
#define TREE_H
#include "node.h"

/**
 * @brief    Generic binary tree.
 *
 * @tparam T Tree type
 */
template <typename T> class Tree {
public:
    Tree();
    Tree(const Tree &);
    Tree(Node<T> *);
    ~Tree();
    bool isEmpty() const;
    bool hasLeftChild(Node<T> *) const;
    bool hasRightChild(Node<T> *) const;
    Node<T> *getRoot() const;
    Node<T> *parent(Node<T> *) const;
    Node<T> *leftChild(Node<T> *) const;
    Node<T> *rightChild(Node<T> *) const;
    void insertRoot(Node<T> *);
    void insertLeftChild(Node<T> *);
    void insertLeftChild(T, Node<T> *);
    void insertRightChild(Node<T> *);
    void insertRightChild(T, Node<T> *);
    void removeSubtree(Node<T> *);
    void write(T, Node<T> *);
    T read(Node<T> *) const;
    void print(Node<T> *n);
private:
    Node<T> *root;
};

/**
 * @brief    Class constructor. Creates an empty binary tree.
 *
 * @tparam T Tree type
 */
template <typename T>
Tree<T>::Tree() { root = nullptr; }

/**
 * @brief      Copy constructor. Creates a new tree which is a copy of the one provided as a parameter.
 *
 * @tparam T   Tree type
 * @param rval Tree to copy
 */
template <typename T>
Tree<T>::Tree(const Tree &rval) {}

/**
 * @brief    Overloaded class constructor. Creates a new tree, setting the node parameter as its root.
 *
 * @tparam T Tree type
 * @param n  Node to use as the tree's root.
 */
template <typename T>
Tree<T>::Tree(Node<T> *n) { insertRoot(n); }

/**
 * @brief    Class destructor. Deletes all nodes in the tree starting from the root.
 *
 * @tparam T Tree type
 */
template <typename T>
Tree<T>::~Tree() { removeSubtree(root); }

/**
 * @brief    Verifies that the tree is empty by checking if the root is equal to a null pointer.
 *
 * @tparam T Tree type
 * @return   True if the root is equal to a null pointer, false otherwise.
 */
template <typename T>
bool Tree<T>::isEmpty() const { return root == nullptr; }

/**
 * @brief    Verifies that the provided node has a left child.
 *
 * @tparam T Tree type
 * @param n  Node to check
 * @return   True if n has a left child, false otherwise.
 */
template <typename T>
bool Tree<T>::hasLeftChild(Node<T> *n) const {
    if (n->getLeftChild() == nullptr) return false;
    else return true;
}

/**
 * @brief    Verifies that the provided node has a right child.
 *
 * @tparam T Tree type
 * @param n  Node to check
 * @return   True if n has a right child, false otherwise.
 */
template <typename T>
bool Tree<T>::hasRightChild(Node<T> *n) const {
    if (n->getRightChild() == nullptr) return false;
    else return true;
}

/**
 * @brief    Writes the provided data to the provided node.
 *
 * @tparam T Tree type
 * @param t  Data to write to the node.
 * @param n  Node in which to store the provided data.
 */
template <typename T>
void Tree<T>::write(T t, Node<T> *n) {
    if (n != nullptr) {
        n->setData(t);
    }
}

/**
 * @brief    Sets the provided node as the tree's root if the tree is empty.
 *
 * @tparam T Tree type
 * @param n  Desired root
 */
template <typename T>
void Tree<T>::insertRoot(Node<T> *n) {
    if (!isEmpty())
        throw std::runtime_error{"Tree::insertRoot():\nTree::isEmpty() == false"};
    root = n;
}

/**
 * @brief    Creates an empty node as the left child of the provided node.
 *
 * @tparam T Tree type
 * @param n  Node to which to add the left child.
 */
template <typename T>
void Tree<T>::insertLeftChild(Node<T> *n) {
    if (isEmpty())
        throw std::runtime_error{"Tree::insertLeftChild():\nTree:isEmpty() == true"};
    if (hasLeftChild(n))
        throw std::runtime_error{"Tree::insertLeftChild():\nTree:hasLeftChild() == true"};
    n->setLeftChild(new Node<T>);
    n->getLeftChild()->setParent(n);
}

/**
 * @brief    Overloaded insertion method. Creates a new node storing the provided
 *           data in it and sets it to be the provided node's left child.
 *
 * @tparam T
 * @param t
 * @param n
 */
template <typename T>
void Tree<T>::insertLeftChild(T t, Node<T> *n) {
    if (isEmpty())
        throw std::runtime_error{""};
    if (hasLeftChild(n))
        throw std::runtime_error{""};
    n->setLeftChild(new Node<T>(t, n));
}

/**
 * @brief    Creates an empty node as the right child of the provided node.
 *
 * @tparam T Tree type
 * @param n  Node to which to add the right child.
 */
template <typename T>
void Tree<T>::insertRightChild(Node<T> *n) {
    if (isEmpty())
        throw std::runtime_error{""};
    if (hasRightChild(n))
        throw std::runtime_error{""};
    n->setRightChild(new Node<T>);
    n->getRightChild()->setParent(n);
}

/**
 * @brief    Overloaded insertion method. Creates a new node storing the provided
 *           data in it and sets it to be the provided node's left child.
 *
 * @tparam T Tree type
 * @param n  Node to which to add the right child.
 */
template <typename T>
void Tree<T>::insertRightChild(T t, Node<T> *n) {
    if (isEmpty())
        throw std::runtime_error{""};
    if (hasRightChild(n))
        throw std::runtime_error{""};
    n->setRightChild(new Node<T>(t, n));
}

/**
 * @brief    Removes all of the provided node's descendants from the tree.
 *
 * @tparam T Tree type
 * @param n  Subtree's root.
 */
template <typename T>
void Tree<T>::removeSubtree(Node<T> *n) {
    if (n != nullptr) {
        if (hasLeftChild(n))
            removeSubtree(leftChild(n));
        if (hasRightChild(n))
            removeSubtree(rightChild(n));
        if (n != root) {
            Node<T> *p = parent(n);
            if (leftChild(p) == n) {
                //Node<T> *l = leftChild(p);
                p->setLeftChild(nullptr);
                //delete l;
            } else {
                //Node<T> *r = rightChild(p);
                p->setRightChild(nullptr);
                //delete r;
            }
        } else root = nullptr;
    }
}

/**
 * @brief    Obtains the tree's root node.
 *
 * @tparam T Tree type
 * @return   root
 */
template <typename T>
Node<T> *Tree<T>::getRoot() const {
    if (isEmpty())
        throw std::runtime_error{"Tree::getRoot()\nTree::isEmpty() == true"};
    return root;
}

/**
 * @brief    Obtains the provided node's parent.
 *
 * @tparam T Tree type
 * @param n  Node whose parent is needed.
 * @return   The provided node's parent.
 */
template <typename T>
Node<T> *Tree<T>::parent(Node<T> *n) const {
    if (isEmpty())
        throw std::runtime_error{"Tree::parent()\nTree::isEmpty() == true"};
    if (n == root)
        throw std::runtime_error{"Tree::parent()\nRoot has no parent Node<T>"};
    return n->getParent();
}

/**
 * @brief    Obtains the provided node's left child.
 *
 * @tparam T Tree type
 * @param n  Node whose left child is needed.
 * @return   The provided node's left child.
 */
template <typename T>
Node<T> *Tree<T>::leftChild(Node<T> *n) const {
    if (isEmpty())
        throw std::runtime_error{"Tree::leftChild()\nTree::isEmpty() == true"};
    if (n == nullptr)
        throw std::runtime_error{"Tree::leftChild()"};
    return n->getLeftChild();
}

/**
 * @brief    Obtains the provided node's right child.
 *
 * @tparam T Tree type
 * @param n  Node whose right child is needed.
 * @return   The provided node's right child.
 */
template <typename T>
Node<T> *Tree<T>::rightChild(Node<T> *n) const {
    if (isEmpty())
        throw std::runtime_error{"Tree::rightChild()\nTree::isEmpty() == true"};
    if (n == nullptr)
        throw std::runtime_error{"Tree::rightChild()"};
    return n->getRightChild();
}

/**
 * @brief    Obtains the data stored in the provided node.
 *
 * @tparam T Data type
 * @param n  Node to read.
 * @return   Node contents
 */
template <typename T>
T Tree<T>::read(Node<T> *n) const { return n->getData(); }

/**
 * @brief    Prints the provided node's contents and the contents of its left and right children, if it has them.
 *
 * @tparam T Tree type
 * @param n  Node from which to start printing.
 */
template <typename T>
void Tree<T>::print(Node<T> *n) {
    //  TODO: transform into overloaded output operator.
    using namespace std;
    cout << "[" << n->getData() << ", ";
    if (hasLeftChild(n)) print(leftChild(n));
    else cout << "°";
    cout << ", ";
    if (hasRightChild(n)) print(rightChild(n));
    else cout << "°";
    cout << "]";
}

#endif // !TREE_H
