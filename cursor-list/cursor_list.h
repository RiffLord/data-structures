#ifndef LIST_H
#define LIST_H

template<class T>
class list;

template<class T>
class node {
    friend class list<T>;
    typedef T data_type;
private:
    data_type content;
    int next;
}

template<class T>
class list {
    typedef node<T>::data_type data_type;
public:
    list();
    ~list();
    void init();
private:
    static node<T> SPACE[100];
    //  Functions for manipulating the SPACE array defined here.
    int length;
}

template<class T>
list<T>::list() {}

template<class T>
list<T>::~list() {}

template<class T>
void list<T>::init() { length = 0; }

#endif // LIST_H
