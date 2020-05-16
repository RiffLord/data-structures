#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <assert.h>

template <class T>
class queue;

template <class T>
class qNode {
    typedef T data_type;
    friend class queue<T>;
public:
    qNode() { next = nullptr; }
    data_type getValue() const { return value; }
    qNode<T>* next;
private:
    data_type value;
};

template <class T>
class queue {
    typedef typename qNode<T>::data_type data_type;

    friend std::ostream& operator<<(std::ostream& out, const queue<T>& q) {
        qNode<T>* temp = q.head;
        while (temp != nullptr) {
            out << temp->getValue() << ' ';
            temp = temp->next;
        }
        out << std::endl;
        return out;
    }

public:
    queue();
    ~queue();

    //  Operators
    void init();
    bool isEmpty() const;
    data_type read() const;
    void enqueue(data_type);
    void dequeue();

    int size() const;
private:
    qNode<T>* head;
    qNode<T>* tail;
    int length;
};

template <class T>
queue<T>::queue() {
    head = nullptr;
    tail = nullptr;
    length = 0;
}

template <class T>
queue<T>::~queue() {
    while (!isEmpty()) dequeue();
    delete tail;
    delete head;
}

template <class T>
bool queue<T>::isEmpty() const { return head == nullptr; }

template <class T>
void queue<T>::enqueue(data_type d) {
    qNode<T>* temp = new qNode<T>;
    temp->value = d;
    temp->next = nullptr;
    if (isEmpty()) {
        head = temp;
        tail = head;
    } else {
        tail->next = temp;
        tail = temp;
    }
    length++;
}

template <class T>
void queue<T>::dequeue() {
    assert(!isEmpty());
    qNode<T>* temp = head;
    head = head->next;
    length--;
    delete temp;
}

template <class T>
typename queue<T>::data_type queue<T>::read() const { 
    assert(!isEmpty());
    return head->value; 
}

template <class T>
int queue<T>::size() const { return length; }

#endif // QUEUE_H