#ifndef NODE_H
#define NODE_H

#include "stack.h"
#include "queue.h"

template<class T>
class queue;

template<class T>
class stack;

template <class T>
class node {
    typedef T data_type;
    friend class stack<T>;
    friend class queue<T>;
public:
    node() { next = nullptr; }
    data_type getValue() const { return value; }
    node<T>* next;
private:
    data_type value;
};

#endif // NODE_H
