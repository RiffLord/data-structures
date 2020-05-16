#ifndef SET_H
#define SET_H

#include <iostream>
#include "linked_list.h"

template<class T>
class set {
    typedef T data_type;

    friend std::ostream& operator<<(std::ostream& out, const set<T>& A) {
        out << '{';
        typename linked_list<T>::position p = A.contents.first();
        while (!A.contents.end(p)) {
            out << A.contents.read(p);
            p = A.contents.next(p);
            if (!A.contents.end(p)) out << ", ";
        }
        out << '}' << std::endl;
        return out;
    }

    //  Set operations
    friend set<T> getUnion(set<T>& A, set<T>& B) {
        set<T> C = A;
        typename linked_list<T>::position p = B.contents.first();
        while (!B.contents.end(p)) {
            typename set<T>::data_type item = B.contents.read(p);
            C.insert(item);
            p = B.contents.next(p);
        }
        return C;
    }

    friend set<T> intersect(set<T>& A, set<T>& B) {
        set<T> C;
        typename linked_list<T>::position p = A.contents.first();
        while (!A.contents.end(p)) {
            if (B.contains(A.contents.read(p)))
                C.insert(A.contents.read(p));

            p = A.contents.next(p);
        }
        return C;
    }

    friend set<T> difference(set<T>& A, set<T>& B) {
        set<T> C;
        typename linked_list<T>::position p = A.contents.first();
        while (!A.contents.end(p)) {
            typename set<T>::data_type item = A.contents.read(p);
            if (!B.contains(item)) C.insert(item);
            p = A.contents.next(p);
        }
        return C;
    }

public:
    set();
    ~set();
    bool isEmpty() const;
    bool contains(data_type) const;
    int size() const;
    void insert(data_type);
    void remove(data_type);
private:
    linked_list<T> contents;
};

template<class T>
set<T>::set() {}

template<class T>
set<T>::~set() {}

template<class T>
bool set<T>::isEmpty() const { return contents.isEmpty(); }

template<class T>
bool set<T>::contains(data_type d) const {
    if (!isEmpty()) {
        typename linked_list<T>::position p = contents.first();
        while (!contents.end(p)) {
            if (contents.read(p) == d) return true;
            p = contents.next(p);
        }
    }
    return false;
}

template<class T>
void set<T>::insert(data_type d) {
    if (!contains(d))
        contents.insert(d, contents.last());
}

template<class T>
void set<T>::remove(data_type d) {
        typename linked_list<T>::position p = contents.first();
        while (!contents.end(p))
            if (contents.read(p) == d) {
                contents.remove(p);
            } else p = contents.next(p);
}

template<class T>
int set<T>::size() const { return contents.size(); }

#endif // SET_H