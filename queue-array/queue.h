#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <assert.h>

template<class T>
class queue {
    typedef T data_type;

    friend void printQueue(queue& q) {
        using namespace std;
        for (int i = 0; i < q.tail; i++)
            cout << q.contents[i] << ' ';

        cout << endl;
    }

public:
    queue();
    queue(int);
    ~queue();

    void init();
    bool isEmpty() const;
    data_type read() const;
    void enqueue(data_type);
    void dequeue();
    int size() const;
private:
    data_type* contents;
    int head;
    int tail;
    int capacity;
};

template<class T>
queue<T>::queue() {
    capacity = 100;
    contents = new data_type[capacity];
    init();
}

template<class T>
queue<T>::queue(int n) {
    capacity = n;
    contents = new data_type[capacity];
    init();
}

template<class T>
queue<T>::~queue() { delete[] contents; }

template<class T>
void queue<T>::init() { head = tail = 0; }

template<class T>
bool queue<T>::isEmpty() const { return head == tail; }

template<class T>
typename queue<T>::data_type queue<T>::read() const { return contents[head]; }

template<class T>
void queue<T>::enqueue(data_type d) {
    assert(tail != capacity);
    contents[tail] = d;
    tail++;
}

template<class T>
void queue<T>::dequeue() {
    if (!isEmpty()) {
        for (int i = head; i < tail; i++)
            contents[i] = contents[i + 1];

        tail--;
    }
}

template<class T>
int queue<T>::size() const { return tail; }

#endif // QUEUE_H