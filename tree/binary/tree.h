/**
 * @file    tree.h
 * @author  Bruno Pezer (bruno.pezer@tutanota.com)
 * @brief   Binary tree data structure definition
 * @version 0.7
 * @date    2022-08-30
 * 
 * @copyright NO COPYRIGHT !(c) 2022
 * 
 */
#ifndef TREE_H
#define TREE_H
#include "node.h"

class Tree {
    friend std::ostream &operator<<(std::ostream &, const Tree &);
public:
    Tree();
    Tree(const Tree &);
    Tree(Node *);
    ~Tree();
    bool isEmpty() const;
    bool hasLeftChild(Node *) const;
    bool hasRightChild(Node *) const;
    Node *getRoot() const;
    Node *parent(Node *) const;
    Node *leftChild(Node *) const;
    Node *rightChild(Node *) const;
    void insertRoot(Node *);
    void insertLeftChild(Node *);
    void insertLeftChild(int, Node *);
    void insertRightChild(Node *);
    void insertRightChild(int, Node *);
    void removeSubtree(Node *);
    void write(int, Node *);
    int read(Node *) const;
    void print(Node *n);
private:
    Node *root;
};

#endif // !TREE_H
