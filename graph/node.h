#ifndef NODE_H
#define NODE_H

#include <cstddef>
#include <iostream>
#include <stdlib.h>
#include <string>

template<class T>
class node {
public:
    node();
    ~node();
    void setInfo(T);
    T getInfo() const;
    void visitState(bool);
    bool visit() const;
    bool isEmpty() const;
    void setDistance(int);
    int getDistance() const;
private:
    T info;
    bool visited;
    bool empty;
    int distance;
};

template<class T>
node<T>::node() {
    empty = true;
    visited = false;
    distance = 0;
}

template<class T>
node<T>::~node() {}

template<class T>
void node<T>::setInfo(T t) { 
    info = t; 
    empty = false;
}

template<class T>
T node<T>::getInfo() const { return info; }

template<class T>
void node<T>::visitState(bool state) { visited = state; }

template<class T>
bool node<T>::visit() const { return visited; }

template<class T>
bool node<T>::isEmpty() const { return empty; }

template<class T>
void node<T>::setDistance(int d) { distance = d; }

template<class T>
int node<T>::getDistance() const { return distance; }

#endif // NODE_H