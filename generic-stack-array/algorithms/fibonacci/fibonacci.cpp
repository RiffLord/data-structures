/*
 *  Visualizing the output of a recursive Fibonacci function
 *  through the use of a stack. Output is from right to left.
 */

#include <iostream>
#include "stack.h"

int fibonacci(int, stack<int>&);

int main() {
    int n = 8;
    stack<int> fibonacciHolder;  
    fibonacci(n, fibonacciHolder);
}

//  Recursively calculates the value of the number at the
//  specified position (k). Uses a stack to store and visualize
//  the output of the steps.
int fibonacci(int k, stack<int>& s) {
    int f;
    if (k == 1 || k == 2) {
        f = 1;
    } else {
        f = fibonacci(k - 1, s) + fibonacci(k - 2, s);
        s.pop();
        s.pop();
    }
    s.push(f);
    printStack(s);
    return f;
}