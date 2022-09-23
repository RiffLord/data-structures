/**
 * @file    tree.h
 * @author  Bruno Pezer (bruno.pezer@tutanota.com)
 * @brief   Binary tree data structure definition
 * @version 0.4
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
    Tree(/* args */);
    Tree(const Tree &);
    Tree(Node *);
    ~Tree();
    Node *getRoot() const;
    Node *parent(Node *) const;
    Node *leftChild(Node *) const;
    Node *rightChild(Node *) const;
    int readNode(Node *) const;
    bool isEmpty() const;
    bool isLeaf(Node *) const;
    bool hasLeftChild(Node *) const;
    bool hasRightChild(Node *) const;
    void setRoot(Node *);
    void setValue(int, Node *);
    void addSubtree(Node *, Node *, const Tree &);
    void removeSubtree(Node *);
    unsigned int getHeight() const;
    
    bool isComplete() const;
private:
    Node *root;
    unsigned int height;
    unsigned int totalNodes;
};

#endif // !TREE_H
