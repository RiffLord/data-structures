/**
 * @file      queue.h
 * @author    Bruno Pezer (bruno.pezer@tutanota.com)
 * @brief     Generic priority queue data structure definition file
 * @version   0.3
 * @date      2022-10-16
 *
 * @copyright NO COPYRIGHT !(c) 2022
 *
 */
#ifndef QUEUE_H
#define QUEUE_H
#include "assert.h"

/**
 * @brief    Generic priority queue data structure.
 *
 * @tparam T Queue type
 */
template <class T> class Queue {
public:
    Queue();
    Queue(int);
    ~Queue();
    void insert(T);
    T min() const;
    void removeMin();
private:
    T *heap;
    int maxlength;
    int last;

    void fixUp();
    void fixDown(int, int);
};

/**
 * @brief    Class constructor. Creates a new queue with a maximum length of 100.
 *
 * @tparam T Queue type
 */
template <class T>
Queue<T>::Queue() : maxlength(100) {
    heap = new T[maxlength];
    last = 0;
}

/**
 * @brief    Overloaded class constructor. Creates a new queue with a maximum length of n.
 *
 * @tparam T Queue type
 * @param n  Maximum queue length
 */
template <class T>
Queue<T>::Queue(int n) : maxlength(n) {
    heap = new T[maxlength];
    last = 0;
}

/**
 * @brief    Class destructor. Frees memory by deleting the array in which the items are stored.
 *
 * @tparam T Queue type
 */
template <class T>
Queue<T>::~Queue() { delete[] heap; }

/**
 * @brief    Adds an item to the queue.
 *
 * @tparam T Queue type
 * @param t  Item to add.
 */
template <class T>
void Queue<T>::insert(T t) {
    assert(last < maxlength);
    heap[++last - 1] = t;
    fixUp();
}

/**
 * @brief
 *
 * @tparam T Queue type
 * @return   The item stored at the beginning of the heap.
 */
template <class T>
T Queue<T>::min() const {
    assert(last != 0);
    return heap[0];
}

/**
 * @brief
 *
 * @tparam T Queue type
 */
template <class T>
void Queue<T>::removeMin() {
    assert(last != 0);
    heap[0] = heap[last - 1];
    last--;
    fixDown(1, last);
}

/**
 * @brief
 *
 * @tparam T Queue type
 */
template <class T>
void Queue<T>::fixUp() {
    int k = last;
    while (k > 1 && heap[k - 1] < heap[(k / 2) - 1]) {
        T tmp;
        tmp = heap[k - 1];
        heap[k - 1] = heap[(k / 2) - 1];
        heap[(k / 2) - 1] = tmp;
        k = k / 2;
    }
}

/**
 * @brief
 *
 * @tparam T Queue type
 * @param k
 * @param N
 */
template <class T>
void Queue<T>::fixDown(int k, int N) {
    short int swap = 1;
    while (k <= N / 2 && swap) {
        int j = 2 * k;
        T tmp;
        if (j < N && heap[j - 1] > heap[j]) j++;
        if (swap = (heap[j - 1] < heap[k - 1])) {
            tmp = heap[k - 1];
            heap[k - 1] = heap[j - 1];
            heap[j - 1] = tmp;
            k = j;
        }
    }
}

#endif // !QUEUE_H
