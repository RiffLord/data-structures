/**
 * @file    list.cpp
 * @author  Bruno Pezer (bruno.pezer@tutanota.com)
 * @brief   Pointer-based linked list data structure implementation
 * @version 0.2
 * @date    2022-08-17
 * 
 * @copyright NO COPYRIGHT !(c) 2022
 * 
 */
#include "list.h"

List::List() { 
    head = nullptr;
    length = 0;
}

List::List(const List &rval) {}

List::~List() {
    while (!endOfList(head)) {
        position p = head;
        head = next(p);
        delete p;  
        --length;
    }
    delete head;
}

bool List::isEmpty() const { return head == nullptr; }

bool List::endOfList(position p) const { return p == nullptr; }

List::position List::first() const { return head; }

List::position List::next(position p) const {
    if (!endOfList(p)) 
        return p->getNext();
    else 
        return p; 
}

int List::read(position p) const { 
    if (endOfList(p))
        throw std::out_of_range{"List::read()"};
    return p->getData();
}

void List::write(int t, position p) {
    if (endOfList(p))
        throw std::out_of_range{"List::write()"};
    p->setData(t);
}

//  TODO:   try using only endOfList(p) condition for empty list as well
void List::insert(int t, position p) {
    position q = new Node(t);
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

void List::remove(position p) {
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

unsigned int List::getLength() const { return length; }

std::ostream &operator<<(std::ostream &out, const List &list) {
    List::position p = list.first();
    while (!list.endOfList(p)) {
        out << list.read(p) << '\n';
        p = list.next(p);
    }
    return out;
}

//  TODO:   fix overloaded = operator
List &List::operator=(const List &rval) {
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

bool List::operator==(const List &rval) const {
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

bool List::operator!=(const List &rval) const { return !(*this == rval); }
