/**
 * @file    list.h
 * @author  Bruno Pezer (bruno.pezer@tutanota.com)
 * @brief   Pointer-based linked list data structure definition
 * @version 0.1
 * @date    2022-08-17
 * 
 * @copyright NO COPYRIGHT !(c) 2022
 * 
 */
#ifndef LIST_H
#define LIST_H
#include "node.h"

class List {
    friend std::ostream &operator<<(std::ostream &, const List &);
public:
    //  TODO:   add function to use numbers for positions
    typedef Node *position;
    List();
    List(const List &);
    ~List();

    bool isEmpty() const;
    bool endOfList(position) const;
    position first() const;
    position next(position) const;
    int read(position) const;
    void write(int, position);
    void insert(int, position);
    void remove(position);

    unsigned int getLength() const;
    List & operator=(const List &);
    bool operator==(const List &) const;
    bool operator!=(const List &) const;
private:
    Node *head;
    unsigned int length;
};

#endif // !LIST_H
