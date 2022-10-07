/**
 * @file    list.h
 * @author  Bruno Pezer (bruno.pezer@tutanota.com)
 * @brief   Generic doubly linked array-based list class definition.
 * @version 0.5
 * @date    2022-08-15
 * 
 * @copyright NO COPYRIGHT !(c) 2022
 * 
 */
#ifndef LIST_H
#define LIST_H
#include <iostream>
#include "node.h"

//  TODO:   fix double free detected error
template <typename T>
class List {
    friend std::ostream &operator<<(std::ostream &out, const List &list) {
        for (int i = 0; i < list.length; i++)
            out << list.contents[i].getData() << '\n';
        return out;
    }
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
    T read(position) const;
    void write(T, position);
    void insert(T, position);
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
    Node<T> *contents;
    unsigned int length, capacity;
};

template <typename T>
List<T>::List(unsigned int c) {
    capacity = c;
    length = 0;
    contents = new Node<T>[capacity];
}

template <typename T>
List<T>::List(const List<T> &rval) {
    capacity = rval.capacity;
    length = rval.length;
    contents = new Node<T>[capacity];
    for (int i = 0; i < length; i++)
        contents[i].setData(rval.contents[i].getData());
}

template <typename T>
List<T>::~List() { delete [] contents; }

template <typename T>
bool List<T>::isEmpty() const { return length == 0; }

template <typename T>
bool List<T>::endOfList(position p) const {
    if (0 < p && p <= length + 1)
        return (p == length + 1);
    else
        return false;
}

template <typename T>
bool List<T>::isValid(position p) const { return (0 < p && p < length + 1); }

template <typename T>
typename List<T>::position List<T>::first() const { return 1; }

template <typename T>
typename List<T>::position List<T>::last() const { return length; }

template <typename T>
typename List<T>::position List<T>::next(position p) const {
    if (isValid(p))
        return p + 1;
    else
        return p;
}

template <typename T>
typename List<T>::position List<T>::previous(position p) const {
    if (isValid(p))
        return p - 1;
    else
        return p;
}

template <typename T>
T List<T>::read(position p) const {
    if (!isValid(p))
        throw std::out_of_range{"List::read()"};
    return contents[p - 1].getData();
}

template <typename T>
void List<T>::write(T t, position p) {
    if (!isValid(p))
        throw std::out_of_range{"List::write()"};
    contents[p - 1].setData(t);
}

template <typename T>
void List<T>::insert(T t, position p) {
    if (length == capacity) { //  TODO: add setCapacity method
    }
    if (0 < p && p <= length + 1) {
        for (int i = length; i >= p; i--) {
            contents[i].setData(contents[i - 1].getData());
        }
        contents[p - 1].setData(t);
        ++length;
    }
}

template <typename T>
void List<T>::remove(position p) {
    if (!isValid(p))
        throw std::out_of_range{"List::remove()"};
    if (!isEmpty()) {
        for (int i = p - 1; i < length - 1; i++) {
            contents[i].setData(contents[i + 1].getData());
        }
        --length;
    }
}

template <typename T>
unsigned int List<T>::getCapacity() const { return capacity; }

template <typename T>
unsigned int List<T>::getLength() const { return length; }

template <typename T>
void List<T>::setCapacity(unsigned int c) {
    capacity = c;
    Node<T> *n = new Node<T>[capacity];
    for (int i = 0; i < length; i++)
        n[i].setData(contents[i].getData());
    delete [] contents;
    contents = n;
}

template <typename T>
bool List<T>::operator==(const List<T> &rval) const {
    if (length != rval.length) 
        return false;
    
    for (int i = 0; i < length; i++) {
        if (contents[i].getData() != rval.contents[i].getData())
            return false;
    }
    
    return true;
}

template <typename T>
bool List<T>::operator!=(const List<T> &rval) const { return !(*this == rval); }

template <typename T>
void List<T>::removeDuplicates() {
    position p = first(), q = next(p);
    while (!endOfList(p)) {
        while (!endOfList(q)) {
            if (read(p) == read(q))
                remove(q);
            else
                q = next(q);
        }
        p = next(p);
        q = next(p);
    }
}

template <typename T>
void List<T>::range(position p) {
    if (!isValid(p))
        throw std::out_of_range{"List::range()"};
    if (!isEmpty()) {
        position q = next(p);
        if (!endOfList(q)) {
            range(q);
            int a = read(p) + read(q);
            write(a, p);
        }
    }
}

#endif // LIST_H