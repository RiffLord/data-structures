#include <iostream>
#include "queue.h"

using namespace std;

int main() {
    cout << "Hellooo?\n";
    queue<char> qChar;
    //cout << qChar.read() << endl; //  Causes assertion failed error.
    cout << qChar.size() << endl;
    cout << "Is queue empty? " << (qChar.isEmpty() ? "true" : "false") << endl;
    qChar.enqueue('%');
    qChar.enqueue('#');
    qChar.enqueue('g');
    cout << "Reading head: " << qChar.read() << endl;
    cout << "Printing queue: " << qChar;
    cout << qChar.size() << endl;
    qChar.dequeue();
    cout << "After dequeueing item from head.\n";
    cout << qChar.size() << endl;
    cout << qChar.read() << endl;
    cout << "Printing queue: " << qChar;
    cout << "Is queue empty? " << (qChar.isEmpty() ? "true" : "false") << endl;
}