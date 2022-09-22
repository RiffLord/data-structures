/**
 * @file    list.cpp
 * @author  Bruno Pezer (bruno.pezer@tutanota.com)
 * @brief   Implementation file for an array list data structure.
 *          The list contains integers.
 * @version 0.3
 * @date    2022-08-15
 * 
 * @copyright NO COPYRIGHT !(c) 2022
 * 
 */
#include "list.h"

List::List() { length = 0; }

List::List(int l) { length = l; }

List::List(const List &rval) : length(rval.length) {
    for (int i = 0; i < length; i++)
        data[i] = rval.data[i];
}

bool List::isEmpty() const { return length == 0; }

bool List::isValid(position p) const { return 0 < p && p < length + 1; }

bool List::endOfList(position p) const {
    if (0 < p && p <= length + 1)
        return p == (length + 1);
    else
        return false;
}

List::position List::first() const { return 1; }

List::position List::last() const { return length; }

//  TODO:   Throw out_of_range if p is not a valid position
List::position List::next(position p) const {
    if (isValid(p))
        return p + 1;
    else
        return p;
}

//  TODO:   Throw out_of_range if p is not a valid position
List::position List::previous(position p) const {
    if (isValid(p))
        return p - 1;
    else
        return p;
}

int List::read(position p) const {
    if (!isValid(p))
        throw std::out_of_range{"List::read()"};
    return data[p - 1];
}

void List::write(int t, position p) {
    if (!isValid(p))
        throw std::out_of_range{"List::write()"};
    data[p - 1] = t;
}

void List::insert(int t, position p) {
    if (0 < p && p <= length + 1) {
        for (int i = length; i >= p; i--) data[i] = data[i - 1];
        data[p - 1] = t;
        ++length;
    }
}

void List::remove(position p) {
    if (!isValid(p)) throw std::out_of_range{"List::remove()"};
    if (!isEmpty()) {
        for (int i = p - 1; i < length - 1; i++) data[i] = data[i + 1];
        --length;
    }
}

unsigned int List::getLength() const { return length; }

std::ostream &operator<<(std::ostream &out, const List &l) {
    for (int i = 0; i < l.length; i++) out << l.data[i] << '\n';
    return out;
}

bool List::operator==(const List &rval) const {
    if (getLength() != rval.getLength())
        return false;
    
    position p = first();
    while (p != last()) {
        if (read(p) != rval.read(p)) return false;
        p = next(p);
    }
    
    return true;
}

bool List::operator!=(const List &rval) const { return !(*this == rval); }
