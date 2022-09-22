/**
 * @file    queue.h
 * @author  Bruno Pezer (bruno.pezer@tutanota.com)
 * @brief   Pointer-based queue data structure class definition
 * @version 0.1
 * @date    2022-08-17
 * 
 * @copyright NO COPYRIGHT !(c) 2022
 * 
 */
#ifndef QUEUE_H
#define QUEUE_H
#include "node.h"

class Queue {
    friend std::ostream &operator<<(std::ostream &, const Queue &);
    friend std::istream &operator>>(std::istream &, const Queue &);
public:
    Queue();
    Queue(const Queue &);
    ~Queue();

    bool isEmpty() const;
    int read() const;
    void pop();
    void push(int);

    unsigned int getSize() const;

    Queue &operator=(const Queue &) const;
    bool operator==(const Queue &) const;
    bool operator!=(const Queue &) const;
private:
    Node *head;
    unsigned int size;
};

#endif // !QUEUE_H
