/**
 * @file    node.h
 * @author  Bruno Pezer (bruno.pezer@tutanota.com)
 * @brief   Node class definition for use in an n-ary tree data structure
 * @version 1.3
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
                  Node * = nullptr);
    Node(const Node &);
    int getData() const;
    Node *getParent() const;
    Node *getNextSibling() const;
    Node *getFirstChild() const;
    void setData(int);
    void setParent(Node *);
    void setNextSibling(Node *);
    void setFirstChild(Node *);
    bool operator==(const Node &) const;
private:
    int data;
    Node *parent;
    Node *nextSibling;
    Node *firstChild;
};

#endif // !NODE_H
