/**
 * @file    node.h
 * @author  Bruno Pezer (bruno.pezer@tutanota.com)
 * @brief   Node class definition for use in a various pointer-based data structures
 * @version 1.0
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
    Node(int = 0, Node * = nullptr);
    Node(const Node &);
    int getData() const;
    Node *getNext() const;
    void setData(int);
    void setNext(Node *);
private:
    int data;
    Node *next;
};

#endif // !NODE_H
