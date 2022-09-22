/**
 * @file    stack.h
 * @author  Bruno Pezer (bruno.pezer@tutanota.com)
 * @brief   Class definition for a pointer-based implementation of a stack data structure
 * @version 0.1
 * @date    2022-08-22
 * 
 * @copyright NO COPYRIGHT !(c) 2022
 */
#ifndef STACK_H
#define STACK_H
#include "node.h"

class Stack {
    friend std::ostream &operator<<(std::ostream &, const Stack &);
    friend std::istream &operator>>(std::istream &, const Stack &);
public:
    Stack();
    Stack(const Stack &);
    ~Stack();

    bool isEmpty() const;
    int read() const;
    void pop();
    void push(int);

    unsigned int getSize() const;
    
    Stack &operator=(const Stack &) const;
    bool operator==(const Stack &) const;
    bool operator!=(const Stack &) const;
private:
    Node *head;
    unsigned int size;
};

#endif // !STACK_H
