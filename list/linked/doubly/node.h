/**
 * @file    node.h
 * @author  Bruno Pezer (bruno.pezer@tutanota.com)
 * @brief   Node class definition for use in various pointer-based data structures
 * @version 1.0
 * @date    2022-08-15
 * 
 * @copyright NO COPYRIGHT !(c) 2022
 * 
 */
#ifndef NODE_H
#define NODE_H

class Node {
public:
    Node(int = 0);
    Node(const Node &);

    void setData(int);
    int getData() const;

    bool operator==(const Node &) const;
    bool operator!=(const Node &) const;
private:
    int data;
};

#endif // !NODE_H
