#include <iostream>
#include "prioriqueue.h"
#include "util.h"

using namespace std;

int main() {
    prioriQueue<char> chars;
    acquire(chars);
    cout << "Priority queue contains:\n";
    print(chars);
    cout << "Priority of the values stored:\n";
    printPriority(chars);
    cout << "Removing minimum value: ";
    chars.dequeue();
    print(chars);
    cout << search(chars, 'o') << endl;
}