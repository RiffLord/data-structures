/**
 * @file    list.h
 * @author  Bruno Pezer (bruno.pezer@tutanota.com)
 * @brief   Generic pointer-based linked list data structure definition
 * @version 0.3
 * @date    2022-08-17
 * 
 * @copyright NO COPYRIGHT !(c) 2022
 * 
 */
#ifndef LIST_H
#define LIST_H
#include "node.h"

template <typename T> class List {
    friend std::ostream &operator<<(std::ostream &out, const List &l) {
        List::position p = l.first();
        while (!l.endOfList(p)) {
            out << l.read(p) << '\n';
            p = l.next(p);
        }
        return out;
    }
public:
    //  TODO:   add function to use numbers for positions
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
    void print();

    unsigned int getLength() const;
    List & operator=(const List &);
    bool operator==(const List &) const;
    bool operator!=(const List &) const;
private:
    Node<T> *head;
    unsigned int length;
};

template <typename T>
List<T>::List() { 
    head = nullptr;
    length = 0;
}

template <typename T>
List<T>::List(const List<T> &rval) {}

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

template <typename T>
bool List<T>::isEmpty() const { return head == nullptr; }

template <typename T>
bool List<T>::endOfList(position p) const { return p == nullptr; }

template <typename T>
typename List<T>::position List<T>::first() const { return head; }

template <typename T>
typename List<T>::position List<T>::next(position p) const {
    if (!endOfList(p)) 
        return p->getNext();
    else 
        return p; 
}

template <typename T>
T List<T>::read(position p) const { 
    if (endOfList(p))
        throw std::out_of_range{"List::read()"};
    return p->getData();
}

template <typename T>
void List<T>::write(T t, position p) {
    if (endOfList(p))
        throw std::out_of_range{"List::write()"};
    p->setData(t);
}

//  TODO:   try using only endOfList(p) condition for empty list as well
template <typename T>
void List<T>::insert(T t, position p) {
    position q = new Node<T>(t);
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

template <typename T>
void List<T>::remove(position p) {
    if (p == head)
        head = p->getNext();
    else {
        position iterator = head;
        while (iterator->getNext() != p) 
        {
            iterator = iterator->getNext();
        }
        iterator->setNext(p->getNext()); 
    }
    delete p;
    --length;
}

template <typename T>
unsigned int List<T>::getLength() const { return length; }

//  TODO:   fix overloaded = operator
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
            remove(p);
        }
        std::cout << "removing excess items?\n";
    }
    std::cout << "exiting operator=\n";
}

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

template <typename T>
bool List<T>::operator!=(const List<T> &rval) const { return !(*this == rval); }

template <typename T>
void List<T>::print() {
    using namespace std;
    List::position p = head;
    while (!endOfList(p)) {
        cout << read(p) << endl;
        p = next(p);
    }
}

#endif // !LIST_H
