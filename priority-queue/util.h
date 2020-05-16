#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include "prioriqueue.h"

using namespace std;

template<class T>
void acquire(prioriQueue<T>& q) {
    q.insert('c', 3);
    q.insert('e', 5);
    q.insert('i', 9);
    q.insert('f', 6);
    q.insert('h', 8);
    q.insert('o', 13);
    q.insert('n', 12);
    q.insert('m', 11);
    q.insert('t', 18);
    q.insert('l', 10);
}

template<class T>
void print(prioriQueue<T>& q) {
    if (!q.isEmpty()) {
        for (int i = 1; i <= q.length(); i++)
            cout << q.readNode(i) << ' ';

        cout << endl;
    } else cout << "The priority queue is empty." << endl;
}

template<class T>
void printPriority(prioriQueue<T>& q) {
    if (!q.isEmpty()) {
        for (int i = 1; i <= q.length(); i++)
            cout << q.readPriority(i) << ' ';

        cout << endl;
    } else cout << "The priority queue is empty." << endl;    
}

template<class T>
int search(prioriQueue<T> &q, T item) {
    int found = true, i = 1;
    while (i <= q.length() && found) {
        if (q.readNode(i) == item) return i;
        i++;
    }
    return -1;
}

#endif // UTIL_H