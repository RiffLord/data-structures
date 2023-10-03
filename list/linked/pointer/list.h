/**
 * @file    list.h
 * @author  Bruno Pezer
 * @brief   Generic pointer-based linked list data structure definition.
 * @version 0.3
 * @date    2022-08-17
 *
 * @copyright NO COPYRIGHT !(c) 2022
 *
 */
#ifndef LIST_H
#define LIST_H
#include "node.h"

/**
 * @brief    Generic pointer-based linked list
 *
 * @tparam T Represents the type of data stored in the list's nodes.
 */
template <typename T> class List {
    /**
     * @brief     Overloaded output operator for the List class. Prints each item in the list with a newline.
     *
     * @param out Output buffer
     * @param l   List to output
     * @return    out
     */
    friend std::ostream &operator<<(std::ostream &out, const List &l) {
        List::position p = l.first();
        while (!l.endOfList(p)) {
            out << l.read(p) << '\n';
            p = l.next(p);
        }
        return out;
    }
public:
    //  TODO: add function to use numbers for positions
    typedef Node<T> *position;
    List();
    List(const List &);
    ~List();

    bool isEmpty() const;
    bool endOfList(position) const;
    position first() const;
    position next(position) const;
    T read(position) const;
    void write(T, position);
    void insert(T, position);
    void remove(position);

    unsigned int getLength() const;
    List & operator=(const List &);
    bool operator==(const List &) const;
    bool operator!=(const List &) const;
private:
    Node<T> *head;
    unsigned int length;
};

/**
 * @brief    Creates an empty list of type T.
 *
 * @tparam T List type
 */
template <typename T>
List<T>::List() {
    head = nullptr;
    length = 0;
}

/**
 * @brief       Copies the contents of rval into a new list.
 *
 * @tparam T    List type
 * @param  rval Original list
 */
template <typename T>
List<T>::List(const List<T> &rval) {
    // TODO: Copy rval contents to a new list.
}

/**
 * @brief    Deletes the list to free memory.
 *
 * @tparam T List type
 */
template <typename T>
List<T>::~List() {
    while (!endOfList(head)) {
        position p = head;
        head = next(p);
        delete p;
        --length;
    }
    delete head;
}

/**
 * @brief    Checks if the list is empty.
 *
 * @tparam T List type
 * @return   true if the list is empty, false if not.
 */
template <typename T>
bool List<T>::isEmpty() const { return head == nullptr; }

/**
 * @brief    Verifies if the current position p is at the end of the list.
 *
 * @tparam T List type
 * @param p  Position within the list
 * @return   true if p is a null pointer (the last position in the list), false otherwise.
 */
template <typename T>
bool List<T>::endOfList(position p) const { return p == nullptr; }

/**
 * @brief    Returns the first node of the list.
 *
 * @tparam T List type
 * @return   List head
 */
template <typename T>
typename List<T>::position List<T>::first() const { return head; }

/**
 * @brief    Returns the position of the next node in the list.
 *
 * @tparam T List type
 * @param p  Current position in the list.
 * @return   The position of the next node in the list. If the current position is at the end of the list, the function returns it.
 */
template <typename T>
typename List<T>::position List<T>::next(position p) const {
    if (!endOfList(p))
        return p->getNext();
    else
        return p;
}

/**
 * @brief    Returns the item in the specified position within the list.
 *
 * @tparam T List type
 * @param p  Position of the item to read.
 * @return   The item of type T at the position p in the list.
 */
template <typename T>
T List<T>::read(position p) const {
    if (endOfList(p))
        throw std::out_of_range{"List::read()"};
    return p->getData();
}

/**
 * @brief     Overwrites the item at the specified position with the new data.
 *
 * @tparam T  List type
 * @param t   Data to write in the list.
 * @param p   Position in the list in which to write the new data.
 */
template <typename T>
void List<T>::write(T t, position p) {
    if (endOfList(p))
        throw std::out_of_range{"List::write()"};
    p->setData(t);
}

//  TODO:   try using only endOfList(p) condition for empty list as well
/**
 * @brief    Inserts a new item into the list, increasing its length.
 *
 * @tparam T List type
 * @param t  Data to insert into the list.
 * @param p  Position in the list in which to insert the new data.
 */
template <typename T>
void List<T>::insert(T t, position p) {
    position q = new Node<T>(t);    // Creates a new node with the provided data.
    if (isEmpty()) {
        head = q;
    } else if (endOfList(p)) {
        position iterator = head;
        while (iterator->getNext() != p) iterator = iterator->getNext();
        iterator->setNext(q);
    } else if (p == first()) {
        q->setNext(p->getNext());
        p->setNext(q);
    } else {
        position iterator = head;
        while (iterator->getNext() != p) iterator = iterator->getNext();
        iterator = q;
        iterator->setNext(p->getNext());
        p->setNext(iterator);
    }
    ++length;
}

/**
 * @brief    Removes an item from the list, decreasing its length.
 *
 * @tparam T List type
 * @param p  Position of the item to remove from the list.
 */
template <typename T>
void List<T>::remove(position p) {
    if (p == head)
        head = p->getNext();
    else {
        position iterator = head;
        while (iterator->getNext() != p) {
            iterator = iterator->getNext();
        }
        iterator->setNext(p->getNext());
    }
    delete p;
    --length;
}

/**
 * @brief    Returns the number of items in the list.
 *
 * @tparam T List type
 * @return   List length
 */
template <typename T>
unsigned int List<T>::getLength() const { return length; }

//  TODO:   fix overloaded = operator
/**
 * @brief           Overloaded assignment operator for the List class.
 *
 * @tparam T        List type
 * @param rval      List to copy
 * @return List<T>& New list, identical to rval.
 */
template <typename T>
List<T> &List<T>::operator=(const List<T> &rval) {
    position p = head, q = rval.head;
    while (!rval.endOfList(q)) {
        insert(rval.read(q), p);
        std::cout << "item inserted\n";
        q = rval.next(q);
        p = next(p);
    }
    //  If the left value list is larger
    //  than the right value list, remove
    //  its remaining items
    if (!endOfList(p)) {
        while (!endOfList(p)) {
            position temp = p->getNext();
            remove(temp);
        }
        std::cout << "removing excess items?\n";
    }
    std::cout << "exiting operator=\n";
}

/**
 * @brief      Overloaded equality operator.
 *
 * @tparam T   List type
 * @param rval List to compare
 * @return     True if this list and rval are equal, false otherwise.
 */
template <typename T>
bool List<T>::operator==(const List<T> &rval) const {
    if (length != rval.length)
        return false;
    List::position p = head, q = rval.head;
    while (!endOfList(p)) {
        if (read(p) != rval.read(q)) return false;
        p = p->getNext();
        q = q->getNext();
    }
    return true;
}

/**
 * @brief      Overloaded inequality operator.
 *
 * @tparam T   List type
 * @param rval List to compare
 * @return     True if this list and rval are not equal, false otherwise.
 */
template <typename T>
bool List<T>::operator!=(const List<T> &rval) const { return !(*this == rval); }

#endif // !LIST_H
