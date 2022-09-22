/**
 * @file    list.h
 * @author  Bruno Pezer (bruno.pezer@tutanota.com)
 * @brief   Definition file for an array list data structure.
 *          The list contains integers.
 * @version 0.3
 * @date    2022-08-15
 * 
 * @copyright NO COPYRIGHT !(c) 2022
 * 
 */
#ifndef LIST_H
#define LIST_H
#include <iostream>

class List {
    const static int MAX_LENGTH = 1024;
    friend std::ostream &operator<<(std::ostream &, const List &);
public:
    typedef unsigned int position;

    List();
    List(int);
    List(const List &);

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

    //  Utility functions and operator overloads
    unsigned int getLength() const;
    bool isValid(position) const;
    bool operator==(const List &) const;
    bool operator!=(const List &) const;
private:
    unsigned int length;
    int data[MAX_LENGTH];
};

#endif  // LIST_H
