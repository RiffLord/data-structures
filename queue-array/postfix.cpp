//  Evaluating postfix (RPN) expressions using stacks & queues.
//  The queue is used to store the symbols of the expression,
//  while the stack stores the numbers and the results.

#include <iostream>
#include <cstring>
#include "queue.h"
#include "stack.h"

using namespace std;

double evaluateRPN(queue<char>&);
bool isNumber(char);

int main(int argc, char* argv[]) {
    char* expression = argv[1];
    queue<char> expSymbols;

    for (int i = 0; i < strlen(expression); i++)
        expSymbols.enqueue(expression[i]);

    printQueue(expSymbols);
    cout << evaluateRPN(expSymbols);
}

double evaluateRPN(queue<char>& postfix) {
    stack<double> rpnResult;
    while (!postfix.isEmpty()) {
        char symbol = postfix.read();
        if (isNumber(symbol)) {
            //  Cast the symbol to a double and push it into the stack.
            double d = (double) (symbol - '0');
            rpnResult.push(d);
        } else {
            int operand1 = rpnResult.read();
            rpnResult.pop();
            int operand2 = rpnResult.read();
            rpnResult.pop();

            //  Handle arithmetic
            if (symbol == '+') rpnResult.push(operand2 + operand1);
            if (symbol == '-') rpnResult.push(operand2 - operand1);
            if (symbol == '*') rpnResult.push(operand2 * operand1);
            if (symbol == '/') rpnResult.push(operand2 / operand1);
        }
        postfix.dequeue();
    }
    return rpnResult.read();
}

bool isNumber(char symbol) {
    if (symbol >= '0' && symbol <= '9') return true;
    return false;
}