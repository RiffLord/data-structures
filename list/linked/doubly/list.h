/**
 * @file    list.h
 * @author  Bruno Pezer
 * @brief   Generic doubly linked array-based list class definition.
 * @version 0.7
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
/**
 * @brief    Doubly-linked array list.
 *
 * @tparam T List type
 */
template <typename T>
class List {
    /**
     * @brief                Overloaded output operator. Prints each item in the list followed by a newline.
     *
     * @param out            Output
     * @param list           List to print
     * @return std::ostream& Output
     */
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

/**
 * @brief    Creates a new list.
 *
 * @tparam T List type
 * @param c  List size
 */
template <typename T>
List<T>::List(unsigned int c) {
    capacity = c;
    length = 0;
    contents = new Node<T>[capacity];
}

/**
 * @brief      Creates a new list copying the contents of the parameter.
 *
 * @tparam T   List type
 * @param rval List to copy
 */
template <typename T>
List<T>::List(const List<T> &rval) {
    capacity = rval.capacity;
    length = rval.length;
    contents = new Node<T>[capacity];
    for (int i = 0; i < length; i++)
        contents[i].setData(rval.contents[i].getData());
}

/**
 * @brief    Class destructor.
 *
 * @tparam T List type
 */
template <typename T>
List<T>::~List() { delete [] contents; }

/**
 * @brief    Checks if the list is empty.
 *
 * @tparam T List type
 * @return   true if the list is empty, false if not.
 */
template <typename T>
bool List<T>::isEmpty() const { return length == 0; }

/**
 * @brief    Verifies if the current position p is at the end of the list.
 *
 * @tparam T List type
 * @param p  Position within the list
 * @return   true if p is greater than zero and lesser than the list length, false otherwise.
 */
template <typename T>
bool List<T>::endOfList(position p) const {
    if (0 < p && p <= length + 1)
        return (p == length + 1);
    else
        return false;
}

/**
 * @brief    Checks if the provided position is within the list boundaries.
 *
 * @tparam T List type
 * @param p  Position to verify.
 * @return   true if the position is between 0 and the list lenght, false otherwise.
 */
template <typename T>
bool List<T>::isValid(position p) const { return (0 < p && p < length + 1); }

/**
 * @brief    Returns the first position in the list.
 *
 * @tparam T List type
 * @return   1
 */
template <typename T>
typename List<T>::position List<T>::first() const { return 1; }

/**
 * @brief    Returns the last position in the list.
 *
 * @tparam T List type
 * @return   List length
 */
template <typename T>
typename List<T>::position List<T>::last() const { return length; }

/**
 * @brief    Returns the next position in the list if the current position is valid.
 *
 * @tparam T List type
 * @param p  Current position
 * @return   p + 1
 */
template <typename T>
typename List<T>::position List<T>::next(position p) const {
    // TODO: throw out of index error if the position is not valid.
    if (isValid(p))
        throw std::out_of_range{"List::next()"};
        //return p + 1;
    else
        return p;
}

/**
 * @brief    Returns the previous position in the list if the current position is valid.
 *
 * @tparam T List type
 * @param p  Current position
 * @return   p - 1
 */
template <typename T>
typename List<T>::position List<T>::previous(position p) const {
    // TODO: throw out of index error if the position is not valid.
    if (isValid(p))
        return p - 1;
    else
        return p;
}

/**
 * @brief    Obtains the list contents at the given position, if the position is valid.
 *
 * @tparam T List type
 * @param p  Current position
 * @return   List data at position p.
 */
template <typename T>
T List<T>::read(position p) const {
    if (!isValid(p))
        throw std::out_of_range{"List::read()"};
    return contents[p - 1].getData();
}

/**
 * @brief    Write the provided data at the given position within the list, if the position is valid.
 *
 * @tparam T List type
 * @param t  Data to write.
 * @param p  Position in which to write the data.
 */
template <typename T>
void List<T>::write(T t, position p) {
    if (!isValid(p))
        throw std::out_of_range{"List::write()"};
    contents[p - 1].setData(t);
}

/**
 * @brief    Adds the provided data to the list at the given position, increasing the list's length, if the position is valid.
 *
 * @tparam T List type
 * @param t  Data to add to the list.
 * @param p  Position in which to add the data.
 */
template <typename T>
void List<T>::insert(T t, position p) {
    if (length == capacity) {
        //  TODO: add setCapacity method
    }
    if (0 < p && p <= length + 1) {
        for (int i = length; i >= p; i--) {
            contents[i].setData(contents[i - 1].getData());
        }
        contents[p - 1].setData(t);
        ++length;
    }
}

/**
 * @brief    Removes the data from the list at the given position, decreasing the length if the position is valid.
 *
 * @tparam T List type
 * @param p  Current position
 */
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

/**
 * @brief    Returns the list's maximum length.
 *
 * @tparam T List type
 * @return   List capacity
 */
template <typename T>
unsigned int List<T>::getCapacity() const { return capacity; }

/**
 * @brief    Returns the list's current length.
 *
 * @tparam T List type
 * @return   List length
 */
template <typename T>
unsigned int List<T>::getLength() const { return length; }

/**
 * @brief    Changes the list's maximum size according to the value provided.
 *
 * @tparam T List type
 * @param c  New list capacity.
 */
template <typename T>
void List<T>::setCapacity(unsigned int c) {
    capacity = c;
    Node<T> *n = new Node<T>[capacity];
    for (int i = 0; i < length; i++)
        n[i].setData(contents[i].getData());
    delete [] contents;
    contents = n;
}

/**
 * @brief      Overloaded equality operator.
 *
 * @tparam T   List type
 * @param rval List to compare.
 * @return     true if the lists are identical, false otherwise.
 */
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

/**
 * @brief      Overloaded inequality operator.
 *
 * @tparam T   List type
 * @param rval List to compare.
 * @return     true if the lists are different, false otherwise.
 */
template <typename T>
bool List<T>::operator!=(const List<T> &rval) const { return !(*this == rval); }

/**
 * @brief    Removes duplicate items from the list.
 *
 * @tparam T List type
 */
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

/**
 * @brief
 *
 * @tparam T
 * @param p
 */
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