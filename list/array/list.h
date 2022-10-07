/**
 * @file    list.h
 * @author  Bruno Pezer (bruno.pezer@tutanota.com)
 * @brief   Definition file for a generic array-based list data structure.
 * @version 0.4
 * @date    2022-08-15
 * 
 * @copyright NO COPYRIGHT !(c) 2022
 * 
 */
#ifndef LIST_H
#define LIST_H
#include <iostream>

//  TODO:   add int max_length to template for dynamically allocated lists
template <typename T>
class List {
    const static int MAX_LENGTH = 1024;
    friend std::ostream &operator<<(std::ostream &out, const List &l) {
        for (int i = 0; i < l.length; i++) out << l.data[i] << '\n';
        return out;
    }
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

template <typename T>
List<T>::List() { length = 0; }

template <typename T>
List<T>::List(int l) { length = l; }

template <typename T>
List<T>::List(const List<T> &rval) : length(rval.length) {
    for (int i = 0; i < length; i++)
        data[i] = rval.data[i];
}

template <typename T>
bool List<T>::isEmpty() const { return length == 0; }

template <typename T>
bool List<T>::isValid(position p) const { return 0 < p && p < length + 1; }

template <typename T>
bool List<T>::endOfList(position p) const {
    if (0 < p && p <= length + 1)
        return p == (length + 1);
    else
        return false;
}

template <typename T>
typename List<T>::position List<T>::first() const { return 1; }

template <typename T>
typename List<T>::position List<T>::last() const { return length; }

//  TODO:   Throw out_of_range if p is not a valid position
template <typename T>
typename List<T>::position List<T>::next(position p) const {
    if (isValid(p))
        return p + 1;
    else
        return p;
}

//  TODO:   Throw out_of_range if p is not a valid position
template <typename T>
typename List<T>::position List<T>::previous(position p) const {
    if (isValid(p))
        return p - 1;
    else
        return p;
}

template <typename T>
int List<T>::read(position p) const {
    if (!isValid(p))
        throw std::out_of_range{"List::read()"};
    return data[p - 1];
}

template <typename T>
void List<T>::write(int t, position p) {
    if (!isValid(p))
        throw std::out_of_range{"List::write()"};
    data[p - 1] = t;
}

template <typename T>
void List<T>::insert(int t, position p) {
    if (0 < p && p <= length + 1) {
        for (int i = length; i >= p; i--) data[i] = data[i - 1];
        data[p - 1] = t;
        ++length;
    }
}

template <typename T>
void List<T>::remove(position p) {
    if (!isValid(p)) throw std::out_of_range{"List::remove()"};
    if (!isEmpty()) {
        for (int i = p - 1; i < length - 1; i++) data[i] = data[i + 1];
        --length;
    }
}

template <typename T>
unsigned int List<T>::getLength() const { return length; }

template <typename T>
bool List<T>::operator==(const List<T> &rval) const {
    if (getLength() != rval.getLength())
        return false;
    
    position p = first();
    while (p != last()) {
        if (read(p) != rval.read(p)) return false;
        p = next(p);
    }
    
    return true;
}

template <typename T>
bool List<T>::operator!=(const List<T> &rval) const { return !(*this == rval); }

#endif  // LIST_H
