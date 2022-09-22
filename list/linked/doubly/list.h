/**
 * @file    list.h
 * @author  Bruno Pezer (bruno.pezer@tutanota.com)
 * @brief   Doubly linked array-based list class definition.
 * @version 0.4
 * @date    2022-08-15
 * 
 * @copyright NO COPYRIGHT !(c) 2022
 * 
 */
#ifndef LIST_H
#define LIST_H
#include <iostream>
#include "node.h"

class List {
    friend std::ostream &operator<<(std::ostream &, const List &);
public:
    typedef unsigned int position;

    List(unsigned int = 10);
    List(const List &);
    ~List();

    bool isEmpty() const;
    bool endOfList(position) const;
    position first() const;
    position last() const;
    position next(position) const;
    position previous(position) const;
    int read(position) const;
    void write(int, position);
    void insert(int, position);
    void remove(position);

    //  Utility functions & overloaded operators
    unsigned int getCapacity() const;
    unsigned int getLength() const;
    void setCapacity(unsigned int);
    bool isValid(position) const;
    void removeDuplicates();
    void range(position);
    bool operator==(const List &) const;
    bool operator!=(const List &) const;
private:
    Node *contents;
    unsigned int length, capacity;
};

#endif // LIST_H