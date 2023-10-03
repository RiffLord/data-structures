/**
 * @file    list.h
 * @author  Bruno Pezer
 * @brief   Definition of a generic array-based list data structure.
 * @version 0.6
 * @date    2022-08-15
 *
 * @copyright NO COPYRIGHT !(c) 2022
 *
 */
#ifndef LIST_H
#define LIST_H
#include <iostream>

/**
 * @brief    Generic array-list
 *
 * @tparam T List type
 */
template <typename T>
class List {
    const static int MAX_LENGTH = 1024;
    /**
     * @brief     Overloaded output operator for the list class. Prints each item in the list with a newline.
     *
     * @param out Output buffer
     * @param l   List to output
     * @return    out
     */
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

/**
 * @brief    List constructor. Initializes an empty list of length 0.
 *
 * @tparam T List type
 */
template <typename T>
List<T>::List() { length = 0; }

/**
 * @brief    Initializes an empty list of a given length.
 *
 * @tparam T List type
 * @param l  List length
 */
template <typename T>
List<T>::List(int l) { length = l; }

/**
 * @brief      Copy constructor. Creates a new list using the given list.
 *
 * @tparam T   List type
 * @param rval List to copy
 */
template <typename T>
List<T>::List(const List<T> &rval) : length(rval.length) {
    for (int i = 0; i < length; i++)
        data[i] = rval.data[i];
}

/**
 * @brief    Checks if the list is empty.
 *
 * @tparam T List type
 * @return   true if the list is empty, false if not.
 */
template <typename T>
bool List<T>::isEmpty() const { return length == 0; }

/**
 * @brief    Checks if the provided position is within the list boundaries.
 *
 * @tparam T List type
 * @param p  Position to verify.
 * @return   true if the position is between 0 and the list lenght, false otherwise.
 */
template <typename T>
bool List<T>::isValid(position p) const { return 0 < p && p < length + 1; }

template <typename T>
bool List<T>::endOfList(position p) const {
    if (0 < p && p <= length + 1)
        return p == (length + 1);
    else
        return false;
}

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

template <typename T>
typename List<T>::position List<T>::next(position p) const {
    if (!isValid(p))
        throw std::out_of_range{"List::next()"};
    return p + 1;
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
    if (!isValid(p))
        throw std::out_of_range{"List::previous()"};
    return p - 1;
}

/**
 * @brief    Obtains the list contents at the given position, if the position is valid.
 *
 * @tparam T List type
 * @param p  Current position
 * @return   List data at position p.
 */
template <typename T>
int List<T>::read(position p) const {
    if (!isValid(p))
        throw std::out_of_range{"List::read()"};
    return data[p - 1];
}

/**
 * @brief    Write the provided data at the given position within the list, if the position is valid.
 *
 * @tparam T List type
 * @param t  Data to write.
 * @param p  Position in which to write the data.
 */
template <typename T>
void List<T>::write(int t, position p) {
    if (!isValid(p))
        throw std::out_of_range{"List::write()"};
    data[p - 1] = t;
}

/**
 * @brief    Adds the provided data to the list at the given position, increasing the list's length, if the position is valid.
 *
 * @tparam T List type
 * @param t  Data to add to the list.
 * @param p  Position in which to add the data.
 */
template <typename T>
void List<T>::insert(int t, position p) {
    if (0 < p && p <= length + 1) {
        for (int i = length; i >= p; i--) data[i] = data[i - 1];
        data[p - 1] = t;
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
    if (!isValid(p)) throw std::out_of_range{"List::remove()"};
    if (!isEmpty()) {
        for (int i = p - 1; i < length - 1; i++) data[i] = data[i + 1];
        --length;
    }
}

/**
 * @brief    Returns the list's current length.
 *
 * @tparam T List type
 * @return   List length
 */
template <typename T>
unsigned int List<T>::getLength() const { return length; }

/**
 * @brief      Overloaded equality operator.
 *
 * @tparam T   List type
 * @param rval List to compare.
 * @return     true if the lists are identical, false otherwise.
 */
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

/**
 * @brief      Overloaded inequality operator.
 *
 * @tparam T   List type
 * @param rval List to compare.
 * @return     true if the lists are different, false otherwise.
 */
template <typename T>
bool List<T>::operator!=(const List<T> &rval) const { return !(*this == rval); }

#endif  //!LIST_H
