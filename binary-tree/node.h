#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <iomanip>

template<class T>
class node {
public:
    node() { 
        father = nullptr; 
        leftSon = nullptr;
        rightSon = nullptr;
    }
    ~node() {
        father = nullptr;
        delete father;
        delete leftSon; 
        delete rightSon;
    }
    T getData() const { return data; }
    void setData(T d) { data = d; }
    node<T>* getFather() const { return father; }
    void setFather(node<T>* f) { father = f; }
    node<T>* getLeftChild() const { return leftSon; }
    void setLeftChild(node<T>* ls) { leftSon = ls; }
    node<T>* getRightChild() const { return rightSon; }
    void setRightChild(node<T>* rs) { rightSon = rs; }
private:
    T data;
    node<T>* father;
    node<T>* leftSon;
    node<T>* rightSon;
};

#endif // !NODE_H