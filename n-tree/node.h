#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <iomanip>
#include <assert.h>

using namespace std;

template<class T>
class node {
public:
    node();
    ~node();
    void setData(T);
    T getData() const;
    void setFirstChild(node<T>*);
    node<T>* getFirstChild() const;
    void setNextBrother(node<T>*);
    node<T>* getNextBrother() const;
    void setFather(node<T>*);
    node<T>* getFather() const;
private:
    T data;
    node<T>* father;
    node<T>* nextBrother;
    node<T>* firstChild;
};

template<class T>
node<T>::node() {
    father = nullptr;
    nextBrother = nullptr;
    firstChild = nullptr;
}

template<class T>
node<T>::~node() {}

template<class T>
void node<T>::setData(T value) { data = value; }

template<class T>
T node<T>::getData() const { return data; }

template<class T>
void node<T>::setFirstChild(node<T>* child) { firstChild = child; }

template<class T>
node<T>* node<T>::getFirstChild() const { return firstChild; }

template<class T>
void node<T>::setNextBrother(node<T>* brother) { nextBrother = brother; }

template<class T>
node<T>* node<T>::getNextBrother() const { return nextBrother; }

template<class T>
void node<T>::setFather(node<T>* f) { father = f; }

template<class T>
node<T>* node<T>::getFather() const { return father; } 

#endif // NODE_H