#ifndef PRIORIQUEUE_H
#define PRIORIQUEUE_H

#include <iostream>
#include "node.h"

template<class T>
class prioriQueue {
public:
    prioriQueue();
    prioriQueue(int);
    ~prioriQueue();
    T readMin() const;
    void insert(T, int);
    void dequeue();
    int length() const;
    bool isEmpty() const;
    T readNode(int) const;
    int readPriority(int) const;

private:
    int capacity;
    int size;
    node<T>* heap;
};

template<class T>
prioriQueue<T>::prioriQueue() {
    capacity = 100;
    heap = new node<T>[capacity];
    size = 0;
}

template<class T>
prioriQueue<T>::prioriQueue(int cap) {
    capacity = cap;
    heap = new node<T>[capacity];
    size = 0;
}

template<class T>
prioriQueue<T>::~prioriQueue() { delete[] heap; }

template<class T>
T prioriQueue<T>::readMin() const {
    if (isEmpty()) return 0;
    return heap[1]->getItem();
}

template<class T>
void prioriQueue<T>::insert(T item, int priority) {
    int i, k;
    node<T> temp;
    if (size == capacity) std::cout << "Queue at full capacity." << std::endl;
    else {
        size++;
        heap[size].setItem(item);
        heap[size].setPriority(priority);
        i = size;
        if (i > 1) k = i / 2;
        while ((i > 1) && (heap[i].getPriority() < heap[k].getPriority())) {
            temp = heap[i];
            heap[i] = heap[k];
            heap[k] = temp;
            i = k;
            if (i > 1) k = i / 2;
        }
        i++;
    }
}

template<class T>
void prioriQueue<T>::dequeue() {
    int i, k;
    node<T> temp;
    bool swap;
    if (isEmpty()) std::cout << "Queue empty." << std::endl;
    else {
        heap[1] = heap[size];
        size--;
        i = 1;
        swap = true;
        while ((i <= size / 2) && swap) {
            k = 2 * i;
            if (k < size)
                if (heap[k].getPriority() > heap[k + 1].getPriority())
                k++;
            
            if (heap[k].getPriority() < heap[i].getPriority()) {
                temp = heap[i];
                heap[i] = heap[k];
                heap[k] = temp;
                i = k;
            } else swap = false;
        }
    }
}

template<class T>
int prioriQueue<T>::length() const { return size; }

template<class T>
bool prioriQueue<T>::isEmpty() const { return size == 0; }

template<class T>
T prioriQueue<T>::readNode(int i) const {
    if (!isEmpty() && i <= length()) return heap[i].getItem();
    return 0;
}

template<class T>
int prioriQueue<T>::readPriority(int i) const {
    if (!isEmpty() && i <= length()) return heap[i].getPriority();
    return 0;
}


#endif // PRIORIQUEUE_H