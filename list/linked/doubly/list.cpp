/**
 * @file    list.cpp
 * @author  Bruno Pezer (bruno.pezer@tutanota.com)
 * @brief   Doubly linked array-based list class definition.
 * @version 0.4
 * @date    2022-08-15
 * 
 * @copyright NO COPYRIGHT !(c) 2022
 * 
 */
#include "list.h"

List::List(unsigned int c) {
    capacity = c;
    length = 0;
    contents = new Node[capacity];
}

List::List(const List &rval) {
    capacity = rval.capacity;
    length = rval.length;
    contents = new Node[capacity];
    for (int i = 0; i < length; i++)
        contents[i].setData(rval.contents[i].getData());
}

List::~List() { delete [] contents; }

bool List::isEmpty() const { return length == 0; }

bool List::endOfList(position p) const {
    if (0 < p && p <= length + 1)
        return (p == length + 1);
    else
        return false;
}

bool List::isValid(position p) const { return (0 < p && p < length + 1); }

List::position List::first() const { return 1; }

List::position List::last() const { return length; }

List::position List::next(position p) const {
    if (isValid(p))
        return p + 1;
    else
        return p;
}

List::position List::previous(position p) const {
    if (isValid(p))
        return p - 1;
    else
        return p;
}

int List::read(position p) const {
    if (!isValid(p))
        throw std::out_of_range{"List::read()"};
    return contents[p - 1].getData();
}

void List::write(int t, position p) {
    if (!isValid(p))
        throw std::out_of_range{"List::write()"};
    contents[p - 1].setData(t);
}

void List::insert(int t, position p) {
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

void List::remove(position p) {
    if (!isValid(p))
        throw std::out_of_range{"List::remove()"};
    if (!isEmpty()) {
        for (int i = p - 1; i < length - 1; i++) {
            contents[i].setData(contents[i + 1].getData());
        }
        --length;
    }
}

unsigned int List::getCapacity() const { return capacity; }

unsigned int List::getLength() const { return length; }

void List::setCapacity(unsigned int c) {
    capacity = c;
    Node *n = new Node[capacity];
    for (int i = 0; i < length; i++)
        n[i].setData(contents[i].getData());
    delete [] contents;
    contents = n;
}

bool List::operator==(const List &rval) const {
    if (length != rval.length) 
        return false;
    
    for (int i = 0; i < length; i++) {
        if (contents[i].getData() != rval.contents[i].getData())
            return false;
    }
    
    return true;
}

bool List::operator!=(const List &rval) const { return !(*this == rval); }

std::ostream &operator<<(std::ostream &out, const List &list) {
    for (int i = 0; i < list.length; i++)
        out << list.contents[i].getData() << '\n';
    return out;
}

void List::removeDuplicates() {
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

void List::range(position p) {
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
