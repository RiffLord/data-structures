//  Pointer implementation of a stack.
#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <assert.h>

template <class T>
class stack;

template <class T>
class sNode {
    typedef T data_type;
    friend class stack<T>;
public:
    data_type getValue() const { return value; }
    sNode<T>* next;
private:
    data_type value;
};

template <class T>
class stack {
    typedef typename sNode<T>::data_type data_type;

    friend std::ostream& operator<<(std::ostream& out, const stack<T>& stk) {
        sNode<T>* temp = stk.head;
        while (temp != nullptr) {
            out << temp->getValue() << ' ';
            temp = temp->next;
        }

        out << std::endl;

        return out;
    }

public:

    stack();
    ~stack();

    void init();
    bool isEmpty() const;
    data_type read() const;
    void push(data_type);
    void pop();
    
    int size() const;

private:
    sNode<T>* head;
    int length;
};

template<class T>
stack<T>::stack() {
    head = nullptr;
    length = 0;
}

template<class T>
stack<T>::~stack() {
    while (!isEmpty()) pop();
    delete head;
}

template<class T>
bool stack<T>::isEmpty() const { return head == nullptr; }

template<class T>
void stack<T>::push(data_type d) {
    sNode<T>* temp = new sNode<T>;
    temp->value = d;
    temp->next = head;
    head = temp;
    length++;
}

template<class T>
void stack<T>::pop() {
    sNode<T>* temp = head;
    head = head->next;
    length--;
    delete temp;
}

template<class T>
typename stack<T>::data_type stack<T>::read() const { 
    assert(!isEmpty());
    return head->value; 
}

template<class T>
int stack<T>::size() const { return length; }

#endif // STACK_H