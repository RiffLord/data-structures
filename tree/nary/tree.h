/**
 * @file    tree.h
 * @author  Bruno Pezer (bruno.pezer@tutanota.com)
 * @brief   Class definition for an n-ary tree data structure
 * @version 0.1
 * @date    2022-10-06
 * 
 * @copyright NO COPYRIGHT !(c) 2022
 * 
 */
#ifndef TREE_H
#define TREE_H
#include "node.h"

class Tree {
public:
    Tree();
    ~Tree();
    bool isEmpty() const;
    bool isLeaf(Node *) const;
    bool isLastSibling(Node *) const;
    bool belongs(Node *) const;
    void insertRoot(Node *);
    void insertFirstSubtree(const Tree &, Node *);
    void insertSubtree(const Tree &, Node *);
    void removeSubtree(Node *);
    Node *getRoot() const;
    Node *parent(Node *) const;
    Node *firstChild(Node *) const;
    Node *nextSibling(Node *) const;
    void write(int, Node *);
    int read(Node *) const;
    void print(Node *);
private:
    Node *root;
};

#endif // !TREE_H