/**
 * @file    node.h
 * @author  Bruno Pezer (bruno.pezer@tutanota.com)
 * @brief   Node class definition for use in a binary tree data structure
 * @version 1.2
 * @date    2022-08-17
 * 
 * @copyright NO COPYRIGHT !(c) 2022
 * 
 */
#ifndef NODE_H
#define NODE_H
#include <iostream>

class Node {
    friend std::ostream &operator<<(const std::ostream &, const Node &);
    friend std::istream &operator>>(const std::istream &, const int &);
public:
    Node(int = 0, Node * = nullptr, 
                  Node * = nullptr, 
                  //Node * = nullptr, 
                  Node * = nullptr);
    Node(const Node &);
    int getData() const;
    Node *getParent() const;
    //Node *getSibling() const;
    Node *getLeftChild() const;
    Node *getRightChild() const;
    void setData(int);
    void setParent(Node *);
    //void setSibling(Node *);
    void setLeftChild(Node *);
    void setRightChild(Node *);
private:
    int data;
    Node *parent;
    //Node *sibling;
    Node *leftChild;
    Node *rightChild;
};

#endif // !NODE_H
